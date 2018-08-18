--- third_party/blink/renderer/bindings/core/v8/v8_script_runner.cc.orig	2018-07-19 16:25:31.421721000 +0200
+++ third_party/blink/renderer/bindings/core/v8/v8_script_runner.cc	2018-07-19 16:26:01.053291000 +0200
@@ -54,7 +54,7 @@
 
 #if defined(OS_WIN)
 #include <malloc.h>
-#else
+#elif !defined(OS_FREEBSD)
 #include <alloca.h>
 #endif
 
