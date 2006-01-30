--- XPathContext.xs.orig	Mon Jan 16 11:27:29 2006
+++ XPathContext.xs	Mon Jan 16 11:28:54 2006
@@ -11,6 +11,15 @@
 #include "XSUB.h"
 #include "ppport.h"
 
+/* try to be compatible with older perls */
+/* SvPV_nolen() macro first defined in 5.005_55 */
+/* this is slow, not threadsafe, but works */
+#include "patchlevel.h"
+#if (PATCHLEVEL == 4) || ((PATCHLEVEL == 5) && (SUBVERSION < 55))
+static STRLEN nolen_na;
+# define SvPV_nolen(sv) SvPV ((sv), nolen_na)
+#endif
+
 /* libxml2 stuff */
 #include <libxml/xpath.h>
 #include <libxml/xpathInternals.h>
