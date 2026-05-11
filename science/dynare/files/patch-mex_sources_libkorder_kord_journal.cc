-- FreeBSD compatibility: fix invalid preprocessor directive '#ifdef __APPLE__ || defined(__FreeBSD__)'
-- (the '|| defined(...)' part is silently ignored by the preprocessor). The correct form is
-- '#if defined(__APPLE__) || defined(__FreeBSD__)'.
-- Also adds FreeBSD-specific memory query using sysctl(3) instead of sysconf(3), as
-- _SC_AVPHYS_PAGES is not available on FreeBSD.

--- mex/sources/libkorder/kord/journal.cc.orig	2025-03-19 00:00:00 UTC
+++ mex/sources/libkorder/kord/journal.cc	2025-03-19 00:00:00 UTC
@@ -33,7 +33,7 @@
 # include <sys/time.h>     // For getrusage()
 # include <sys/utsname.h>  // For uname()
 # include <unistd.h>       // For sysconf()
-# ifdef __APPLE__
+# if defined(__APPLE__) || defined(__FreeBSD__)
 #  include <sys/sysctl.h>
 #  include <sys/types.h>
 # endif
@@ -58,9 +58,9 @@
 long
 SystemResources::availableMemory()
 {
-#if !defined(_WIN32) && !defined(__APPLE__)
+#if !defined(_WIN32) && !defined(__APPLE__) && !defined(__FreeBSD__)
   return sysconf(_SC_AVPHYS_PAGES) * pageSize();
-#elif defined(__APPLE__)
+#elif defined(__APPLE__) || defined(__FreeBSD__)
   unsigned long usermem = 0;
   size_t len = sizeof usermem;
   static int mib[2] = {CTL_HW, HW_USERMEM};
