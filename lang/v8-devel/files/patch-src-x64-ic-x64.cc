--- src/x64/ic-x64.cc.orig	2016-01-17 13:52:46 UTC
+++ src/x64/ic-x64.cc
@@ -1283,7 +1283,8 @@ void PatchInlinedSmiCode(Address address
   uint8_t delta = *reinterpret_cast<uint8_t*>(delta_address);
   if (FLAG_trace_ic) {
     PrintF("[  patching ic at %p, test=%p, delta=%d\n",
-           address, test_instruction_address, delta);
+           reinterpret_cast<void*>(address),
+           reinterpret_cast<void*>(test_instruction_address), delta);
   }
 
   // Patch with a short conditional jump. Enabling means switching from a short
