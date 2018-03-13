--- config.mk.orig	2018-03-05 09:24:46 UTC
+++ config.mk
@@ -5,12 +5,11 @@ VERSION = 0
 
 # paths
 PREFIX = /usr/local
-MANPREFIX = $(PREFIX)/share/man
+MANPREFIX = $(PREFIX)/man
 
 # flags
-CPPFLAGS = -DVERSION=\"$(VERSION)\" -D_DEFAULT_SOURCE -D_XOPEN_SOURCE=700 -D_BSD_SOURCE
-CFLAGS   = -std=c99 -pedantic -Wall -Wextra -Os
-LDFLAGS  = -s
+CPPFLAGS += -DVERSION=\"$(VERSION)\" -D_DEFAULT_SOURCE -D_XOPEN_SOURCE=700 -D_BSD_SOURCE
+CFLAGS   += -std=c99 -pedantic -Wall -Wextra
 
 # compiler and linker
-CC = cc
+CC ?= cc
