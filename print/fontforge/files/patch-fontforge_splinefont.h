--- fontforge/splinefont.h.orig	2015-08-20 03:39:10 UTC
+++ fontforge/splinefont.h
@@ -3548,7 +3548,11 @@ char * delimit_null(const char * input, 
 
 #include "ustring.h"
 
-#ifdef _WIN32
+#ifdef __FreeBSD__
+#include <osreldate.h>
+#endif
+
+#if defined(_WIN32) || (defined(__FreeBSD__) && __FreeBSD_version < 900506)
 #define BAD_LOCALE_HACK
 typedef char* locale_t;
 #define LC_GLOBAL_LOCALE ((locale_t)-1)
