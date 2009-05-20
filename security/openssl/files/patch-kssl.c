--- ssl/kssl.c.orig	2009-02-14 22:50:13.000000000 +0100
+++ ssl/kssl.c	2009-05-20 17:11:00.000000000 +0200
@@ -68,11 +68,6 @@
 
 #include <openssl/opensslconf.h>
 
-#define _XOPEN_SOURCE 500 /* glibc2 needs this to declare strptime() */
-#include <time.h>
-#if 0 /* experimental */
-#undef _XOPEN_SOURCE /* To avoid clashes with anything else... */
-#endif
 #include <string.h>
 
 #define KRB5_PRIVATE	1
