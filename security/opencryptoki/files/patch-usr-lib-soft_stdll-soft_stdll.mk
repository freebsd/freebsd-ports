--- usr/lib/soft_stdll/soft_stdll.mk.orig	2018-11-16 14:53:03 UTC
+++ usr/lib/soft_stdll/soft_stdll.mk
@@ -4,7 +4,7 @@ noinst_HEADERS += usr/lib/soft_stdll/tok_struct.h
 
 opencryptoki_stdll_libpkcs11_sw_la_CFLAGS =				\
 	-DDEV -D_THREAD_SAFE -DSHALLOW=0 -DSWTOK=1 -DLITE=0 -DNOCDMF	\
-	-DNOMD2 -DNODSA -DNORIPE -fPIC -I${srcdir}/usr/lib/soft_stdll	\
+	-DNOMD2 -DNODSA -DNORIPE $(FPIC) -I${srcdir}/usr/lib/soft_stdll	\
 	-I${srcdir}/usr/lib/common -I${srcdir}/usr/include		\
 	-DSTDLL_NAME=\"swtok\"
 
