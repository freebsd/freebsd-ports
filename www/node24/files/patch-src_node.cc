--- src/node.cc.orig	2026-09-08 00:00:00 UTC
+++ src/node.cc
@@ -786,8 +786,10 @@
     v8_args.emplace_back("--js-source-phase-imports");
   }
 
+#if V8_ENABLE_WEBASSEMBLY
   // WebAssembly JS Promise Integration
   v8_args.emplace_back("--experimental-wasm-jspi");
+#endif  // V8_ENABLE_WEBASSEMBLY
 
 #ifdef __POSIX__
   // Block SIGPROF signals when sleeping in epoll_wait/kevent/etc.  Avoids the
