--- base/memory/protected_memory.h.orig	2024-10-22 08:31:56 UTC
+++ base/memory/protected_memory.h
@@ -119,12 +119,12 @@ __declspec(selectany) char __stop_protected_memory;
 
 #define DECLARE_PROTECTED_DATA constinit
 #define DEFINE_PROTECTED_DATA constinit __declspec(allocate("prot$mem"))
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_ANDROID)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
 // This value is used to align the writers variable. That variable needs to be
 // aligned to ensure that the protected memory section starts on a page
 // boundary.
 #if (PA_BUILDFLAG(IS_ANDROID) && PA_BUILDFLAG(PA_ARCH_CPU_64_BITS)) || \
-    (PA_BUILDFLAG(IS_LINUX) && PA_BUILDFLAG(PA_ARCH_CPU_ARM64))
+    ((PA_BUILDFLAG(IS_LINUX) || PA_BUILDFLAG(IS_BSD)) && PA_BUILDFLAG(PA_ARCH_CPU_ARM64))
 // arm64 supports 4kb, 16kb, and 64kb pages. Set to the largest of 64kb as that
 // will guarantee the section is page aligned regardless of the choice.
 inline constexpr int kProtectedMemoryAlignment = 65536;
@@ -339,7 +339,7 @@ class BASE_EXPORT AutoWritableMemoryBase {
     // where an attacker could overwrite it with a large value and invoke code
     // that constructs and destructs an AutoWritableMemory. After such a call
     // protected memory would still be set writable because writers > 0.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_ANDROID)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
     // On Linux, the protected memory section is not automatically page aligned.
     // This means that attempts to reset the protected memory region to readonly
     // will set some of the preceding section that is on the same page readonly
@@ -353,7 +353,7 @@ class BASE_EXPORT AutoWritableMemoryBase {
 #endif
     static inline size_t writers GUARDED_BY(writers_lock()) = 0;
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_ANDROID)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
     // On Linux, there is no guarantee the section following the protected
     // memory section is page aligned. This can result in attempts to change
     // the access permissions of the end of the protected memory section
@@ -411,7 +411,7 @@ class BASE_EXPORT AutoWritableMemoryInitializer
     // the variable to something large before the section was read-only.
     WriterData::writers = 0;
     CHECK(SetProtectedSectionReadOnly());
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_ANDROID)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
     // Set the protected_memory_section_buffer to true to ensure the buffer
     // section is created. If a variable is declared but not used the memory
     // section won't be created.
