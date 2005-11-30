--- config/rules.mk.orig	Sun May 18 16:10:18 2003
+++ config/rules.mk	Sun Jul 20 18:07:26 2003
@@ -448,7 +448,11 @@
 
 ifeq ($(OS_ARCH),FreeBSD)
 ifdef IS_COMPONENT
+ifneq (,$(filter alpha ia64,$(OS_TEST)))
+EXTRA_DSO_LDOPTS += -Wl,-Bsymbolic -lc
+else
 EXTRA_DSO_LDOPTS += -Wl,-Bsymbolic
+endif
 endif
 endif
 
