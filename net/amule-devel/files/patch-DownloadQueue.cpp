--- src/DownloadQueue.cpp.orig	Sat Oct 23 05:04:50 2004
+++ src/DownloadQueue.cpp	Sat Oct 23 05:07:18 2004
@@ -24,6 +24,13 @@
 	#include <winsock.h>
 	#include <wx/msw/winundef.h>
 #else
+
+	#if defined(__FreeBSD__)
+	  #if __FreeBSD__ < 5
+	    #include <sys/types.h>
+	  #endif
+	#endif
+
 	#include <netdb.h>		// Needed for gethostbyname_r
 	#include <sys/socket.h>		//
 	#include <netinet/in.h>		// These three are needed for inet_ntoa
