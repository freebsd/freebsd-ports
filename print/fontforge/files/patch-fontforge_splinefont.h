--- fontforge/splinefont.h~
+++ fontforge/splinefont.h
@@ -3547,7 +3547,11 @@ char * delimit_null(const char * input, 
 
 #include "ustring.h"
 
-#ifdef __MINGW32__
+#ifdef __FreeBSD__
+#include <osreldate.h>
+#endif
+
+#if defined(__MINGW32__) || (defined(__FreeBSD__) && __FreeBSD_version < 900506)
 #define BAD_LOCALE_HACK
 typedef char* locale_t;
 #define LC_GLOBAL_LOCALE ((locale_t)-1)
