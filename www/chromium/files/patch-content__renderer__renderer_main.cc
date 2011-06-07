--- content/renderer/renderer_main.cc.orig	2011-03-20 22:02:04.303357408 +0200
+++ content/renderer/renderer_main.cc	2011-03-20 22:02:04.457737643 +0200
@@ -272,7 +272,7 @@
   PepperPluginRegistry::GetInstance();
 
   {
-#if !defined(OS_LINUX)
+#if !defined(OS_LINUX) && !defined(OS_FREEBSD)
     // TODO(markus): Check if it is OK to unconditionally move this
     // instruction down.
     RenderProcessImpl render_process;
@@ -284,7 +284,7 @@
     } else {
       LOG(ERROR) << "Running without renderer sandbox";
     }
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
     RenderProcessImpl render_process;
     render_process.set_main_thread(new RenderThread());
 #endif
