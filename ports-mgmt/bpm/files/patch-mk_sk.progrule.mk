--- ./mk/sk.progrule.mk.orig	2004-06-08 01:11:45.000000000 +0200
+++ ./mk/sk.progrule.mk	2014-08-22 02:04:46.000000000 +0200
@@ -40,10 +40,10 @@
 .endif
 
 install::
-	[ -d ${PREFIX}/${BIN_DIR} ] ||\
-	    mkdir -p -m ${DIR_MODE} ${PREFIX}/${BIN_DIR}
+	[ -d ${DESTDIR}${PREFIX}/${BIN_DIR} ] ||\
+	    mkdir -p -m ${DIR_MODE} ${DESTDIR}${PREFIX}/${BIN_DIR}
 	${INSTALL} ${INST_FLAGS} ${STRIP} -o ${BIN_OWN} -g ${BIN_GRP} ${PROG}\
-	    ${PREFIX}/${BIN_DIR}
+	    ${DESTDIR}${PREFIX}/${BIN_DIR}
 .ifndef NOMAN
 	[ -d ${MAN_DIR} ] || @mkdir -p -m ${DIR_MODE} ${MAN_DIR}
 	${INSTALL} ${INST_FLAGS} -o ${SHARE_OWN} -g ${SHARE_GRP}\
