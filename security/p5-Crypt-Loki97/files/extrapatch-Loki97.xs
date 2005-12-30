--- Loki97.xs.orig	Sat Dec 31 03:04:38 2005
+++ Loki97.xs	Sat Dec 31 03:05:06 2005
@@ -4,6 +4,15 @@
 #include "ppport.h"
 #include "_loki97.c"
 
+/* try to be compatible with older perls */
+/* SvPV_nolen() macro first defined in 5.005_55 */
+/* this is slow, not threadsafe, but works */
+#include "patchlevel.h"
+#if (PATCHLEVEL == 4) || ((PATCHLEVEL == 5) && (SUBVERSION < 55))
+static STRLEN nolen_na;
+# define SvPV_nolen(sv) SvPV ((sv), nolen_na)
+#endif
+
 typedef struct loki97 {
     keyInstance enc_key, dec_key;
     cipherInstance cipher;
