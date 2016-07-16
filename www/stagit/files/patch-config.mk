--- config.mk.orig	2016-05-07 13:07:28 UTC
+++ config.mk
@@ -19,14 +19,14 @@ LIBS = -L${GITLIB} -lgit2 -lc
 #LDFLAGS = ${LIBS}
 
 # optimized
-CFLAGS = -O2 -std=c99 ${INCS}
-LDFLAGS = -s ${LIBS}
+CFLAGS = -std=c99 ${INCS}
+LDFLAGS = ${LIBS}
 
 # optimized static
 #CFLAGS = -static -O2 -std=c99 ${INCS}
 #LDFLAGS = -static -s ${LIBS}
 
-CPPFLAGS = -D_XOPEN_SOURCE=700 -D_DEFAULT_SOURCE -D_BSD_SOURCE ${INCS}
+CPPFLAGS+= -D_XOPEN_SOURCE=700 -D_DEFAULT_SOURCE -D_BSD_SOURCE ${INCS}
 
 # OpenBSD 5.9+: use pledge(2)
 #CPPFLAGS += -DUSE_PLEDGE
