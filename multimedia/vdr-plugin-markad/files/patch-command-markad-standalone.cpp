--- a/command/markad-standalone.cpp
+++ b/command/markad-standalone.cpp
@@ -24,7 +24,13 @@
 #include <locale.h>
 #include <libintl.h>
 #include <execinfo.h>
+#ifndef __FreeBSD__
 #include <mntent.h>
+#else
+#include <netinet/in.h>
+#include <sys/socket.h>
+#include <sys/mount.h>
+#endif
 #include <utime.h>
 #include <math.h>
 #include <limits.h>
@@ -1389,6 +1395,7 @@ bool cMarkAdStandalone::SaveInfo()
 time_t cMarkAdStandalone::GetBroadcastStart(time_t start, int fd)
 {
     // get broadcast start from atime of directory (if the volume is mounted with noatime)
+#ifndef __FreeBSD__
     struct mntent *ent;
     struct stat statbuf;
     FILE *mounts=setmntent(_PATH_MOUNTED,"r");
@@ -1415,6 +1422,14 @@ time_t cMarkAdStandalone::GetBroadcastSt
         }
     }
     endmntent(mounts);
+#else
+    struct stat statbuf;
+    struct statfs statfsbuf;
+    bool useatime=false;
+    if ((statfs(directory, &statfsbuf) == 0) &&
+        !(statfsbuf.f_flags & MNT_NOATIME))
+        useatime=true;
+#endif
 
     if ((useatime) && (stat(directory,&statbuf)!=-1))
     {
@@ -1900,10 +1915,14 @@ bool cMarkAdStandalone::CreatePidfile()
         int pid;
         if (fscanf(oldpid,"%i\n",&pid)==1)
         {
+#ifndef __FreeBSD__
             char procname[256]="";
             snprintf(procname,sizeof(procname),"/proc/%i",pid);
             struct stat statbuf;
             if (stat(procname,&statbuf)!=-1)
+#else
+            if (kill(pid, 0) == 0)
+#endif
             {
                 // found another, running markad
                 isyslog("another instance is running on this recording");
@@ -2212,7 +2231,7 @@ cMarkAdStandalone::~cMarkAdStandalone()
     RemovePidfile();
 }
 
-bool isnumber(const char *s)
+bool str_isnumber(const char *s)
 {
     while (*s)
     {
@@ -2238,7 +2257,11 @@ int usage(int svdrpport)
            "                  ignores hints from info(.vdr) file\n"
            "                  <info> 4 = ignore timer info\n"
            "-l              --logocachedir\n"
+#ifdef DATADIR
+           "                  directory where logos stored, default " DATADIR "/logos\n"
+#else
            "                  directory where logos stored, default /var/lib/markad\n"
+#endif
            "-p              --priority=<priority>\n"
            "                  software priority of markad when running in background\n"
            "                  <priority> from -20...19, default 19\n"
@@ -2382,7 +2405,11 @@ int main(int argc, char *argv[])
     config.logoHeight=-1;
     config.threads=-1;
     strcpy(config.svdrphost,"127.0.0.1");
+#ifdef DATADIR
+    strcpy(config.logoDirectory,DATADIR "/logos");
+#else
     strcpy(config.logoDirectory,"/var/lib/markad");
+#endif
 
     struct servent *serv=getservbyname("svdrp","tcp");
     if (serv)
@@ -2513,7 +2540,7 @@ int main(int argc, char *argv[])
 
         case 'p':
             // --priority
-            if (isnumber(optarg) || *optarg=='-')
+            if (str_isnumber(optarg) || *optarg=='-')
                 niceLevel = atoi(optarg);
             else
             {
@@ -2699,7 +2726,7 @@ int main(int argc, char *argv[])
             break;
 
         case 9: // --svdrpport
-            if (isnumber(optarg) && atoi(optarg) > 0 && atoi(optarg) < 65536)
+            if (str_isnumber(optarg) && atoi(optarg) > 0 && atoi(optarg) < 65536)
             {
                 config.svdrpport=atoi(optarg);
             }
