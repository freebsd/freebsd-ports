--- src/runwhen.h.orig	2022-08-10 16:08:24 UTC
+++ src/runwhen.h
@@ -8,8 +8,8 @@
   } while (0)
 
 #include <skalibs/tai.h>
-void rw_scan(tain_t*, char const*);
-void rw_pass(tain_t const*, char**) gccattr_noreturn;
+void rw_scan(tain*, char const*);
+void rw_pass(tain const*, char**) gccattr_noreturn;
 
 #define WARNTEXT0_clock_gettime "get current time"
 
