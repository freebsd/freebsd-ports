--- command/markad-standalone.cpp.orig	2012-09-11 11:06:28 UTC
+++ command/markad-standalone.cpp
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
@@ -1428,6 +1434,7 @@ bool cMarkAdStandalone::SaveInfo()
 time_t cMarkAdStandalone::GetBroadcastStart(time_t start, int fd)
 {
     // get broadcast start from atime of directory (if the volume is mounted with noatime)
+#ifndef __FreeBSD__
     struct mntent *ent;
     struct stat statbuf;
     FILE *mounts=setmntent(_PATH_MOUNTED,"r");
@@ -1454,6 +1461,14 @@ time_t cMarkAdStandalone::GetBroadcastSt
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
@@ -1554,6 +1569,16 @@ bool cMarkAdStandalone::LoadInfo()
                 if (lf) *lf=0;
                 char *cr=strchr(macontext.Info.ChannelName,13);
                 if (cr) *cr=0;
+#if 1
+                int len = strlen(macontext.Info.ChannelName);
+                if (len > 5 &&
+	            (!strcmp(macontext.Info.ChannelName + len - 4, " (A)") ||
+	             !strcmp(macontext.Info.ChannelName + len - 4, " (C)") ||
+	             !strcmp(macontext.Info.ChannelName + len - 4, " (S)") ||
+	             !strcmp(macontext.Info.ChannelName + len - 4, " (T)") ||
+	             !strcmp(macontext.Info.ChannelName + len - 4, " (I)")))
+	            macontext.Info.ChannelName[len - 4] = '\0';
+#endif
                 for (int i=0; i<(int) strlen(macontext.Info.ChannelName); i++)
                 {
                     if (macontext.Info.ChannelName[i]==' ') macontext.Info.ChannelName[i]='_';
@@ -1961,10 +1986,14 @@ bool cMarkAdStandalone::CreatePidfile()
         int pid;
         if (fscanf(oldpid,"%10i\n",&pid)==1)
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
                 fprintf(stderr,"another instance is running on %s",directory);
@@ -2081,6 +2110,7 @@ cMarkAdStandalone::cMarkAdStandalone(con
         }
     }
 
+#ifndef __FreeBSD__
     long lb;
     errno=0;
     lb=sysconf(_SC_LONG_BIT);
@@ -2089,6 +2119,7 @@ cMarkAdStandalone::cMarkAdStandalone(con
         isyslog("starting v%s (%libit)",VERSION,lb);
     }
     else
+#endif
     {
         isyslog("starting v%s",VERSION);
     }
@@ -2319,7 +2350,7 @@ cMarkAdStandalone::~cMarkAdStandalone()
     RemovePidfile();
 }
 
-bool isnumber(const char *s)
+bool str_isnumber(const char *s)
 {
     while (*s)
     {
@@ -2345,7 +2376,11 @@ int usage(int svdrpport)
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
@@ -2489,7 +2524,11 @@ int main(int argc, char *argv[])
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
@@ -2620,7 +2659,7 @@ int main(int argc, char *argv[])
 
         case 'p':
             // --priority
-            if (isnumber(optarg) || *optarg=='-')
+            if (str_isnumber(optarg) || *optarg=='-')
                 niceLevel = atoi(optarg);
             else
             {
@@ -2806,7 +2845,7 @@ int main(int argc, char *argv[])
             break;
 
         case 9: // --svdrpport
-            if (isnumber(optarg) && atoi(optarg) > 0 && atoi(optarg) < 65536)
+            if (str_isnumber(optarg) && atoi(optarg) > 0 && atoi(optarg) < 65536)
             {
                 config.svdrpport=atoi(optarg);
             }
