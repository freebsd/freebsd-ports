--- mk/sk.sharerule.mk.orig	2004-07-23 03:45:59 UTC
+++ mk/sk.sharerule.mk
@@ -37,11 +37,11 @@
 all: ${SHARES}
 
 install:
-	[ -d ${PREFIX}/${SHARE_DIR} ] ||\
-	    mkdir -p -m ${DIR_MODE} ${PREFIX}/${SHARE_DIR}
+	[ -d ${DESTDIR}${PREFIX}/${SHARE_DIR} ] ||\
+	    mkdir -p -m ${DIR_MODE} ${DESTDIR}${PREFIX}/${SHARE_DIR}
 	@set -x; for s in ${SHARES}; do\
-	    ${INSTALL} -o ${SHARE_OWN} -g ${SHARE_GRP} -m ${SHARE_MODE}\
-		$$s ${PREFIX}/${SHARE_DIR};\
+	    ${INSTALL} -m ${SHARE_MODE}\
+		$$s ${DESTDIR}${PREFIX}/${SHARE_DIR};\
 	done
 
 .include    "${BASE_DIR}/mk/sk.targets.mk"
