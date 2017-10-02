--- dialects/freebsd/dlsof.h.orig	2017-09-15 15:56:37.973983000 -0700
+++ dialects/freebsd/dlsof.h	2017-09-15 15:57:27.970424000 -0700
@@ -142,8 +142,10 @@
 #include <rpc/types.h>
 #include <sys/protosw.h>
 #include <sys/socket.h>
+#define	_WANT_SOCKET			/* for FreeBSD 12 and above */
 #include <sys/socketvar.h>
 #include <sys/un.h>
+#define	_WANT_UNPCB			/* for FreeBSD 12 and above */
 #include <sys/unpcb.h>
 
 # if	FREEBSDV>=3000
