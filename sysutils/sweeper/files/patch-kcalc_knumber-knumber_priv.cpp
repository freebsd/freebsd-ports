--- kcalc/knumber/knumber_priv.cpp.orig	Tue Dec 20 14:54:29 2005
+++ kcalc/knumber/knumber_priv.cpp	Tue Dec 20 14:59:11 2005
@@ -20,6 +20,9 @@
 #include <math.h>
 #include <config.h>
 
+#ifdef HAVE_STDLIB_H
+#include <stdlib.h>
+#endif
 #include <qregexp.h>
 #include <qstring.h>
 
