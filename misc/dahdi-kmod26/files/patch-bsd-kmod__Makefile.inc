--- bsd-kmod/Makefile.inc.orig	2012-02-26 21:53:27.000000000 +0100
+++ bsd-kmod/Makefile.inc	2014-01-26 19:46:54.000000000 +0100
@@ -19,4 +19,4 @@
 TOUCH?=		touch
 
 beforeinstall:
-	${MKDIR} ${KMODDIR}
+	${MKDIR} ${DESTDIR}${KMODDIR}
