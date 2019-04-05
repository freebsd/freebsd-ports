--- content/public/common/content_features.cc.orig	2019-03-24 18:52:00.447438000 +0100
+++ content/public/common/content_features.cc	2019-03-24 18:52:16.870073000 +0100
@@ -493,7 +493,7 @@
                                         base::FEATURE_DISABLED_BY_DEFAULT};
 
 // Enable WebAssembly trap handler.
-#if defined(OS_LINUX) && defined(ARCH_CPU_X86_64)
+#if (defined(OS_BSD) || defined(OS_LINUX)) && defined(ARCH_CPU_X86_64)
 const base::Feature kWebAssemblyTrapHandler{"WebAssemblyTrapHandler",
                                             base::FEATURE_ENABLED_BY_DEFAULT};
 #else
