Index: et/com_err.c
diff -u et/com_err.c.orig et/com_err.c
--- et/com_err.c.orig	Wed May 24 05:52:06 2000
+++ et/com_err.c	Sat Jul 19 23:22:43 2003
@@ -48,6 +48,9 @@
 #include <string.h>
 #include "mit-sipb-copyright.h"
 
+#ifdef __STDC__
+#define HAVE_STDARG_H	1
+#endif
 #if defined(HAVE_STDARG_H) || defined(_WINDOWS)
 #include <stdarg.h>
 #else
