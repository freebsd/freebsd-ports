--- mk/sk.localerule.mk.orig	2004-08-24 03:15:03 UTC
+++ mk/sk.localerule.mk
@@ -36,12 +36,12 @@
 
 install:
 	@set -x; for l in ${LANGS}; do\
-	    [ -d ${PREFIX}/${LOCALE_DIR}/$$l/LC_MESSAGES ] ||\
+	    [ -d ${DESTDIR}${PREFIX}/${LOCALE_DIR}/$$l/LC_MESSAGES ] ||\
 		mkdir -p -m ${DIR_MODE}\
-		${PREFIX}/${LOCALE_DIR}/$$l/LC_MESSAGES;\
-	    ${INSTALL} ${INST_FLAGS} -o ${SHARE_OWN} -g ${SHARE_GRP} -m\
+		${DESTDIR}${PREFIX}/${LOCALE_DIR}/$$l/LC_MESSAGES;\
+	    ${INSTALL} ${INST_FLAGS} -m\
 		${SHARE_MODE} $$l.mo\
-		${PREFIX}/${LOCALE_DIR}/$$l/LC_MESSAGES/${PACKAGE}.mo;\
+		${DESTDIR}${PREFIX}/${LOCALE_DIR}/$$l/LC_MESSAGES/${PACKAGE}.mo;\
 	done
 
 .include    "sk.targets.mk"
