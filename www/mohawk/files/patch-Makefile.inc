--- Makefile.inc.orig	2014-07-24 14:39:15.798656512 +0200
+++ Makefile.inc	2014-07-24 14:39:25.056652385 +0200
@@ -9,8 +9,8 @@
 .if ${OPSYS} == "FreeBSD" || ${OPSYS} == "DragonFly"
 PREFIX?=  /usr/local
 CFLAGS+=  -I${PREFIX}/include
-LDFLAGS+= -L${PREFIX}/lib/event2
-LDADD+=   -lcrypt -levent-2.0
+LDFLAGS+= -L${PREFIX}/lib
+LDADD+=   -lcrypt -levent
 MANDIR= ${PREFIX}/man/man
 OSVERSION!= sysctl -n kern.osreldate
 .if ${OPSYS} == "FreeBSD" && ${OSVERSION} >= 1000032
