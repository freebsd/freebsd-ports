--- Shark.xs.orig	Sat Dec 31 04:10:06 2005
+++ Shark.xs	Sat Dec 31 04:10:37 2005
@@ -4,6 +4,15 @@
 #include "ppport.h"
 #include "_shark.c"
 
+/* try to be compatible with older perls */
+/* SvPV_nolen() macro first defined in 5.005_55 */
+/* this is slow, not threadsafe, but works */
+#include "patchlevel.h"
+#if (PATCHLEVEL == 4) || ((PATCHLEVEL == 5) && (SUBVERSION < 55))
+static STRLEN nolen_na;
+# define SvPV_nolen(sv) SvPV ((sv), nolen_na)
+#endif
+
 typedef struct shark {
     ddword roundkey_enc[14];
     ddword roundkey_dec[14];
