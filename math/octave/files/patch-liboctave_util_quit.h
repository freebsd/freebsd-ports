--- liboctave/util/quit.h.orig	2025-03-29 19:33:33 UTC
+++ liboctave/util/quit.h
@@ -224,7 +224,7 @@ extern "C" {
 
 #if defined (__cplusplus)
 
-  extern OCTAVE_API std::atomic<int> octave_interrupt_state;
+  extern OCTAVE_API std::atomic<sig_atomic_t> octave_interrupt_state;
 
   extern OCTAVE_API std::atomic<bool> octave_signal_caught;
 
