--- config.h.orig
+++ config.h
@@ -1,6 +1,6 @@
-#if defined (__FreeBSD__) || defined (__OpenBSD__)
+#if defined (__OpenBSD__)
 
-/* Our only FreeBSD driver, this goes straight into kernel memory 
+/* Our only OpenBSD driver(old FreeBSD-4.x driver), this goes straight into kernel memory 
  * and reads the raw structures from right underneath the kernel using the
  * kvm library.  This made the code a require a little more thought, but 
  * the end result is a statistics driver thats faster than the linux ones 
@@ -12,7 +12,11 @@
 
 #endif
 
+#if defined (__FreeBSD__)
 
+#define USE_SYSCTL
+
+#endif
 
 #ifdef linux
 
