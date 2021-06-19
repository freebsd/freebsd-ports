--- imap/notify.c.orig	2021-05-10 04:34:24 UTC
+++ imap/notify.c
@@ -49,6 +49,9 @@
 #include <syslog.h>
 #include <sys/mman.h>
 #include <sys/types.h>
+#if defined(__FreeBSD__)
+#include <sys/sysctl.h>
+#endif
 #include <sys/socket.h>
 #include <netinet/in.h>
 #include <sys/un.h>
@@ -209,6 +212,27 @@ EXPORTED void notify(const char *method,
                 FNAME_NOTIFY_SOCK, sizeof(sun_data.sun_path));
     }
 
+#if defined(__FreeBSD__)
+    size_t maxsockbuf;
+    size_t len = sizeof(maxsockbuf);
+    r = sysctlbyname("kern.ipc.maxsockbuf", &maxsockbuf, &len, NULL, 0);
+    if (r == 0) {
+        bufsiz = MIN(maxsockbuf, NOTIFY_MAXSIZE);
+    } else {
+        syslog(LOG_WARNING,
+               "NOTIFY(%s): unable to sysctlbyname(kern.ipc.maxsockbuf): %m",
+               loginfo);
+        bufsiz = NOTIFY_MAXSIZE;
+    }
+
+    optlen = sizeof(bufsiz);
+    r = setsockopt(soc, SOL_SOCKET, SO_SNDBUF, &bufsiz, optlen);
+    if (r == -1) {
+        syslog(LOG_WARNING,
+               "NOTIFY(%s): unable to setsockopt(SO_SNDBUF) on socket: %m",
+               loginfo);
+    }
+#else
     /* Get send buffer size */
     optlen = sizeof(bufsiz);
     r = getsockopt(soc, SOL_SOCKET, SO_SNDBUF, &bufsiz, &optlen);
@@ -221,6 +245,7 @@ EXPORTED void notify(const char *method,
 
     /* Use minimum of 1/10 of send buffer size (-overhead) NOTIFY_MAXSIZE */
     bufsiz = MIN(bufsiz / 10 - 32, NOTIFY_MAXSIZE);
+#endif
 
     /*
      * build request of the form:
