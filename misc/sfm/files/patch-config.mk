--- config.mk.orig	2021-11-05 14:11:35 UTC
+++ config.mk
@@ -6,9 +6,9 @@ PREFIX    = /usr/local
 MANPREFIX = ${PREFIX}/share/man
 
 # flags
-CPPFLAGS = -D_DEFAULT_SOURCE -D_BSD_SOURCE -D_POSIX_C_SOURCE=200809L -D_XOPEN_SOURCE=700 -DVERSION=\"${VERSION}\"
-CFLAGS   = -std=c99 -pedantic -Wextra -Wall -Wno-unused-parameter -Os ${CPPFLAGS}
-LDFLAGS  = -pthread -s
+CPPFLAGS += -D_DEFAULT_SOURCE -D_BSD_SOURCE -D_POSIX_C_SOURCE=200809L -D_XOPEN_SOURCE=700 -DVERSION=\"${VERSION}\"
+CFLAGS   += -pedantic -Wextra -Wall -Wno-unused-parameter ${CPPFLAGS}
+LDFLAGS  += -pthread
 
 # compiler and linker
-CC = cc
+CC ?= cc
