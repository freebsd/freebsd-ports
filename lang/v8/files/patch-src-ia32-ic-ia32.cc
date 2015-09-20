--- src/ia32/ic-ia32.cc.orig	2013-05-01 12:56:29 UTC
+++ src/ia32/ic-ia32.cc
@@ -1657,7 +1657,8 @@ void PatchInlinedSmiCode(Address address
   int8_t delta = *reinterpret_cast<int8_t*>(delta_address);
   if (FLAG_trace_ic) {
     PrintF("[  patching ic at %p, test=%p, delta=%d\n",
-           address, test_instruction_address, delta);
+           reinterpret_cast<void*>(address),
+           reinterpret_cast<void*>(test_instruction_address), delta);
   }
 
   // Patch with a short conditional jump. Enabling means switching from a short
