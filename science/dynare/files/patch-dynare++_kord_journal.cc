- FreeBSD compatibility.

--- dynare++/kord/journal.cc.orig	2021-08-14 01:22:14 UTC
+++ dynare++/kord/journal.cc
@@ -33,7 +33,7 @@
 # include <sys/utsname.h>  // For uname()
 # include <cstdlib>        // For getloadavg()
 # include <unistd.h>       // For sysconf()
-# ifdef __APPLE__
+# if defined(__APPLE__) || defined(__FreeBSD__)
 #  include <sys/types.h>
 #  include <sys/sysctl.h>
 # endif
@@ -57,9 +57,9 @@ SystemResources::pageSize()
 long
 SystemResources::availableMemory()
 {
-#if !defined(_WIN32) && !defined(__APPLE__)
+#if !defined(_WIN32) && !defined(__APPLE__) && !defined(__FreeBSD__)
   return sysconf(_SC_AVPHYS_PAGES)*pageSize();
-#elif defined(__APPLE__)
+#elif defined(__APPLE__) || defined(__FreeBSD__)
   unsigned long usermem = 0;
   size_t len = sizeof usermem;
   static int mib[2] = { CTL_HW, HW_USERMEM };
