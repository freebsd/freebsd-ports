$FreeBSD$
  $MCom: ports/www/firefox-devel/files/patch-config-rules.mk,v 1.6 2005/07/14 05:25:44 ahze Exp $

--- config/rules.mk.orig	Tue Aug 26 13:28:47 2003
+++ config/rules.mk	Sun Feb  1 15:11:41 2004
@@ -444,7 +444,11 @@
 
 ifeq ($(OS_ARCH),FreeBSD)
 ifdef IS_COMPONENT
+ifneq (,$(filter alpha ia64,$(OS_TEST)))
+EXTRA_DSO_LDOPTS += -Wl,-Bsymbolic -lc
+else
 EXTRA_DSO_LDOPTS += -Wl,-Bsymbolic
+endif
 endif
 endif
 
