--- ./mk/sk.localerule.mk.orig	2004-08-24 05:15:03.000000000 +0200
+++ ./mk/sk.localerule.mk	2014-08-22 02:03:51.000000000 +0200
@@ -36,12 +36,12 @@
 
 install:
 	@set -x; for l in ${LANGS}; do\
-	    [ -d ${PREFIX}/${LOCALE_DIR}/$$l/LC_MESSAGES ] ||\
+	    [ -d ${DESTDIR}${PREFIX}/${LOCALE_DIR}/$$l/LC_MESSAGES ] ||\
 		mkdir -p -m ${DIR_MODE}\
-		${PREFIX}/${LOCALE_DIR}/$$l/LC_MESSAGES;\
+		${DESTDIR}${PREFIX}/${LOCALE_DIR}/$$l/LC_MESSAGES;\
 	    ${INSTALL} ${INST_FLAGS} -o ${SHARE_OWN} -g ${SHARE_GRP} -m\
 		${SHARE_MODE} $$l.mo\
-		${PREFIX}/${LOCALE_DIR}/$$l/LC_MESSAGES/${PACKAGE}.mo;\
+		${DESTDIR}${PREFIX}/${LOCALE_DIR}/$$l/LC_MESSAGES/${PACKAGE}.mo;\
 	done
 
 .include    "sk.targets.mk"
