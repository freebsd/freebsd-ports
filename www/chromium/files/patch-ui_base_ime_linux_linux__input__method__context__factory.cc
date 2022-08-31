--- ui/base/ime/linux/linux_input_method_context_factory.cc.orig	2022-08-31 12:19:35 UTC
+++ ui/base/ime/linux/linux_input_method_context_factory.cc
@@ -9,7 +9,7 @@
 #include "build/build_config.h"
 #include "ui/base/ime/linux/fake_input_method_context.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "ui/linux/linux_ui.h"
 #include "ui/linux/linux_ui_delegate.h"
 #endif
@@ -37,7 +37,7 @@ std::unique_ptr<LinuxInputMethodContext> CreateLinuxIn
     if (auto context = factory.Run(delegate))
       return context;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Finally, let the toolkit create the context.
   if (auto* linux_ui = LinuxUi::instance()) {
     if (auto context = linux_ui->CreateInputMethodContext(delegate))
