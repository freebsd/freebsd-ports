/* ====================================================================
 *
 * Apache FrontPage module.
 *
 * Copyright (c) 1996-2001 Microsoft Corporation -- All Rights Reserved.
 *
 * NO WARRANTIES. Microsoft expressly disclaims any warranty for this code and
 * information. This code and information and any related documentation is
 * provided "as is" without warranty of any kind, either express or implied,
 * including, without limitation, the implied warranties or merchantability,
 * fitness for a particular purpose, or noninfringement. The entire risk
 * arising out of use or performance of this code and information remains with
 * you.
 *
 * NO LIABILITY FOR DAMAGES. In no event shall Microsoft or its suppliers be
 * liable for any damages whatsoever (including, without limitation, damages
 * for loss of business profits, business interruption, loss of business
 * information, or any other pecuniary loss) arising out of the use of or
 * inability to use this Microsoft product, even if Microsoft has been advised
 * of the possibility of such damages. Because some states/jurisdictions do not
 * allow the exclusion or limitation of liability for consequential or
 * incidental damages, the above limitation may not apply to you.
 */


/*
 * User configurable items.  We will not run the server extensions with any
 * UID/GID less than LOWEST_VALID_UID/LOWEST_VALID_GID.
 */

#if defined(LINUX)
#define LOWEST_VALID_UID 15
#else
#define LOWEST_VALID_UID 11
#endif

#if defined(HPUX) || defined(IRIX) || defined(SUNOS4)
#define LOWEST_VALID_GID 20
#else
#if defined(SCO)
#define LOWEST_VALID_GID 24
#else
#define LOWEST_VALID_GID 21   /* Solaris, AIX, Alpha, Bsdi, *BSD, etc. */
#endif
#endif

/*
 * End of user configurable items
 */


#include "httpd.h"
#include "http_config.h"
#include "http_conf_globals.h"
#include "http_log.h"

#include <stdio.h>
#include <sys/time.h>

#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif

#ifndef MAXPATHLEN
#define MAXPATHLEN 1024
#endif
#if (MAXPATHLEN < 1024)
#undef MAXPATHLEN
#define MAXPATHLEN 1024
#endif

#define KEYLEN 128                  /* Should be a multiple of sizeof(int) */

static char gszKeyVal[KEYLEN+1];    /* SUID key value used by this module */
static int  gfdKeyPipe[2];          /* Pipe to fpexe stub CGI */
static int  gbKeyPipeActive = FALSE;/* Pipe to fpexe stub CGI is active */
static int  gbEnabled = FALSE;      /* TRUE when SUID scheme is enabled */
#if !defined(SHARED_MODULE)
static int  giInitializeCount = 0;  /* FrontPageInit called previously */
#endif

static const char FP[]         =
          "/usr/local/frontpage/version5.0";
static const char FPKEYDIR[]   =
          "/usr/local/frontpage/version5.0/apache-fp";
static const char KEYFILEXOR[] =
          "/usr/local/frontpage/version5.0/apache-fp/suidkey";
static const char KEYFILE[]    =
          "/usr/local/frontpage/version5.0/apache-fp/suidkey.%d";
static const char FPSTUBDIR[]  =
          "/usr/local/frontpage/version5.0/apache-fp/_vti_bin";
static const char FPSTUB[]     =
          "/usr/local/frontpage/version5.0/apache-fp/_vti_bin/fpexe";
static const char GLOBALADMINDIR[] =
          "/usr/local/frontpage/version5.0/admin-exes";
static const char IMAGESDIR[]  =
          "/exes/_vti_bin/_vti_adm/images" ;
static const char SHTML[]      =
          "/_vti_bin/shtml.exe";
static const char SHTML2[]     =
          "/_vti_bin/shtml.dll";
static const char VTI_BIN[]    =
          "/_vti_bin";
static const char FPCOUNT[]    =
          "/_vti_bin/fpcount.exe";
static const char AUTHOR[]     =
          "/_vti_bin/_vti_aut/author.exe" ;
static const char ADMIN[]      =
          "/_vti_bin/_vti_adm/admin.exe" ;
static const char ADMINCGI[]   =
          "/_vti_bin/_vti_adm/fpadmcgi.exe" ;
static const char PASSWD[]     =
          "/passwd.htm" ;
static const char VTIHELP[]    =
          "/_vti_bin/_vti_adm/help/" ;
static const char VTI_ADM[]    =
          "/_vti_bin/_vti_adm/" ;
static const char HELPDIR[]    =
          "/help" ;
static const char ADMINDIR[]   =
          "/admin" ;

const int iVTI_LEN = sizeof(VTI_ADM)/sizeof(VTI_ADM[0]) - 1;
const int iHELP    = sizeof(VTIHELP)/sizeof(VTIHELP[0]) - 1;


MODULE_VAR_EXPORT module frontpage_module;

/*
 * Print a descriptive error in the httpd's error_log.  The format string
 * should be length limited so that it is no longer than 1800 bytes.
 */
static void LogFrontPageError(
    server_rec* s,
    const char* szFormat,
    const char* szFile,
    const char* szRoutine,
    int bIsDisabled)
{
    char szBuf[MAXPATHLEN * 2];
    sprintf(szBuf, szFormat, szFile);
    strcat(szBuf, " in ");
    strcat(szBuf, szRoutine);
    strcat(szBuf, ".");
    if (bIsDisabled)
    {
        strcat(szBuf, "  Until this problem is fixed, the FrontPage security patch is disabled and the FrontPage extensions may not work correctly.");
        gbEnabled = FALSE;            /* Make double sure we're not enabled */
    }
    ap_log_error(APLOG_MARK, APLOG_ERR, s, szBuf);
}


/*
 * Clean up stale keyfiles.  Failure to clean up stale keyfiles does not
 * stop the FrontPage SUID scheme.
 */
static void FrontPageCleanup(server_rec *s)
{
    DIR *d;
    struct DIR_TYPE *dstruct;
    int myPid = getpid();
    
    if (!(d = opendir(FPKEYDIR)))
    {
        /*
         * This should be a rare occurrence, because we're running as root and
         * should have access to the directory.  Stale key files can be
         * exploited.  User recovery: Check that the directory exists and is
         * properly protected (owned by root, permissions rwx--x--x), and that
         * there are no stale key files in it (suidkey.*, where * is a
         * non-existant PID).
         */
        LogFrontPageError(s, "Can't clean stale key files from directory \"%-.1024s\"",
                          FPKEYDIR, "FrontPageCleanup()", FALSE);
        return;
    }

    while ((dstruct = readdir(d)))
    {
        if (strncmp("suidkey.", dstruct->d_name, 8) == 0)
        {
            /*
             * Make sure the key file contains a pid number - otherwise
             * it is harmless and you can ignore it.
             */
            char* pEnd = 0;
            int pid = strtol(dstruct->d_name + 8, &pEnd, 10);
            if (!pEnd || *pEnd)
                continue;

            /*
             * Make sure there isn't some other server using this key file.
             * If the process group isn't alive, then the file is stale
             * and we want to remove it.
             */
            if (pid == myPid || kill(pid, 0) == -1)
            {
                char szBuf[MAXPATHLEN];
                sprintf(szBuf, "%-.500s/%-.500s", FPKEYDIR, dstruct->d_name);
                if (unlink(szBuf) == -1)
                {
                    /*
                     * This should be a rare occurrence, because we're running
                     * as root and should always have permission to delete the
                     * file.  Stale key files can be exploited.  User recovery:
                     * delete the offending file.
                     */
                    LogFrontPageError(s, "Can't unlink stale key file \"%-.1024s\"",
                                      szBuf, "FrontPageCleanup()", FALSE);
                }
            }
        }
    }

    closedir(d);
}

/*
 * Checks that all the permissions are currently correct for the FrontPage
 * fpexe SUID stub to run correctly.  If not, it logs an error and aborts
 * initialization, effectively disabling the FrontPage SUID scheme.
 * It checks both the file permissions (owned by root and not writable to
 * group, other) and that the directory is not writable.
 */
static int FrontPageCheckup(server_rec *s)
{
    struct stat fs;
 
    if (geteuid() != 0)
    {
        /*
         * We need to be root to have the security scheme work correctly.
         * User recovery: run the server as root.
         */
        LogFrontPageError(s, "Not running as root",
                          0, "FrontPageCheckup()", TRUE);
        return (FALSE);
    }

    if (lstat(FPKEYDIR, &fs) == -1          || /* We can't stat the key dir */
        fs.st_uid                           || /* key dir not owned by root */
        (fs.st_mode & (S_IRGRP | S_IROTH))  || /* key dir is readable */
        (fs.st_mode & (S_IWGRP | S_IWOTH))  || /* key dir is writable */
        !(fs.st_mode & (S_IXGRP | S_IXOTH)) || /* key dir is not executable */
        !(S_ISDIR(fs.st_mode)))
    {
        /*
         * User recovery: set directory to be owned by by root with permissions
         * rwx--x--x.  Note you need the execute bit for group and other so
         * that non-root programs can run apache-fp/_vti_bin/fpexe (even though
         * non-root cannot list the directory).
         */
        LogFrontPageError(s, "Incorrect permissions on key directory \"%-.1024s\", needs root ownership and permissions rwx--x--x",
                          FPKEYDIR, "FrontPageCheckup()", TRUE);
        return (FALSE);
    }

    if (lstat(FPSTUBDIR, &fs) == -1         || /* We can't stat the stub dir */
        fs.st_uid                           || /* stub dir not owned by root */
        (fs.st_mode & (S_IWGRP | S_IWOTH))  || /* stub dir is writable */
        (!S_ISDIR(fs.st_mode)))
    {
        /*
         * User recovery: set directory to be owned by by root with permissions
         * r*x*-x*-x.
         */
        LogFrontPageError(s, "Incorrect permissions on stub directory \"%-.1024s\", needs root ownership and permissions r*x*-x*-x",
                          FPSTUBDIR, "FrontPageCheckup()", TRUE);
        return (FALSE);
    }

    if (stat(FPSTUB, &fs) == -1             || /* We can't stat the stub */
        fs.st_uid                           || /* stub not owned by root */
        !(fs.st_mode & S_ISUID)             || /* stub is not set-uid */
        (fs.st_mode & S_ISGID)              || /* stub is set-gid */
        (fs.st_mode & (S_IWGRP | S_IWOTH))  || /* stub is writable */
        !(fs.st_mode & (S_IXGRP | S_IXOTH)))   /* stub is not executable */
    {
        /*
         * User recovery: set stub to be owned by by root with permissions
         * r*s*-x*-x.
         */
        LogFrontPageError(s, "Incorrect permissions on stub \"%-.1024s\", needs root ownership and permissions r*s*-x*-x",
                          FPSTUB, "FrontPageCheckup()", TRUE);
        return (FALSE);
    }

    return (TRUE);
}


/*
 * Module-initializer: Create the suidkey file and local value.
 * Everything needs to be just right, or we don't create the key file, and
 * therefore, the fpexe SUID stub refuses to run.
 */
static void FrontPageInit(server_rec *s, pool *p)
{
    int fdPipe[2];
    pid_t pid;
    FILE *f;
    struct stat fs;
    int fd;
    char szKeyFile[MAXPATHLEN];
    int iRandom[5];
    char* szRandom = (char*)iRandom;
    struct timeval tp;
    struct timezone tz;
    
    (void)p;   /* p is unused */

#if !defined(SHARED_MODULE)
    /*
     * Standalone servers call initialization twice: once in main() and again
     * in standalone_main().  The fully initializing on the the first call is a
     * waste of time, and a race condition can leave a stale suidkey.pgrpid
     * file around.
     */
    if (ap_standalone && !giInitializeCount++)
        return;
#endif

    /*
     * Disable the suid scheme until everything falls perfectly into place.
     */
    gbEnabled = FALSE;
    gbKeyPipeActive = FALSE;

    /*
     * Clean up old key files before we start
     */
    FrontPageCleanup(s);
    if (!FrontPageCheckup(s))
        return;
    
    if (pipe(fdPipe) == -1)
    {
        /*
         * This should be a rare occurrence.  User recovery: check to see why
         * the system cannot allocate a pipe (is the file table full from
         * run-away processes?), and fix the problem or reboot, then try again.
         */
        LogFrontPageError(s, "pipe() failed", 0, "FrontPageInit()", TRUE);
        return;
    }
    
    gettimeofday(&tp, &tz);
    iRandom[0] = tp.tv_sec;
    iRandom[1] = tp.tv_usec | tp.tv_usec << 20;

    pid = fork();
    if (pid == -1)
    {
        /*
         * This should be a rare occurrence.  User recovery: check to see why
         * the system cannot allocate a process (is the process table full from
         * run-away processes?), and fix the problem or reboot, then try again.
         */
        LogFrontPageError(s, "fork() failed", 0, "FrontPageInit()", TRUE);
        return;
    }
    
    if (pid)
    {
        /*
         * I am the parent process.  Try to read a random number from the
         * child process.
         */

        unsigned int npos = (unsigned int)-1;
        unsigned int v1 = npos, v2 = npos, v3 = npos, v4 = npos;
        int stat;
        int iCount;

        close(fdPipe[1]);
        if (waitpid(pid, &stat, 0) == -1 ||
            (!WIFEXITED(stat) || WIFEXITED(stat) && WEXITSTATUS(stat)))
        {
            /*
             * This should be a rare occurrence.  User recovery: Make sure you
             * have a /bin/sh, or change the shell location in the execl
             * command below.  Try the commands defined in RAND_CMD in a
             * /bin/sh session to make sure they work properly.  Rebuild this
             * module and your httpd with the proper commands.
             */
            LogFrontPageError(s, "Random number generator exited abnormally", 0,
                              "FrontPageInit()", TRUE);
            return;
        }

        iCount = read(fdPipe[0], gszKeyVal, KEYLEN);
        close(fdPipe[0]);
        if (iCount < 0)
        {
            /*
             * This should be a rare occurrence.  See the above comment under
             * the waitpid failure condition for user recovery steps.
             */
            LogFrontPageError(s, "Could not read random numbers", 0,
                              "FrontPageInit()", TRUE);
            return;
        }
        gszKeyVal[iCount] = 0;

        sscanf(gszKeyVal, "%u %u %u %u", &v2, &v1, &v4, &v3);
        if (v1 == npos || v2 == npos || v3 == npos || v4 == npos)
        {
            /*
             * This should be a rare occurrence.  See the above comment under
             * the waitpid failure condition for user recovery steps.
             */
            LogFrontPageError(s, "Could not scan random numbers", 0,
                              "FrontPageInit()", TRUE);
            return;
        }

        iRandom[2] = (v1 << 16) + v2 + (v4 << 12) + v3;
    }
    else
    {
        /*
         * I am the child process.  Create a random number which shouldn't
         * be easily duplicated.
         */

        if (dup2(fdPipe[1], 1) == -1)
            exit(1);                    /* Parent picks up the error */

        close(fdPipe[0]);

#ifdef LINUX
#define RAND_CMD "/bin/ps laxww | /usr/bin/sum ; /bin/ps laxww | /usr/bin/sum"
#else
#if defined ( bsdi ) || ( defined ( BSD ) && ( BSD >= 199103 ))
#define RAND_CMD "/bin/ps laxww | /usr/bin/cksum -o 1 ; /bin/ps laxww | /usr/bin/cksum -o 1"
#else
#define RAND_CMD "/bin/ps -ea | /bin/sum ; /bin/ps -ea | /bin/sum"
#endif
#endif
        execl("/bin/sh", "/bin/sh", "-c", RAND_CMD, NULL);
        exit(1);
    }

    gettimeofday(&tp, &tz);
    iRandom[3] = tp.tv_sec;
    iRandom[4] = tp.tv_usec | tp.tv_usec << 20;

    /*
     * See if there is an 'suidkey' file to merge into our key.
     */
    if (stat(KEYFILEXOR, &fs) == -1)
    {
        /*
         * It's a security violation if the key file is not present.  User
         * recovery: Make sure the key file is present and properly protected
         * (owned by root, permissions r**------).
         */
        LogFrontPageError(s, "The key file \"%-.1024s\" does not exist",
                          KEYFILEXOR, "FrontPageInit()", TRUE);
        return;
    }
    else
    {
        int i, iCount;
        char szBuf[KEYLEN];

        if ((fs.st_mode & (S_IRWXG | S_IRWXO)) || fs.st_uid)
        {
            /*
             * It's a security violation if the key file is not owned by root,
             * and is not protected from all other group. User recovery: Make
             * sure the key file is properly protected (owned by root,
             * permissions r**------).
             */
            LogFrontPageError(s, "The key file \"%-.1024s\" must not be accessible except by root and with permissions r**------",
                              KEYFILEXOR, "FrontPageInit()", TRUE);
            return;
        }

        if ((fd = open(KEYFILEXOR, O_RDONLY)) == -1)
        {
            /*
             * This should be a rare occurrence.  User recovery: Make sure
             * the key file exists, is properly owned and protected, and is
             * readable.
             */
            LogFrontPageError(s, "Cannot open key file \"%-.1024s\"",
                              KEYFILEXOR, "FrontPageInit()", TRUE);
            return;
        }

        iCount = read(fd, szBuf, KEYLEN);
        if (iCount < 8)
        {
            /*
             * The keyfile must be at least 8 bytes.  If it longer than 128
             * bytes, only the first 128 bytes will be used.  Any character
             * value from 0-255 is fine.  User recovery: Make sure the key file
             * is at least 8 bytes long.
             */
            LogFrontPageError(s, "Key file \"%-.1024s\" is unreadable or is too short (must be at least 8 bytes)",
                              KEYFILEXOR, "FrontPageInit()", TRUE);
            close(fd);
            return;
        }

        /*
         * Now generate the effective key we'll be using by XORing your key
         * with 5 "random" 32-bit integers.  The primary security of this
         * scheme is your key; properly setting it and changing it often keeps
         * the FrontPage SUID scheme secure.  All this work above to generate 5
         * random 32-bit integers is soley to make your key somewhat harder to
         * crack (assuming the key files are properly protected).  If you don't
         * like the algorithm used to generate the 5 random integers, feel free
         * to substitute as appropriate (check out SGI's Lavarand (TM) at
         * lavarand.sgi.com).
         */
        for (i = 0;  i < KEYLEN;  i++)
            gszKeyVal[i] = szBuf[i % iCount] ^ szRandom[i % sizeof(iRandom)];

        /*
         * Thanks to A.Mayrhofer@Austria.EU.net 980130
         */
        close(fd);
    }

#if defined(SUNOS4)
    pid = getpgrp(0);
#else
    pid = getpgrp();
#endif
    sprintf(szKeyFile, KEYFILE, (int)pid);

    fd = creat(szKeyFile, 0600);
    if (fd < 0)
    {
        /*
         * This should be a rare occurrence, because we're running as root and
         * should always have permission to create the file.  User recovery:
         * check that you are not out of disk space, or that the file is not
         * NFS-mounted on a share where you do not have permissions.
         */
        LogFrontPageError(s, "Could not create key file \"%-.1024s\"",
                          szKeyFile, "FrontPageInit()", TRUE);
        return;
    }

    if (write(fd, gszKeyVal, 128) != 128)
    {
        /*
         * This should be a rare occurrence.  User recovery: check that you are
         * not out of disk space.
         */
        close(fd);  
        unlink(szKeyFile);
        LogFrontPageError(s, "Could not write to key file \"%-.1024s\"",
                          szKeyFile, "FrontPageInit()", TRUE);
        return;
    }

    close(fd);  

    /*
     * Everything looks OK enough to start the suid scheme.
     */
    gbEnabled = TRUE;

    /*
     * Thanks to Scot Hetzel (hetzels@westbend.net)
     */
    ap_add_version_component("FrontPage/5.0.2.2510");
}

static int FrontPageCheckWebRoot(
    request_rec* r,
    char* szCgi,
    struct stat *pWebroot)
{
    int iLen;
    struct stat vti_pvt;
    char szBuf[MAXPATHLEN];
    char chSave;
    char szFormat[MAXPATHLEN * 2];

    chSave = szCgi[1];
    szCgi[1] = '\0';
    ap_translate_name(r);
    szCgi[1] = chSave;

    /*
     * Zap trailing slash that confuses some OSes.
     */
    iLen = strlen(r->filename);
    r->filename[--iLen] = 0;

    if (iLen > MAXPATHLEN - 10)
        return DECLINED;
    sprintf(szBuf, "%s/_vti_pvt", r->filename);

    /*
     * Decline if webroot and webroot/_vti_pvt don't have the same
     * user and group or uid < LOWEST_VALID_UID or gid < LOWEST_VALID_GID.
     */
    if (stat(szBuf, &vti_pvt)       != 0 ||
        stat(r->filename, pWebroot) != 0 ||
        pWebroot->st_uid != vti_pvt.st_uid  || 
        pWebroot->st_gid != vti_pvt.st_gid)
    {
        /*
         * The webroot and webroot/_vti_pvt don't match.  User recovery: fix
         * the owners and groups of both directories to match, and have both a
         * uid and gid in the allowable range.
         */
	sprintf(szFormat, "Incorrect permissions on webroot \"%%-.0124s\" and webroot's _vti_pvt directory, the owners and groups must match and have a uid >= %d and gid >= %d", LOWEST_VALID_UID, LOWEST_VALID_GID);
	LogFrontPageError(r->server, szFormat,
                          szBuf, "FrontPageAlias()", FALSE);
        return DECLINED;
    }

    if ((!strcmp(r->filename,GLOBALADMINDIR)) ? vti_pvt.st_uid > 0
        : (vti_pvt.st_uid < LOWEST_VALID_UID ||
           vti_pvt.st_gid < LOWEST_VALID_GID))
    {
        /*
         * User recovery: fix the owners and groups of both directories to
         * match, and have both a uid and gid in the allowable range.
         */
	sprintf(szFormat, "Incorrect permissions on webroot \"%%-.0124s\" and webroot's _vti_pvt directory, the owners and groups must match and have a uid >= %d and gid >= %d", LOWEST_VALID_UID, LOWEST_VALID_GID);
	LogFrontPageError(r->server, szFormat,
                          szBuf, "FrontPageAlias()", FALSE);
        return DECLINED;
    }
    
    return OK;
}


/*
 * Look for a valid FrontPage extensions scenario and fake a scriptalias if
 * appropriate.  If there are any problems, we silently decline.
 */
static int FrontPageAlias(
    request_rec* r,
    char* szCgi,
    const char* szFpexe)
{
    struct stat webroot;
    struct stat stub;
    char szBuf[MAXPATHLEN];

    /*
     * Decline if we cannot run the stub, or it is writable.
     */
    if (stat(FPSTUB, &stub) == -1 || !(stub.st_mode & S_IXOTH) ||
        stub.st_mode & (S_IWGRP | S_IWOTH))
    {
        /*
         * The stub used to be correctly permissioned; what happened?  User
         * recovery: set stub to be owned by by root with permissions
         * r*s*-x*-x.
         */
        LogFrontPageError(r->server, "Incorrect permissions on stub \"%-.1024s\", must be owned by root with permissions r*s*-x*-x",
                          FPSTUB, "FrontPageAlias()", FALSE);
        return DECLINED;
    }

    if (OK != FrontPageCheckWebRoot(r, szCgi, &webroot))
        return DECLINED;

    /*
     * If the pipe is active, it was because we previously executed a CGI.
     * That CGI must have finished by now (otherwise we wouldn't be processing
     * this next request), so we can and should close the pipe to avoid a
     * resource leak.
     */
    if (gbKeyPipeActive)
    {
        close(gfdKeyPipe[0]);
        gbKeyPipeActive = FALSE;
    }

    /*
     * If we can't get a pipe, that's really bad.  We'll log an error, and
     * decline.  This should be a rare occurrence.  User recovery: check to see
     * why the system cannot allocate a pipe (is the file table full from
     * run-away processes?), and fix the problem or reboot, then try again.
     */
    if (pipe(gfdKeyPipe) == -1)
    {
        LogFrontPageError(r->server, "pipe() failed", 0,
                          "FrontPageAlias()", FALSE);
        return DECLINED;
    }

    /*
     * Note: ap_pstrdup allocates memory, but it checks for out of memory
     * conditions - it will not return if out of memory.
     */
    r->handler = ap_pstrdup(r->pool, "cgi-script");
    ap_table_set(r->notes, "alias-forced-type", r->handler);

    ap_table_set(r->subprocess_env, "FPEXE", ap_pstrdup(r->pool, szFpexe));
    sprintf(szBuf, "%d", webroot.st_uid );
    ap_table_set(r->subprocess_env, "FPUID", ap_pstrdup(r->pool, szBuf));
    sprintf(szBuf, "%d", webroot.st_gid );
    ap_table_set(r->subprocess_env, "FPGID", ap_pstrdup(r->pool, szBuf));
    sprintf(szBuf, "%d", gfdKeyPipe[0]);
    ap_table_set(r->subprocess_env, "FPFD", ap_pstrdup(r->pool, szBuf));

    r->execfilename = ap_pstrcat(r->pool, FPSTUB, szCgi+strlen(szFpexe), NULL);
    r->filename = ap_pstrcat(r->pool, r->filename, szCgi, NULL);

    if (write(gfdKeyPipe[1], gszKeyVal, 128) != 128)
    {
        /*
         * If we can't write to the pipe, that's really bad.  We'll log an
         * error, and decline.  This should be a rare occurrence.  User
         * recovery: check to see why the system cannot write to the pipe (is
         * the system being choked with too much load?), and fix the problem or
         * reboot, then try again.
         */
        LogFrontPageError(r->server, "Write to pipe failed", 0,
                          "FrontPageAlias()", FALSE);
        close (gfdKeyPipe[0]);
        close (gfdKeyPipe[1]);
        return DECLINED;
    }
    close(gfdKeyPipe[1]);

    gbKeyPipeActive = TRUE;
    return OK;
}

static int FrontPageGetLcid(const char* szDir)
{
    int iLcid;
    iLcid = atoi(szDir);
    if (iLcid < 1 || iLcid > 9999)
        iLcid = 1033;
    return iLcid;
}

/*
 * Look for a valid FrontPage extensions scenario and fake an alias if
 * appropriate.  If there are any problems, we silently decline.
 */
static int FrontPageStaticAlias(
    request_rec* r,
    char* szCgi,
    const char* szDir,
    int iLcid)
{
    struct stat webroot;
    char szBuf[8];
    char* szBase;

    if (OK != FrontPageCheckWebRoot(r, szCgi, &webroot))
        return DECLINED;

    szBase = strrchr(r->uri, '/');
    if (!szBase)
        return DECLINED;

    szBuf[0] = 0;
    if (iLcid > 0 && iLcid < 10000)
        sprintf(szBuf, "/%04d", iLcid);

    r->execfilename = ap_pstrcat(r->pool, FP, szDir, szBuf, szBase, NULL);
    r->filename = ap_pstrcat(r->pool, r->filename, szCgi, NULL);

    return OK;
}


/*
 * This routine looks for shtml.exe, fpcount.exe, author.exe and admin.exe
 * in a URI, and if found we call FrontPageAlias() to check for a valid
 * FrontPage scenario.
 *
 * The return value is OK or DECLINED.
 */
static int FrontPageXlate(
    request_rec *r)
{
    char *szVti;
    char *szCgi;

    /*
     * Decline if we're improperly initialized.
     */
    if (!gbEnabled)
        return DECLINED;

    /*
     * Check once for anything with _vti_bin.  This is much faster than
     * checking all our paths, because anything without this is definitely
     * not a FrontPage scenario.
     */
    if (!(szVti = strstr(r->uri, VTI_BIN)))
        return DECLINED;

    /* 
     * Test for FrontPage server extenders:
     * .../_vti_bin/shtml.exe...
     * .../_vti_bin/shtml.dll...
     * .../_vti_bin/fpcount.exe...
     * .../_vti_bin/_vti_aut/author.exe...
     * .../_vti_bin/_vti_adm/admin.exe...
     * .../_vti_bin/_vti_adm/owsadm.exe...
     */
    if (szCgi = strstr(szVti, AUTHOR ))
        return FrontPageAlias(r, szCgi, AUTHOR);
    /*
     * Convert inadvertent shtml.dll to shtml.exe
     * Thanks for the idea to Scot Hetzel (hetzels@westbend.net)
     */
    if (szCgi = strstr(szVti, SHTML2 ))
    {
        int iShtmlExtPos = strlen(SHTML2) - 3;
        strncpy(szCgi + iShtmlExtPos, SHTML + iShtmlExtPos, 3);
    }
    if (szCgi = strstr(szVti, SHTML  ))
        return FrontPageAlias(r, szCgi, SHTML);
    if (szCgi = strstr(szVti, ADMIN  ))
        return FrontPageAlias(r, szCgi, ADMIN);
    if (szCgi = strstr(szVti, ADMINCGI  ))
        return FrontPageAlias(r, szCgi, ADMINCGI);
    if (szCgi = strstr(szVti, FPCOUNT))
        return FrontPageAlias(r, szCgi, FPCOUNT);

    if (szCgi = strstr(szVti, VTIHELP))
        return FrontPageStaticAlias(r, szVti, HELPDIR,
                                    FrontPageGetLcid(szVti + iHELP));
    if ((szCgi = strrchr(szVti,'/')) && !strcmp(szCgi, PASSWD) &&
        (iVTI_LEN < strlen(szVti)))
        return FrontPageStaticAlias(r, szVti, ADMINDIR,
                                    FrontPageGetLcid(szVti + iVTI_LEN));
    if ((szCgi = strrchr(szVti,'.')) && !strcmp(szCgi, ".gif"))
        return FrontPageStaticAlias(r, szVti, IMAGESDIR, 0);
    if ((szCgi = strrchr(szVti,'.')) && !strcmp(szCgi, ".css") &&
        (iVTI_LEN < strlen(szVti)))
        return FrontPageStaticAlias(r, szVti, ADMINDIR,
                                    FrontPageGetLcid(szVti + iVTI_LEN));
    
    return DECLINED;    
}


/*
 * Declare ourselves so the configuration routines can find us.
 */
module MODULE_VAR_EXPORT frontpage_module = 
{
    STANDARD_MODULE_STUFF,
    FrontPageInit,             /* initializer */
    NULL,                      /* per-directory config creater */
    NULL,                      /* dir config merger - default is to override */
    NULL,                      /* server config creator */
    NULL,                      /* server config merger */
    NULL,                      /* command table */
    NULL,                      /* [6] list of handlers */
    FrontPageXlate,            /* [1] URI-to-filename translation */
    NULL,                      /* [4] check/validate HTTP user_id */
    NULL,                      /* [5] check HTTP user_id is valid *here* */
    NULL,                      /* [3] check access by host address, etc. */
    NULL,                      /* [6] MIME type checker/setter */
    NULL,                      /* [7] fixups */
    NULL,                      /* [9] logger */
    NULL,                      /* [2] header parser */
    NULL,                      /* child_init */
    NULL,                      /* child_exit */
    NULL                       /* post read-request */
};
