--- usr/lib/ica_s390_stdll/ica_s390_stdll.mk.orig	2022-04-25 11:04:51 UTC
+++ usr/lib/ica_s390_stdll/ica_s390_stdll.mk
@@ -3,7 +3,7 @@ nobase_lib_LTLIBRARIES += opencryptoki/stdll/libpkcs11
 noinst_HEADERS += usr/lib/ica_s390_stdll/tok_struct.h
 
 opencryptoki_stdll_libpkcs11_ica_la_CFLAGS =				\
-	-DDEV -D_THREAD_SAFE -fPIC -DSHALLOW=0 -DSWTOK=0 -DLITE=1	\
+	-DDEV -D_THREAD_SAFE $(FPIC) -DSHALLOW=0 -DSWTOK=0 -DLITE=1	\
 	-DNODH -DNOCDMF -DNOMD2 -DNODSA -DSTDLL_NAME=\"icatok\"		\
 	-DTOK_NEW_DATA_STORE=0x0003000c					\
 	$(ICA_INC_DIRS) -I${srcdir}/usr/lib/ica_s390_stdll		\
@@ -12,7 +12,7 @@ opencryptoki_stdll_libpkcs11_ica_la_CFLAGS =				\
 
 opencryptoki_stdll_libpkcs11_ica_la_LDFLAGS =				\
 	$(LCRYPTO) $(ICA_LIB_DIRS) -nostartfiles -shared		\
-	-Wl,-z,defs,-Bsymbolic -Wl,-soname,$@ -lc -lpthread -lica -ldl	\
+	-Wl,-z,defs,-Bsymbolic -Wl,-soname,$@ -lc -lpthread -lica 	\
 	-lcrypto -lrt							\
 	-Wl,--version-script=${srcdir}/opencryptoki_tok.map
 
