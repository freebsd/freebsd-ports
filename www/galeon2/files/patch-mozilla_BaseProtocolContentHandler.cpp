--- mozilla/BaseProtocolContentHandler.cpp.orig	Thu Feb 13 16:21:02 2003
+++ mozilla/BaseProtocolContentHandler.cpp	Thu Feb 13 16:22:10 2003
@@ -16,6 +16,10 @@
  *  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
  */
 
+#ifdef HAVE_CONFIG_H
+#include <config.h>
+#endif
+
 #include "nsCOMPtr.h"
 #include "nsIURI.h"
 #include "nsIChannel.h"
@@ -63,8 +67,13 @@
 	if (NS_FAILED(rv)) return rv;
 
 	nsCOMPtr<nsIChannel> channel;
+#if MOZILLA_SNAPSHOT > 3
+	rv = NS_NewInputStreamChannel(getter_AddRefs(channel), aURI,
+				      iStream, mMimeType, NS_LITERAL_CSTRING(""));
+#else
 	rv = NS_NewInputStreamChannel(getter_AddRefs(channel), aURI,
 				      iStream, mMimeType, NS_LITERAL_CSTRING(""), 0);
+#endif
 	if (NS_FAILED(rv)) return rv;
 
 	NS_IF_ADDREF (*_retval = channel);
