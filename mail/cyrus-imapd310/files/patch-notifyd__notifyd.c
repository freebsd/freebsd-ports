--- notifyd/notifyd.c.orig	2021-05-05 03:21:59 UTC
+++ notifyd/notifyd.c
@@ -50,6 +50,9 @@
 #include <sysexits.h>
 #include <syslog.h>
 #include <sys/types.h>
+#if defined(__FreeBSD__)
+#include <sys/sysctl.h>
+#endif
 #include <sys/socket.h>
 #include <netinet/in.h>
 #include <sys/un.h>
@@ -111,6 +114,23 @@ static int do_notify(void)
     unsigned bufsiz;
     socklen_t optlen;
 
+#if defined(__FreeBSD__)
+    size_t maxsockbuf;
+    size_t len = sizeof(maxsockbuf);
+    r = sysctlbyname("kern.ipc.maxsockbuf", &maxsockbuf, &len, NULL, 0);
+    if (r == 0) {
+        bufsiz = MIN(maxsockbuf, NOTIFY_MAXSIZE);
+    } else {
+        syslog(LOG_WARNING, "unable to sysctlbyname(kern.ipc.maxsockbuf): %m");
+        bufsiz = NOTIFY_MAXSIZE;
+    }
+
+    optlen = sizeof(bufsiz);
+    r = setsockopt(soc, SOL_SOCKET, SO_RCVBUF, &bufsiz, optlen);
+    if (r == -1) {
+        syslog(LOG_WARNING, "unable to setsockopt(SO_RCVBUF) on notify socket: %m");
+    }
+#else
     /* Get receive buffer size */
     optlen = sizeof(bufsiz);
     r = getsockopt(soc, SOL_SOCKET, SO_RCVBUF, &bufsiz, &optlen);
@@ -121,6 +141,7 @@ static int do_notify(void)
 
     /* Use minimum of 1/10 of receive buffer size (-overhead) NOTIFY_MAXSIZE */
     bufsiz = MIN(bufsiz / 10 - 32, NOTIFY_MAXSIZE);
+#endif
 
     while (1) {
         method = class = priority = user = mailbox = message = reply = NULL;
