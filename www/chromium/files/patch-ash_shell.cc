--- ash/shell.cc.orig	2017-01-26 00:49:07 UTC
+++ ash/shell.cc
@@ -579,7 +579,7 @@ void Shell::Init(const ShellInitParams& 
 
   immersive_handler_factory_ = base::MakeUnique<ImmersiveHandlerFactoryAsh>();
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
   NOTREACHED() << "linux desktop does not support ash.";
 #endif
 
