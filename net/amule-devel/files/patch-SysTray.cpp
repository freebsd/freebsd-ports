--- src/SysTray.cpp.orig	Sat Oct 23 05:53:20 2004
+++ src/SysTray.cpp	Sat Oct 23 05:55:40 2004
@@ -24,6 +24,12 @@
 		#include <sys/types.h>
 	#endif /* __BSD__ */
 
+#if defined(__FreeBSD__) // for FreeBSD 4.x
+        #if __FreeBSD__ < 5
+                #include <sys/types.h>
+        #endif
+#endif
+
 	#include <cstddef>			// Needed for NULL. Must be BEFORE gtk/gdk headers!
 	#include <sys/socket.h>		//
 	#include <netinet/in.h>		// Needed for inet_ntoa
