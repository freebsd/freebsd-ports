--- deps/v8/src/compiler/backend/ppc/code-generator-ppc.cc.orig	2026-07-28 22:07:50 UTC
+++ deps/v8/src/compiler/backend/ppc/code-generator-ppc.cc
@@ -2863,7 +2863,7 @@
       break;
     }
     case kPPC_I8x16BitMask: {
-      __ I8x16BitMask(i.OutputRegister(), i.InputSimd128Register(0), r0, ip,
+      __ I8x16BitMask(i.OutputRegister(), i.InputSimd128Register(0), ip, r0,
                       kScratchSimd128Reg);
       break;
     }
