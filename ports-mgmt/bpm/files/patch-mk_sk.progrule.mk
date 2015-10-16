--- mk/sk.progrule.mk.orig	2004-06-07 23:11:45 UTC
+++ mk/sk.progrule.mk
@@ -40,13 +40,13 @@ all: ${PROG}.${MAN_SECT}
 .endif
 
 install::
-	[ -d ${PREFIX}/${BIN_DIR} ] ||\
-	    mkdir -p -m ${DIR_MODE} ${PREFIX}/${BIN_DIR}
-	${INSTALL} ${INST_FLAGS} ${STRIP} -o ${BIN_OWN} -g ${BIN_GRP} ${PROG}\
-	    ${PREFIX}/${BIN_DIR}
+	[ -d ${DESTDIR}${PREFIX}/${BIN_DIR} ] ||\
+	    mkdir -p -m ${DIR_MODE} ${DESTDIR}${PREFIX}/${BIN_DIR}
+	${INSTALL} ${INST_FLAGS} ${STRIP} ${PROG}\
+	    ${DESTDIR}${PREFIX}/${BIN_DIR}
 .ifndef NOMAN
 	[ -d ${MAN_DIR} ] || @mkdir -p -m ${DIR_MODE} ${MAN_DIR}
-	${INSTALL} ${INST_FLAGS} -o ${SHARE_OWN} -g ${SHARE_GRP}\
+	${INSTALL} ${INST_FLAGS} \
 	    -m ${SHARE_MODE} ${PROG}.${MAN_SECT} ${MAN_DIR}
 	@for l in ${MAN_LINKS};\
 	    do ln -sfv ${MAN_DIR}/${PROG}.${MAN_SECT} $$l;\
