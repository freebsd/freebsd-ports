--- chrome/renderer/renderer_main_platform_delegate_linux.cc.orig	2011-03-20 22:02:04.353053389 +0200
+++ chrome/renderer/renderer_main_platform_delegate_linux.cc	2011-03-20 22:02:04.476736985 +0200
@@ -36,7 +36,7 @@
   // The seccomp sandbox is started in the renderer.
   // http://code.google.com/p/seccompsandbox/
 #if defined(ARCH_CPU_X86_FAMILY) && !defined(CHROMIUM_SELINUX) && \
-    !defined(__clang__)
+    !defined(__clang__) && !defined(OS_FREEBSD)
   // N.b. SupportsSeccompSandbox() returns a cached result, as we already
   // called it earlier in the zygote. Thus, it is OK for us to not pass in
   // a file descriptor for "/proc".
