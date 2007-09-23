--- crypt/getsysnoise.C.orig	2002-02-08 09:27:51.000000000 -0500
+++ crypt/getsysnoise.C	2007-09-15 17:30:39.000000000 -0400
@@ -27,61 +27,61 @@
 #include <sys/resource.h>
 
 char *const noiseprogs[][5] = {
-  { PATH_PS, "laxwww" },
-  { PATH_PS, "-al" },
-  { PATH_LS, "-nfail", "/tmp/." },
+  { const_cast<char *> (PATH_PS), const_cast<char *> ("laxwww") },
+  { const_cast<char *> (PATH_PS), const_cast<char *> ("-al") },
+  { const_cast<char *> (PATH_LS), const_cast<char *> ("-nfail"), const_cast<char *> ("/tmp/.") },
 #ifdef PATH_NETSTAT
-  { PATH_NETSTAT, "-s" },
-  { PATH_NETSTAT, "-an" },
-  { PATH_NETSTAT, "-in" },
+  { const_cast<char *> (PATH_NETSTAT), const_cast<char *> ("-s") },
+  { const_cast<char *> (PATH_NETSTAT), const_cast<char *> ("-an") },
+  { const_cast<char *> (PATH_NETSTAT), const_cast<char *> ("-in") },
 #endif /* PATH_NETSTAT */
 #ifdef PATH_NTPQ
-  { PATH_NTPQ, "-np" },
+  { const_cast<char *> (PATH_NTPQ), const_cast<char *> ("-np") },
 #endif /* PATH_NTPQ */
 #ifdef PATH_W
-  { PATH_W },
+  { const_cast<char *> (PATH_W) },
 #endif /* PATH_W */
 #ifdef PATH_NFSSTAT
-  { PATH_NFSSTAT },
+  { const_cast<char *> (PATH_NFSSTAT) },
 #endif /* PATH_NFSSTAT */
 #ifdef PATH_VNSTAT
-  { PATH_VMSTAT },
-  { PATH_VMSTAT, "-i" },
-  { PATH_VMSTAT, "-s" },
+  { const_cast<char *> (PATH_VMSTAT) },
+  { const_cast<char *> (PATH_VMSTAT), const_cast<char *> ("-i") },
+  { const_cast<char *> (PATH_VMSTAT), const_cast<char *> ("-s") },
 #endif /* PATH_VNSTAT */
 #ifdef PATH_IOSTAT
 #if defined (__linux__) || defined (__osf__)
-  { PATH_IOSTAT },
+  { const_cast<char *> (PATH_IOSTAT) },
 #else /* not linux or osf */
-  { PATH_IOSTAT, "-I" },
+  { const_cast<char *> (PATH_IOSTAT), const_cast<char *> ("-I") },
 #endif /* not linux or osf */
 #endif /* PATH_IOSTAT */
 #ifdef PATH_LSOF
-  { PATH_LSOF, "-bwn",
+  { const_cast<char *> (PATH_LSOF), const_cast<char *> ("-bwn"),
 # ifdef LSOF_DEVCACHE
-    "-Di"
+    const_cast<char *> ("-Di")
 # endif /* LSOF_DEVCACHE */
   },
 #else /* no lsof */
 # ifdef PATH_FSTAT
-  { PATH_FSTAT },
+  { const_cast<char *> (PATH_FSTAT) },
 # endif /* PATH_FSTAT */
 # ifdef PATH_PSTAT
-  { PATH_PSTAT, "-f" },
+  { const_cast<char *> (PATH_PSTAT), const_cast<char *> ("-f") },
 # endif /* PATH_PSTAT */
 #endif /* no lsof */
 #ifdef PATH_PSTAT
-  { PATH_PSTAT, "-t" },
+  { const_cast<char *> (PATH_PSTAT), const_cast<char *> ("-t") },
 # if defined (__OpenBSD__) || defined (__NetBSD__) || defined (__FreeBSD__)
-  { PATH_PSTAT, "-v" },
+  { const_cast<char *> (PATH_PSTAT), const_cast<char *> ("-v") },
 # endif /* open/net/freebsd */
 #endif /* PATH_PSTAT */
 #ifdef PATH_NFSSTAT
-  { PATH_NFSSTAT },
+  { const_cast<char *> (PATH_NFSSTAT) },
 #endif /* PATH_NFSSTAT */
 #if 0
-  { PATH_RUP },
-  { PATH_RUSERS, "-l" },
+  { const_cast<char *> (PATH_RUP) },
+  { const_cast<char *> (PATH_RUSERS), const_cast<char *> ("-l") },
 #endif
   { NULL }
 };
