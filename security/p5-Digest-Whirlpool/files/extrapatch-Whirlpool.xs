--- Whirlpool.xs.orig	Sat Dec 24 23:41:30 2005
+++ Whirlpool.xs	Sat Dec 24 23:42:16 2005
@@ -4,6 +4,15 @@
 #include "ppport.h"
 #include "_whirlpool.c"
 
+/* try to be compatible with older perls */
+/* SvPV_nolen() macro first defined in 5.005_55 */
+/* this is slow, not threadsafe, but works */
+#include "patchlevel.h"
+#if (PATCHLEVEL == 4) || ((PATCHLEVEL == 5) && (SUBVERSION < 55))
+static STRLEN nolen_na;
+# define SvPV_nolen(sv) SvPV ((sv), nolen_na)
+#endif
+
 typedef struct whirlpool {
     NESSIEstruct state;
 }* Digest__Whirlpool;
