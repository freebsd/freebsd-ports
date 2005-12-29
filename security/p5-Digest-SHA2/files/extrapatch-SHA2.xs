--- SHA2.xs.orig	Sat Dec 24 21:15:29 2005
+++ SHA2.xs	Sat Dec 24 21:16:10 2005
@@ -4,6 +4,15 @@
 #include "ppport.h"
 #include "_sha2.c"
 
+/* try to be compatible with older perls */
+/* SvPV_nolen() macro first defined in 5.005_55 */
+/* this is slow, not threadsafe, but works */
+#include "patchlevel.h"
+#if (PATCHLEVEL == 4) || ((PATCHLEVEL == 5) && (SUBVERSION < 55))
+static STRLEN nolen_na;
+# define SvPV_nolen(sv) SvPV ((sv), nolen_na)
+#endif
+
 typedef struct sha2 {
     SHA256_CTX ctx256;
     SHA384_CTX ctx384;
