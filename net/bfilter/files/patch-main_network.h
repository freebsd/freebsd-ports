
$FreeBSD$

--- main/network.h.orig	Sat Jul 17 12:33:38 2004
+++ main/network.h	Sat Jul 17 12:34:22 2004
@@ -55,7 +55,7 @@
 #else
 	typedef int Socket;
 	static const Socket INVALID_SOCK = -1;
-	typedef ::iovec iovec;
+	typedef iovec IoVec;
 #endif
 	typedef std::list<in_addr> addr_list_type;
 	static addr_list_type resolve(const char *host, NetworkError *err=0);
@@ -64,7 +64,7 @@
 	static Socket tcpConnect(const char *host, unsigned port, NetworkError* err=0);
 	static bool tcpSendData(Socket sock, const std::string& data, NetworkError* err=0);
 	static void sockSetNodelay(Socket sock, bool state);
-	static int writev(int sock, const iovec* iov, int cnt);
+	static int writev(int sock, const IoVec* iov, int cnt);
 	static void closeSocket(Socket sock);
 	static void disconnectAndCloseSocket(Socket sock, int timeout);
 	static bool isValidSocket(Socket sock);
