--- ./mk/sk.scriptrule.mk.orig	2004-06-02 04:09:53.000000000 +0200
+++ ./mk/sk.scriptrule.mk	2014-08-22 02:06:04.000000000 +0200
@@ -37,11 +37,11 @@
 all:
 
 install:
-	[ -d ${PREFIX}/${SCRIPT_DIR} ] ||\
-	    mkdir -p -m ${DIR_MODE} ${PREFIX}/${SCRIPT_DIR}
+	[ -d ${DESTDIR}${PREFIX}/${SCRIPT_DIR} ] ||\
+	    mkdir -p -m ${DIR_MODE} ${DESTDIR}${PREFIX}/${SCRIPT_DIR}
 	@set -x; for s in ${SCRIPTS}; do\
 	    ${INSTALL} ${INST_FLAGS} -o ${BIN_OWN} -g ${BIN_GRP}\
-	    -m ${BIN_MODE} $$s.*sh ${PREFIX}/${SCRIPT_DIR}/$$s;\
+	    -m ${BIN_MODE} $$s.*sh ${DESTDIR}${PREFIX}/${SCRIPT_DIR}/$$s;\
 	done
 
 .include    "${BASE_DIR}/mk/sk.targets.mk"
