--- config.mk.orig	2023-11-28 19:03:18.907271000 +0200
+++ config.mk	2023-11-28 19:03:52.448805000 +0200
@@ -18,22 +18,22 @@
 
 # IO type
 # clr (clear)
-#IO = clr
+IO = clr
 # tls (Transport Layer Security)
-IO = tls
-IOLIBS = -ltls
-IOCFLAGS = -DUSE_TLS
+#IO = tls
+#IOLIBS = -ltls
+#IOCFLAGS = -DUSE_TLS
 
 # OS compilation flags are used to expose the system interfaces
 # Linux, OpenBSD
-OSCFLAGS = -D_DEFAULT_SOURCE -D_XOPEN_SOURCE=700 -D_BSD_SOURCE -D_GNU_SOURCE
-OSLDFLAGS = 
+#OSCFLAGS = -D_DEFAULT_SOURCE -D_XOPEN_SOURCE=700 -D_BSD_SOURCE -D_GNU_SOURCE
+#OSLDFLAGS = 
 # NetBSD, using default pkgsrc path
 #OSCFLAGS = -I/usr/pkg/include
 #OSLDFLAGS = -L/usr/pkg/lib -R/usr/pkg/lib
 # FreeBSD
-#OSCFLAGS = -I/usr/local/include
-#OSLDFLAGS = -L/usr/local/lib
+OSCFLAGS = -I/usr/local/include
+OSLDFLAGS = -L/usr/local/lib
 
 # Define NEED_ASPRINTF and/or NEED_STRCASESTR in your OS compilation flags
 # if your system does not provide asprintf() or strcasestr(), respectively.
