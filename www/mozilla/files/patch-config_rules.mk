--- config/rules.mk.orig	Fri Oct 25 01:59:03 2002
+++ config/rules.mk	Sat Jan 25 16:44:25 2003
@@ -463,6 +463,12 @@
 endif
 endif
 
+ifeq ($(OS_ARCH),FreeBSD)
+ifdef IS_COMPONENT
+EXTRA_DSO_LDOPTS += -Wl,-Bsymbolic
+endif
+endif
+
 ifeq ($(OS_ARCH),NetBSD)
 ifneq (,$(filter arc cobalt hpcmips mipsco newsmips pmax sgimips,$(OS_TEST)))
 ifeq ($(MODULE),layout)
