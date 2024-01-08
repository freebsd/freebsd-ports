--- third_party/libvpx/source/libvpx/vpx_ports/aarch64_cpudetect.c.orig	2024-01-08 12:52:53 UTC
+++ third_party/libvpx/source/libvpx/vpx_ports/aarch64_cpudetect.c
@@ -153,7 +153,16 @@ static int arm_get_cpu_caps(void) {
   return flags;
 }
 
-#else  // end __Fuchsia__
+#elif defined(__FreeBSD__)  // end __Fuchsia__
+
+int arm_get_cpu_caps(void) {
+  int flags = 0;
+#if HAVE_NEON
+  flags |= HAS_NEON;  // Neon is mandatory in Armv8.0-A.
+#endif  // HAVE_NEON
+  return flags;
+}
+#else  // end __FreeBSD__
 #error \
     "Runtime CPU detection selected, but no CPU detection method available" \
 "for your platform. Rerun configure with --disable-runtime-cpu-detect."
