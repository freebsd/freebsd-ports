--- config.mk.orig	2016-01-09 11:40:56 UTC
+++ config.mk
@@ -10,8 +10,13 @@ INCS = -I.
 TERMINFO := ${DESTDIR}${PREFIX}/share/terminfo
 
 INCS = -I.
-LIBS = -lc -lutil -lncursesw
-CPPFLAGS = -D_POSIX_C_SOURCE=200809L -D_XOPEN_SOURCE=700 -D_XOPEN_SOURCE_EXTENDED
+LIBS = -lc -lutil
+.if exists(/usr/lib/libncursesw.so)
+LIBS += -lncursesw
+.else
+LIBS += -lncurses
+.endif
+CPPFLAGS = -D_POSIX_C_SOURCE=200809L -D_XOPEN_SOURCE=700 -D_XOPEN_SOURCE_EXTENDED -D__BSD_VISIBLE
 CFLAGS += -std=c99 ${INCS} -DVERSION=\"${VERSION}\" -DNDEBUG ${CPPFLAGS}
 LDFLAGS += ${LIBS}
 
