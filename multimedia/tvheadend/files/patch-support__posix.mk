--- support/posix.mk.orig	2013-05-05 14:49:47.000000000 +0200
+++ support/posix.mk	2013-05-05 15:50:33.514989222 +0200
@@ -7,8 +7,8 @@
 install: ${PROG} ${MAN}
 	install -d ${DESTDIR}${bindir}
 	install ${PROG} ${DESTDIR}${bindir}/tvheadend
-	install -d ${DESTDIR}${mandir}
-	install ${MAN} ${DESTDIR}${mandir}/tvheadend.1
+	install -d ${DESTDIR}${mandir}/man1
+	install ${MAN} ${DESTDIR}${mandir}/man1/tvheadend.1
 
 	for bundle in ${BUNDLES}; do \
 		mkdir -p ${DESTDIR}${datadir}/tvheadend/$$bundle ;\
@@ -19,5 +19,5 @@
 
 uninstall:
 	rm -f ${DESTDIR}${bindir}/tvheadend
-	rm -f ${DESTDIR}${mandir}/tvheadend.1
+	rm -f ${DESTDIR}${mandir}/man1/tvheadend.1
 	rm -rf ${DESTDIR}${datadir}/tvheadend
