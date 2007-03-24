--- config/rules.mk.orig	Fri Apr 28 12:25:51 2006
+++ config/rules.mk
@@ -443,7 +443,11 @@
 
 ifeq ($(OS_ARCH),FreeBSD)
 ifdef IS_COMPONENT
+ifneq (,$(filter alpha ia64,$(OS_TEST)))
+EXTRA_DSO_LDOPTS += -Wl,-Bsymbolic -lc
+else
 EXTRA_DSO_LDOPTS += -Wl,-Bsymbolic
+endif
 endif
 endif
 
