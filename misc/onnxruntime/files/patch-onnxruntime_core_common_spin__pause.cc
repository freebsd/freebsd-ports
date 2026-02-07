--- onnxruntime/core/common/spin_pause.cc.orig	2025-11-10 18:42:26 UTC
+++ onnxruntime/core/common/spin_pause.cc
@@ -30,7 +30,7 @@ void SpinPause() {
     !defined(__APPLE__)
 
   static const bool has_tpause = CPUIDInfo::GetCPUIDInfo().HasTPAUSE();
-  static constexpr uint64_t tpause_spin_delay_cycles = 1000;
+  //static constexpr uint64_t tpause_spin_delay_cycles = 1000; // unused variable error breaking the build
   if (has_tpause) {
 #if defined(_WIN32)
     _tpause(0x0, __rdtsc() + tpause_spin_delay_cycles);
