--- src/ClientDetailDialog.cpp.orig	Sat Oct 23 05:00:14 2004
+++ src/ClientDetailDialog.cpp	Sat Oct 23 05:00:45 2004
@@ -31,6 +31,12 @@
        #include <sys/types.h>
 #endif /* __BSD__ */
 
+#if defined(__FreeBSD__) // for FreeBSD 4.x
+	#if __FreeBSD__ < 5
+		#include <sys/types.h>
+	#endif
+#endif
+
 	#include <sys/socket.h>
 	#include <netinet/in.h>
 	#include <arpa/inet.h>
