--- embed/mozilla/EphyEventListener.cpp.orig	Sat Nov  1 22:39:59 2003
+++ embed/mozilla/EphyEventListener.cpp	Sat Nov  1 22:41:44 2003
@@ -16,6 +16,10 @@
  *  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
  */
 
+#ifdef HAVE_CONFIG_H
+#include <config.h>
+#endif
+
 #include <nsCOMPtr.h>
 
 #include "EphyEventListener.h"
@@ -80,9 +84,15 @@
 		nsCOMPtr<nsIDocument> doc = do_QueryInterface (domDoc);
 		if(!doc) return NS_ERROR_FAILURE;
 
+#if MOZILLA_SNAPSHOT > 11
+		nsIURI *uri;
+		uri = doc->GetDocumentURL ();
+		if (uri == NULL) return NS_ERROR_FAILURE;
+#else
 		nsCOMPtr<nsIURI> uri;
 		result = doc->GetDocumentURL(getter_AddRefs(uri));
 		if (NS_FAILED (result)) return NS_ERROR_FAILURE;
+#endif
 
 		const nsACString &link = NS_ConvertUCS2toUTF8(value);
 		nsCAutoString favicon_url;
