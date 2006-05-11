/*
 * Enable the recv() and send(), I am not sure why it was disabled on FreeBSD
 * only but allow other OSs. It works great as I have tested it with a few
 * of applications on FreeBSD 6.0. If anyone know why, please let me know.
 */
--- trickle-overload.c.orig	Sun May  7 23:05:43 2006
+++ trickle-overload.c	Sun May  7 23:07:06 2006
@@ -197,15 +197,11 @@
 
 	GETADDR(read);
 	GETADDR(readv);
-#ifndef __FreeBSD__
 	GETADDR(recv);
-#endif /* !__FreeBSD__ */
 	GETADDR(recvfrom);
 
 	GETADDR(writev);
-#ifndef __FreeBSD__
 	GETADDR(send);
-#endif /* !__FreeBSD__ */
 	GETADDR(sendto);
 
 	GETADDR(select);
@@ -627,7 +623,6 @@
 	return (ret);
 }
 
-#ifndef __FreeBSD__ 
 ssize_t
 recv(int sock, void *buf, size_t len, int flags)
 {
@@ -649,7 +644,6 @@
 
 	return (ret);
 }
-#endif /* !__FreeBSD__ */
 
 #ifdef __sun__
 ssize_t
@@ -730,7 +724,6 @@
 	return (ret);
 }
 
-#ifndef __FreeBSD__
 ssize_t
 send(int sock, const void *buf, size_t len, int flags)
 {
@@ -752,7 +745,6 @@
 
 	return (ret);
 }
-#endif /* !__FreeBSD__ */
 
 ssize_t
 sendto(int sock, const void *buf, size_t len, int flags, const struct sockaddr *to,
