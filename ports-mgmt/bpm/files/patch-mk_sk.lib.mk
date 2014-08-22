--- ./mk/sk.lib.mk.orig	2004-06-08 02:31:49.000000000 +0200
+++ ./mk/sk.lib.mk	2014-08-22 02:02:31.000000000 +0200
@@ -83,16 +83,16 @@
 install:
 .ifndef INTERNAL_LIB
 .ifndef NO_STATIC
-	[ -d ${PREFIX}/${LIB_DIR} ] ||\
-	    mkdir -p -m ${DIR_MODE} ${PREFIX}/${LIB_DIR}
+	[ -d ${DESTDIR}${PREFIX}/${LIB_DIR} ] ||\
+	    mkdir -p -m ${DIR_MODE} ${DESTDIR}${PREFIX}/${LIB_DIR}
 	${INSTALL} ${INST_FLAGS} ${STRIP} -o ${LIB_OWN} -g ${LIB_GRP}\
-	    -m ${LIB_MODE} ${LIB}.a ${PREFIX}/${LIB_DIR}
+	    -m ${LIB_MODE} ${LIB}.a ${DESTDIR}${PREFIX}/${LIB_DIR}
 .endif
 .ifndef NO_SHARED
-	[ -d ${PREFIX}/${LIB_DIR} ] ||\
-	    mkdir -p -m ${DIR_MODE} ${PREFIX}/${LIB_DIR}
+	[ -d ${DESTDIR}${PREFIX}/${LIB_DIR} ] ||\
+	    mkdir -p -m ${DIR_MODE} ${DESTDIR}${PREFIX}/${LIB_DIR}
 	${INSTALL} ${INST_FLAGS} ${STRIP} -o ${LIB_OWN} -g ${LIB_GRP}\
-	    -m ${LIB_MODE} ${LIB}.so${SO_SUFFIX} ${PREFIX}/${LIB_DIR}
+	    -m ${LIB_MODE} ${LIB}.so${SO_SUFFIX} ${DESTDIR}${PREFIX}/${LIB_DIR}
 .endif
 .endif # INTERNAL_LIB
 
