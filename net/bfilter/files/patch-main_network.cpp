
$FreeBSD$

--- main/network.cpp.orig	Sat Jul 17 12:32:36 2004
+++ main/network.cpp	Sat Jul 17 12:33:21 2004
@@ -284,7 +284,7 @@
 }
 
 int
-Network::writev(int sock, const iovec* iov, int cnt)
+Network::writev(int sock, const IoVec* iov, int cnt)
 {
 #ifdef WIN32
 	DWORD sent;
@@ -298,7 +298,7 @@
 	return sent;
 #else
 	int sent;
-	SYSCALL(sent = ::writev(sock, iov, cnt));
+	SYSCALL(sent = writev(sock, iov, cnt));
 	return sent;
 #endif
 }
