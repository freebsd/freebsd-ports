--- usr/lib/soft_stdll/soft_stdll.mk.orig	2022-04-25 11:04:51 UTC
+++ usr/lib/soft_stdll/soft_stdll.mk
@@ -4,7 +4,7 @@ noinst_HEADERS += usr/lib/soft_stdll/tok_struct.h
 
 opencryptoki_stdll_libpkcs11_sw_la_CFLAGS =				\
 	-DDEV -D_THREAD_SAFE -DSHALLOW=0 -DSWTOK=1 -DLITE=0 -DNOCDMF	\
-	-DNOMD2 -DNODSA -DNORIPE -fPIC -I${srcdir}/usr/lib/soft_stdll	\
+	-DNOMD2 -DNODSA -DNORIPE $(FPIC) -I${srcdir}/usr/lib/soft_stdll	\
 	-DTOK_NEW_DATA_STORE=0x0003000c					\
 	-I${srcdir}/usr/lib/common -I${srcdir}/usr/include		\
 	-DSTDLL_NAME=\"swtok\" -I${top_builddir}/usr/lib/api		\
