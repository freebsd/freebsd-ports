--- services/service_manager/public/cpp/service_executable/service_executable_environment.cc.orig	2021-12-31 00:57:38 UTC
+++ services/service_manager/public/cpp/service_executable/service_executable_environment.cc
@@ -51,6 +51,13 @@ ServiceExecutableEnvironment::ServiceExecutableEnviron
                 sandbox::policy::switches::kServiceSandboxType)),
         sandbox::policy::SandboxLinux::PreSandboxHook(), sandbox_options);
   }
+#elif defined(OS_FREEBSD)
+  if (command_line.HasSwitch(sandbox::policy::switches::kServiceSandboxType)) {
+    sandbox::policy::Sandbox::Initialize(
+        sandbox::policy::UtilitySandboxTypeFromString(
+            command_line.GetSwitchValueASCII(
+                sandbox::policy::switches::kServiceSandboxType)));
+  }
 #endif
 
   mojo::core::Init();
