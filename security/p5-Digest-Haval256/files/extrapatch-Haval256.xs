--- Haval256.xs.orig	Sat Dec 24 09:54:45 2005
+++ Haval256.xs	Sat Dec 24 09:55:39 2005
@@ -4,6 +4,15 @@
 #include "ppport.h"
 #include "_haval.c"
 
+/* try to be compatible with older perls */
+/* SvPV_nolen() macro first defined in 5.005_55 */
+/* this is slow, not threadsafe, but works */
+#include "patchlevel.h"
+#if (PATCHLEVEL == 4) || ((PATCHLEVEL == 5) && (SUBVERSION < 55))
+static STRLEN nolen_na;
+# define SvPV_nolen(sv) SvPV ((sv), nolen_na)
+#endif
+
 typedef struct haval {
     haval_state state;
 }* Digest__Haval256;
