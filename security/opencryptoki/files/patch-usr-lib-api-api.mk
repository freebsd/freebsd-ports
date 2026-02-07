--- usr/lib/api/api.mk.orig	2022-04-25 11:04:51 UTC
+++ usr/lib/api/api.mk
@@ -8,14 +8,14 @@ SO_REVISION=0
 SO_AGE=0
 
 opencryptoki_libopencryptoki_la_CFLAGS =				\
-	-DAPI -DDEV -D_THREAD_SAFE -fPIC -I${srcdir}/usr/include	\
+	-DAPI -DDEV -D_THREAD_SAFE $(FPIC) -I${srcdir}/usr/include	\
 	-I${srcdir}/usr/lib/common -I${srcdir}/usr/lib/api		\
 	-I${srcdir}/usr/lib/config -I${top_builddir}/usr/lib/config	\
 	-DSTDLL_NAME=\"api\" -DHASHMAP_JENKINS_MIX  			\
 	-I${top_builddir}/usr/lib/api
 
 opencryptoki_libopencryptoki_la_LDFLAGS =				\
-	-shared	-Wl,-z,defs,-Bsymbolic -lc -ldl -lpthread -lcrypto -lrt	\
+	-shared	-Wl,-z,defs,-Bsymbolic -lc -lpthread -lcrypto -lrt	\
 	-version-info $(SO_CURRENT):$(SO_REVISION):$(SO_AGE)		\
 	-Wl,--version-script=${srcdir}/opencryptoki.map
 
