--- config/rules.mk.orig	Mon May  5 21:04:55 2003
+++ config/rules.mk	Tue May 27 01:33:11 2003
@@ -444,7 +444,11 @@
 
 ifeq ($(OS_ARCH),FreeBSD)
 ifdef IS_COMPONENT
+ifneq (,$(filter alpha,$(OS_TEST)))
+EXTRA_DSO_LDOPTS += -Wl,-Bsymbolic -lc
+else
 EXTRA_DSO_LDOPTS += -Wl,-Bsymbolic
+endif
 endif
 endif
 
