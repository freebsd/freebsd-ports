--- pxr/base/arch/stackTrace.cpp.orig	2025-10-24 16:21:56 UTC
+++ pxr/base/arch/stackTrace.cpp
@@ -58,11 +58,11 @@
 /* Darwin/ppc did not do stack traces.  Darwin/i386 still 
    needs some work, this has been stubbed out for now.  */
 
-#if defined(ARCH_OS_LINUX)
+#if defined(ARCH_OS_LINUX) || defined(ARCH_OS_FREEBSD)
 #include <ucontext.h>
 #endif
 
-#if defined(ARCH_OS_LINUX) && defined(ARCH_BITS_64)
+#if defined(ARCH_OS_LINUX)  || defined(ARCH_OS_FREEBSD) && defined(ARCH_BITS_64)
 #include <unwind.h>
 #endif
 
@@ -93,7 +93,7 @@ ForkFunc Arch_nonLockingFork =
 // total hack -- no idea if this will work if we die in malloc...
 typedef int (*ForkFunc)(void);
 ForkFunc Arch_nonLockingFork =
-#if defined(ARCH_OS_LINUX)
+#if defined(ARCH_OS_LINUX) || defined(ARCH_OS_FREEBSD)
     (ForkFunc)dlsym(RTLD_DEFAULT, "_Fork");
 #elif defined(ARCH_OS_DARWIN) || defined(ARCH_OS_WASM_VM)
     NULL;
@@ -626,7 +626,7 @@ nonLockingFork()
 }
 #endif
 
-#if defined(ARCH_OS_LINUX)
+#if defined(ARCH_OS_LINUX) || defined(ARCH_OS_FREEBSD)
 static int
 nonLockingLinux__execve (const char *file,
                          char *const argv[],
@@ -1392,7 +1392,7 @@ ArchGetStackFrames(size_t maxDepth, size_t skip, vecto
     frames->resize(ArchGetStackFrames(maxDepth, skip, frames->data()));
 }
 
-#if defined(ARCH_OS_LINUX) && defined(ARCH_BITS_64)
+#if defined(ARCH_OS_LINUX) || defined(ARCH_OS_FREEBSD) && defined(ARCH_BITS_64)
 struct Arch_UnwindContext {
 public:
     Arch_UnwindContext(size_t maxdepth, size_t skip, uintptr_t* frames) :
