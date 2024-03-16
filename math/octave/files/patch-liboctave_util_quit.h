--- liboctave/util/quit.h.orig	2024-03-16 19:30:09 UTC
+++ liboctave/util/quit.h
@@ -224,7 +224,7 @@ octave_exception
 
 #if defined (__cplusplus)
 
-extern OCTAVE_API std::atomic<int> octave_interrupt_state;
+extern OCTAVE_API std::atomic<sig_atomic_t> octave_interrupt_state;
 
 extern OCTAVE_API volatile std::atomic<bool> octave_signal_caught;
 
