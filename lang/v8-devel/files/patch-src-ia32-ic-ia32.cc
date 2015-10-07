--- src/ia32/ic-ia32.cc.orig	2014-06-03 08:52:11 UTC
+++ src/ia32/ic-ia32.cc
@@ -1262,7 +1262,8 @@ void PatchInlinedSmiCode(Address address
   uint8_t delta = *reinterpret_cast<uint8_t*>(delta_address);
   if (FLAG_trace_ic) {
     PrintF("[  patching ic at %p, test=%p, delta=%d\n",
-           address, test_instruction_address, delta);
+           reinterpret_cast<void*>(address),
+           reinterpret_cast<void*>(test_instruction_address), delta);
   }
 
   // Patch with a short conditional jump. Enabling means switching from a short
