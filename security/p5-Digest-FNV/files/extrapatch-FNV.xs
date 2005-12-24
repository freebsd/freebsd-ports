--- FNV.xs.orig	Sat Dec 24 10:51:11 2005
+++ FNV.xs	Sat Dec 24 10:51:55 2005
@@ -4,6 +4,15 @@
 
 #include "fnvlib/fnv.h"
 
+/* try to be compatible with older perls */
+/* SvPV_nolen() macro first defined in 5.005_55 */
+/* this is slow, not threadsafe, but works */
+#include "patchlevel.h"
+#if (PATCHLEVEL == 4) || ((PATCHLEVEL == 5) && (SUBVERSION < 55))
+static STRLEN nolen_na;
+# define SvPV_nolen(sv) SvPV ((sv), nolen_na)
+#endif
+
 static int
 not_here(char *s)
 {
