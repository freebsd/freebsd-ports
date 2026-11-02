--- src/3rdparty/chromium/v8/src/codegen/ppc/assembler-ppc.h.orig	2026-10-21 00:29:58 UTC
+++ src/3rdparty/chromium/v8/src/codegen/ppc/assembler-ppc.h
@@ -1413,9 +1413,11 @@ class Assembler : public AssemblerBase {
 
   RelocInfoWriter reloc_info_writer;
 
- private:
+ public:
   // Avoid overflows for displacements etc.
   static const int kMaximalBufferSize = 512 * MB;
+
+ private:
 
   // Repeated checking whether the trampoline pool should be emitted is rather
   // expensive. By default we only check again once a number of instructions
