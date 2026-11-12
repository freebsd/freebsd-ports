V8 commit dec5f6bdbe68 ([wasm] Fix walking WasmLiftoffSetupFrame) made
frames.cc read WasmLiftoffSetupFrameConstants::kCallingPCOffset, but the PPC
port only got the constant in f285826766bd (PPC/s390: [wasm] Fix walking
WasmLiftoffSetupFrame).  Backport that one line for powerpc64le.

--- src/3rdparty/chromium/v8/src/execution/ppc/frame-constants-ppc.h.orig	2026-11-10 20:53:34 UTC
+++ src/3rdparty/chromium/v8/src/execution/ppc/frame-constants-ppc.h
@@ -33,6 +33,7 @@
   static constexpr int kNumberOfSavedFpParamRegs = 8;
 
   // There's one spilled value (which doesn't need visiting) below the instance.
+  static constexpr int kCallingPCOffset = TYPED_FRAME_PUSHED_VALUE_OFFSET(0);
   static constexpr int kInstanceSpillOffset =
       TYPED_FRAME_PUSHED_VALUE_OFFSET(1);
 
