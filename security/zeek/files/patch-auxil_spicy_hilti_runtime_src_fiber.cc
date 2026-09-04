--- auxil/spicy/hilti/runtime/src/fiber.cc.orig	2026-09-04 12:06:27 UTC
+++ auxil/spicy/hilti/runtime/src/fiber.cc	2026-09-04 12:06:27 UTC
@@ -213,7 +213,7 @@
             if ( limit.rlim_cur < min_size )
                 throw RuntimeError(fmt("process stack size too small, need at least %zu KB", min_size / 1024));
 
-#if __x86_64__ || __arm__ || __arm64__ || __aarch64__ || __i386__
+#if __x86_64__ || __arm__ || __arm64__ || __aarch64__ || __i386__ || __powerpc64__
             // There's a bit of fuzziness here as the current frame won't start
             // exactly at the beginning of the stack---but should be good
             // enough.
@@ -330,7 +330,7 @@
     // The direction in which the stack grows is platform-specific. It's
     // probably gong to be growing downwards pretty much everywhere, but to be
     // safe we whitelist platforms that we have confirmed to do so.
-#if __x86_64__ || __arm__ || __arm64__ || __aarch64__ || __i386__
+#if __x86_64__ || __arm__ || __arm64__ || __aarch64__ || __i386__ || __powerpc64__
     auto* lower = reinterpret_cast<char*>(_fiber->regs.sp);
     auto* upper = reinterpret_cast<char*>(_fiber->regs.sp) + fiber_stack_used_size(_fiber);
 #else
@@ -349,7 +349,7 @@
     assert(::fiber_is_executing(_fiber)); // must be live
 
     // Whitelist architectures where we know how to do this.
-#if __x86_64__ || __arm__ || __arm64__ || __aarch64__ || __i386__
+#if __x86_64__ || __arm__ || __arm64__ || __aarch64__ || __i386__ || __powerpc64__
     // See
     // https://stackoverflow.com/questions/20059673/print-out-value-of-stack-pointer
     // for discussion of how to get stack pointer.
