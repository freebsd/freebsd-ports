--- mozilla/mozilla-embed-persist.cpp.orig	Thu Feb 13 16:18:30 2003
+++ mozilla/mozilla-embed-persist.cpp	Thu Feb 13 16:20:25 2003
@@ -16,6 +16,10 @@
  *  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
  */
 
+#ifdef HAVE_CONFIG_H
+#include <config.h>
+#endif
+
 #include "mozilla-embed-persist.h"
 #include "mozilla-embed.h"
 #include "ProgressListener.h"
@@ -235,7 +239,11 @@
                                  	   persist, 
 					   !(flags & EMBED_PERSIST_SHOW_PROGRESS));
 
+#if MOZILLA_SNAPSHOT > 3
+		rv = bpersist->SaveURI (linkURI, nsnull, nsnull, nsnull, nsnull, file);
+#else
 		rv = bpersist->SaveURI (linkURI, nsnull, file);
+#endif
 		if (NS_FAILED(rv)) return G_FAILED;
 	}
 	
