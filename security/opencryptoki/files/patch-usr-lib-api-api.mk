--- usr/lib/api/api.mk.orig	2018-11-16 14:53:03 UTC
+++ usr/lib/api/api.mk
@@ -7,12 +7,12 @@ SO_REVISION=0
 SO_AGE=0
 
 opencryptoki_libopencryptoki_la_CFLAGS =				\
-	-DAPI -DDEV -D_THREAD_SAFE -fPIC -I${srcdir}/usr/include	\
+	-DAPI -DDEV -D_THREAD_SAFE $(FPIC) -I${srcdir}/usr/include	\
 	-I${srcdir}/usr/lib/common -I${srcdir}/usr/lib/api		\
 	-DSTDLL_NAME=\"api\"
 
 opencryptoki_libopencryptoki_la_LDFLAGS =				\
-	-shared	-Wl,-z,defs,-Bsymbolic -lc -ldl -lpthread		\
+	-shared	-Wl,-z,defs,-Bsymbolic -lc -lpthread			\
 	-version-info $(SO_CURRENT):$(SO_REVISION):$(SO_AGE)		\
 	-Wl,--version-script=${srcdir}/opencryptoki.map
 
