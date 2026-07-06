--- onnxruntime/core/common/spin_pause.cc.orig	2026-06-12 15:12:02 UTC
+++ onnxruntime/core/common/spin_pause.cc
@@ -34,7 +34,7 @@ void SpinPause() {
     !defined(__APPLE__)
 
   static const bool has_tpause = CPUIDInfo::GetCPUIDInfo().HasTPAUSE();
-  static constexpr uint64_t tpause_spin_delay_cycles = 1000;
+  //static constexpr uint64_t tpause_spin_delay_cycles = 1000; // unused variable error breaking the build
   if (has_tpause) {
 #if defined(_WIN32) || defined(__WAITPKG__)
     _tpause(0x0, __rdtsc() + tpause_spin_delay_cycles);
