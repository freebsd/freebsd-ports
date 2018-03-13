--- config.mk.orig	2017-11-11 02:19:32 UTC
+++ config.mk
@@ -2,8 +2,6 @@
 VERSION = 0.0
 
 # paths
-PREFIX = /usr/local
-MANPREFIX = $(PREFIX)/share/man
 
 CC = cc
 AR = ar
@@ -11,6 +9,6 @@ RANLIB = ranlib
 
 # for NetBSD add -D_NETBSD_SOURCE
 # -lrt might be needed on some systems
-CPPFLAGS = -D_DEFAULT_SOURCE -D_BSD_SOURCE -D_XOPEN_SOURCE=700 -D_FILE_OFFSET_BITS=64
-CFLAGS   = -std=c99 -Wall -pedantic
-LDFLAGS  = -s
+CPPFLAGS += -D_DEFAULT_SOURCE -D_BSD_SOURCE -D_FILE_OFFSET_BITS=64
+CFLAGS   += -std=c99 -Wall -pedantic
+LDFLAGS  += -s
