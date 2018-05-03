--- config.mk.orig	2018-04-02 23:23:00 UTC
+++ config.mk
@@ -8,9 +8,8 @@ PREFIX = /usr/local
 MANPREFIX = $(PREFIX)/share/man
 
 # flags
-CPPFLAGS = -DVERSION=\"$(VERSION)\" -D_DEFAULT_SOURCE -D_XOPEN_SOURCE=700 -D_BSD_SOURCE
-CFLAGS   = -std=c99 -pedantic -Wall -Wextra -Os
-LDFLAGS  = -s
+CPPFLAGS += -DVERSION=\"$(VERSION)\" -D_DEFAULT_SOURCE -D_XOPEN_SOURCE=700 -D_BSD_SOURCE
+CFLAGS   += -std=c99 -pedantic -Wall -Wextra
 
 # compiler and linker
 CC = cc
