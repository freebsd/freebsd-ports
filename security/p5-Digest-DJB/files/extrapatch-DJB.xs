--- DJB.xs.orig	Sat Dec 24 10:44:54 2005
+++ DJB.xs	Sat Dec 24 10:45:41 2005
@@ -2,6 +2,15 @@
 #include "perl.h"
 #include "XSUB.h"
 
+/* try to be compatible with older perls */
+/* SvPV_nolen() macro first defined in 5.005_55 */
+/* this is slow, not threadsafe, but works */
+#include "patchlevel.h"
+#if (PATCHLEVEL == 4) || ((PATCHLEVEL == 5) && (SUBVERSION < 55))
+static STRLEN nolen_na;
+# define SvPV_nolen(sv) SvPV ((sv), nolen_na)
+#endif
+
 #define UCHAR unsigned char
 
 size_t
