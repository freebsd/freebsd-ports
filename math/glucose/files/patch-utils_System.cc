--- utils/System.cc.orig	2018-02-01 09:11:32 UTC
+++ utils/System.cc
@@ -78,7 +78,7 @@ double Glucose::memUsed(void) {
     struct rusage ru;
     getrusage(RUSAGE_SELF, &ru);
     return (double)ru.ru_maxrss / 1024; }
-double MiniSat::memUsedPeak(void) { return memUsed(); }
+//double MiniSat::memUsedPeak(void) { return memUsed(); }
 
 
 #elif defined(__APPLE__)
