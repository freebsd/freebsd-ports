--- pwauth.c.orig	Thu Oct 14 10:23:59 2004
+++ pwauth.c	Thu Oct 14 10:24:11 2004
@@ -141,7 +141,7 @@
 #ifdef UNIX_LASTLOG
 #define NEED_UID
 #include <utmp.h>
-#include <lastlog.h>
+//#include <lastlog.h>
 #ifndef UT_LINESIZE
 #define UT_LINESIZE 8
 #endif
