--- freebsd/freebsd/Makefile.inc.orig	2010-09-01 08:54:06.000000000 +0200
+++ freebsd/freebsd/Makefile.inc	2014-01-26 19:12:09.000000000 +0100
@@ -19,4 +19,4 @@
 TOUCH?=		touch
 
 beforeinstall:
-	${MKDIR} ${KMODDIR}
+	${MKDIR} ${DESTDIR}${KMODDIR}
