--- mozilla/MyportalProtocolHandler.cpp.orig	Thu Feb 13 16:23:25 2003
+++ mozilla/MyportalProtocolHandler.cpp	Thu Feb 13 16:26:47 2003
@@ -16,6 +16,10 @@
  *  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
  */
 
+#ifdef HAVE_CONFIG_H
+#include <config.h>
+#endif
+
 #include "bookmarks.h"
 #include "bookmarks-iterator.h"
 #include "eel-gconf-extensions.h"
@@ -249,17 +253,23 @@
 	g_free (myportalURI);
 #else
 	nsCOMPtr<nsIInputStream> iStream;
-	PRUint32 size;  
-    
-	rv = sStream->GetLength(&size);
+	rv = sStream->NewInputStream(0, getter_AddRefs(iStream));
+
 	if (NS_FAILED(rv)) return rv;
 
-	rv = sStream->NewInputStream(0, getter_AddRefs(iStream));
+#if MOZILLA_SNAPSHOT > 3
+	rv = NS_NewInputStreamChannel(getter_AddRefs(mChannel), mURI,
+				      iStream, NS_LITERAL_CSTRING("text/html"),
+				      NS_LITERAL_CSTRING("utf-8"));
+#else
+	PRUint32 size;
+	rv = sStream->GetLength(&size);
 	if (NS_FAILED(rv)) return rv;
 
 	rv = NS_NewInputStreamChannel(getter_AddRefs(mChannel), mURI,
 				      iStream, NS_LITERAL_CSTRING("text/html"),
 				      NS_LITERAL_CSTRING("utf-8"), size);
+#endif
 	if (NS_FAILED(rv)) return rv;
 #endif
 	g_free (stylesheet_filename);
