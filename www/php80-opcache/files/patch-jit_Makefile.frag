--- jit/Makefile.frag.orig	2020-11-24 17:04:03 UTC
+++ jit/Makefile.frag
@@ -5,7 +5,7 @@ $(builddir)/minilua: $(srcdir)/jit/dynasm/minilua.c
 $(builddir)/jit/zend_jit_x86.c: $(srcdir)/jit/zend_jit_x86.dasc $(srcdir)/jit/dynasm/*.lua $(builddir)/minilua
 	$(builddir)/minilua $(srcdir)/jit/dynasm/dynasm.lua  $(DASM_FLAGS) -o $@ $(srcdir)/jit/zend_jit_x86.dasc
 
-$(builddir)/jit/zend_jit.lo: \
+jit/zend_jit.lo: \
 	$(builddir)/jit/zend_jit_x86.c \
 	$(srcdir)/jit/zend_jit_helpers.c \
 	$(srcdir)/jit/zend_jit_disasm_x86.c \
