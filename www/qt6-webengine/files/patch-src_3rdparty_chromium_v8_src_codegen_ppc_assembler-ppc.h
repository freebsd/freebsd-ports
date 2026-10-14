--- src/3rdparty/chromium/v8/src/codegen/ppc/assembler-ppc.h.orig	2026-09-18 00:00:00 UTC
+++ src/3rdparty/chromium/v8/src/codegen/ppc/assembler-ppc.h
@@ -1413,10 +1413,12 @@
 
   RelocInfoWriter reloc_info_writer;
 
- private:
+ public:
   // Avoid overflows for displacements etc.
   static const int kMaximalBufferSize = 512 * MB;
 
+ private:
+
   // Repeated checking whether the trampoline pool should be emitted is rather
   // expensive. By default we only check again once a number of instructions
   // has been generated.
