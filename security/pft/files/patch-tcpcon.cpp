--- tcpcon.cpp.orig	Sat Jul  6 18:36:21 2002
+++ tcpcon.cpp	Thu Aug  5 18:54:27 2004
@@ -2,7 +2,7 @@
  *
  * $Id: tcpcon.cpp,v 1.2 2002/01/07 17:18:49 fx Exp $
  */
-#include <iostream.h>
+#include <iostream>
 #include <string.h>
 #include <time.h>
 
@@ -17,15 +17,17 @@
 // defined on Windows but not on UNIX 
 #define INVALID_SOCKET		(-1)
 #define SOCKET_ERROR		(-1)
-#endif UNIX
+#endif // UNIX
 
 #include "tcpcon.h"
 
+using namespace std;
+
 TCPcon::TCPcon() {
 #ifndef UNIX
 	WORD wVersionRequested; 
 	WSADATA wsaData; 
-#endif UNIX
+#endif // UNIX
 	
 	// initialize values
 	memset(&dest,0,sizeof(dest));
@@ -40,10 +42,10 @@
 	if (WSAStartup(wVersionRequested, &wsaData)!=0) {
 #ifdef _DEBUG
 		cerr << "TCPcon::TCPcon() starting WSA failed\n";
-#endif _DEBUG
+#endif // _DEBUG
 		throw ExWinSock();
 	}
-#endif UNIX
+#endif // UNIX
 }
 
 
@@ -51,7 +53,7 @@
 	if (connected) closeconnection();
 #ifndef UNIX
 	WSACleanup();
-#endif UNIX
+#endif // UNIX
 }
 
 
@@ -61,7 +63,7 @@
 	if ((he=gethostbyname(host))==NULL) {
 #ifdef _DEBUG
 		cerr << "TCPcon::set_host(): gethostbyname() failed\n";
-#endif _DEBUG
+#endif // _DEBUG
 		throw ExResolver();
 	}
 
@@ -75,7 +77,7 @@
 	if ((port<=0)||(port>65535)) {
 #ifdef _DEBUG
 		cerr << "TCPcon::set_port(): port out of range\n";
-#endif _DEBUG
+#endif // _DEBUG
 		throw ExInvalid();
 	}
 	dest.sin_port=htons(port);
@@ -92,21 +94,21 @@
 	if ( ntohs(*((unsigned short *)(&(dest.sin_port))))==0 ) {
 #ifdef _DEBUG
 		cerr << "TCPcon::startconnection(): port not set\n";
-#endif _DEBUG
+#endif // _DEBUG
 		throw ExInvalid();
 	}
 
 	if ((sfd=socket(AF_INET,SOCK_STREAM,0))==INVALID_SOCKET) {
 #ifdef _DEBUG
 		cerr << "TCPcon::startconnection(): socket() failed\n";
-#endif _DEBUG
+#endif // _DEBUG
 		throw ExSocket();
 	}
 
 	if (connect(sfd,(struct sockaddr *)&dest,sizeof(dest))!=0) {
 #ifdef _DEBUG
 		cerr << "TCPcon::startconnection(): connect() failed\n";
-#endif _DEBUG
+#endif // _DEBUG
 		throw ExSocket();
 	}
 
@@ -120,7 +122,7 @@
 		closesocket(sfd);
 #else
 		close(sfd);
-#endif UNIX
+#endif // UNIX
 	}
 	connected=false;
 }
@@ -152,14 +154,14 @@
 	if (sendbuf.length()==0) {
 #ifdef _DEBUG
 		cerr << "TCPcon::send(): send buffer empty\n";
-#endif _DEBUG
+#endif // _DEBUG
 		throw ExInvalid();
 	}
 
 	if (send(sfd,(char *)sendbuf.get(),sendbuf.length(),0)==SOCKET_ERROR) {
 #ifdef _DEBUG
 		cerr << "TCPcon::send(): send() failed\n";
-#endif _DEBUG
+#endif // _DEBUG
 		throw ExSocket();
 	}
 }
@@ -173,7 +175,7 @@
 	if ((tp=(char *)malloc(TPSIZE))==NULL) {
 #ifdef _DEBUG
 		cerr << "TCPcon::recvdata(): malloc() failed\n";
-#endif _DEBUG
+#endif // _DEBUG
 		throw ExMalloc();
 	}
 	
@@ -240,7 +242,7 @@
 		throw ExTimeout();
 #ifdef _DEBUG
 		cerr << "TCPcon::recvuntilchr(): timed out\n";
-#endif _DEBUG
+#endif // _DEBUG
 	}
 }
 
@@ -263,7 +265,7 @@
 		throw ExTimeout();
 #ifdef _DEBUG
 		cerr << "TCPcon::recvuntilstr(): timed out\n";
-#endif _DEBUG
+#endif // _DEBUG
 	}
 }
 
@@ -286,7 +288,7 @@
 		throw ExTimeout();
 #ifdef _DEBUG
 		cerr << "TCPcon::recvatleast(): timed out\n";
-#endif _DEBUG
+#endif // _DEBUG
 	}
 }
 
