--- src/UDPSocket.cpp.orig	Fri Oct  1 09:06:52 2004
+++ src/UDPSocket.cpp	Sat Oct 23 05:18:16 2004
@@ -23,6 +23,13 @@
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
 	#include <netdb.h>
 	#include <sys/socket.h>
 	#include <netinet/in.h>
