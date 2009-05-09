--- mod_clamav.h.orig	2009-04-11 10:31:32.000000000 -0300
+++ mod_clamav.h	2009-04-11 10:32:11.000000000 -0300
@@ -70,9 +70,7 @@
 #ifdef HAVE_ALLOCA_H
 #include <alloca.h>
 #endif /* HAVE_ALLOCA_H */
-#ifdef HAVE_REGEX_H
-#include <regex.h>
-#endif /* HAVE_REGEX_H */
+#include <ap_regex.h>
 
 #ifndef CLAMAV_DEBUG
 #define	CLAMAV_DEBUG	0
