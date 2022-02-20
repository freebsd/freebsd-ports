--- ui/gfx/render_text_api_fuzzer.cc.orig	2022-02-07 13:39:41 UTC
+++ ui/gfx/render_text_api_fuzzer.cc
@@ -20,7 +20,7 @@
 
 // TODO(crbug.com/1052397): Revisit once build flag switch of lacros-chrome is
 // complete.
-#if defined(OS_ANDROID) || (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS))
+#if defined(OS_ANDROID) || (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD))
 #include "base/test/test_discardable_memory_allocator.h"
 #endif
 
@@ -42,7 +42,7 @@ struct Environment {
     logging::SetMinLogLevel(logging::LOG_FATAL);
 // TODO(crbug.com/1052397): Revisit once build flag switch of lacros-chrome is
 // complete.
-#if defined(OS_ANDROID) || (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS))
+#if defined(OS_ANDROID) || (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD))
     // Some platforms require discardable memory to use bitmap fonts.
     base::DiscardableMemoryAllocator::SetInstance(
         &discardable_memory_allocator);
@@ -53,7 +53,7 @@ struct Environment {
 
 // TODO(crbug.com/1052397): Revisit once build flag switch of lacros-chrome is
 // complete.
-#if defined(OS_ANDROID) || (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS))
+#if defined(OS_ANDROID) || (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD))
   base::TestDiscardableMemoryAllocator discardable_memory_allocator;
 #endif
 
