--- config/rules.mk.orig	Thu Jun 13 07:00:30 2002
+++ config/rules.mk	Sat Jan 25 16:48:21 2003
@@ -467,6 +467,12 @@
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
