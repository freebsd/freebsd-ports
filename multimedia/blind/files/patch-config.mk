--- config.mk.orig	2017-05-06 11:27:39 UTC
+++ config.mk
@@ -2,10 +2,10 @@
 VERSION = 1.1
 
 # Paths
-PREFIX = /usr/local
-MANPREFIX = $(PREFIX)/share/man
+PREFIX ?= /usr/local
+MANPREFIX = $(PREFIX)/man
 
 # You may want to remove -DHAVE_PRCTL and -DHAVE_EPOLL from CPPFLAGS if you are not using Linux.
-CFLAGS   = -std=c99 -Wall -pedantic -O2
-CPPFLAGS = -D_DEFAULT_SOURCE -D_BSD_SOURCE -D_XOPEN_SOURCE=700 -D_FILE_OFFSET_BITS=64 -DHAVE_PRCTL -DHAVE_EPOLL
-LDFLAGS  = -lm -s
+CFLAGS   += -std=c99 -Wall -pedantic
+CPPFLAGS += -D_DEFAULT_SOURCE -D_BSD_SOURCE -D_FILE_OFFSET_BITS=64
+LDFLAGS  += -lm -lc -s
