--- mozilla/GlobalHistory.cpp.orig	Thu Feb 13 16:30:19 2003
+++ mozilla/GlobalHistory.cpp	Thu Feb 13 16:32:29 2003
@@ -16,6 +16,10 @@
  *  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
  */
 
+#ifdef HAVE_CONFIG_H
+#include <config.h>
+#endif
+
 #include "galeon-config.h"
 #include "mozilla-embed-shell.h"
 
@@ -149,6 +153,13 @@
 {
     return NS_ERROR_NOT_IMPLEMENTED;
 }
+
+#if MOZILLA_SNAPSHOT > 3
+NS_IMETHODIMP MozGlobalHistory::OutputReferrerURL(const char *aURL, const char *aReferrer)
+{
+    return NS_ERROR_NOT_IMPLEMENTED;
+}
+#endif
 
 NS_DEF_FACTORY (MozGlobalHistory, MozGlobalHistory);
 
