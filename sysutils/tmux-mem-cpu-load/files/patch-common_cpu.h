--- common/cpu.h.orig	2021-08-04 11:37:18 UTC
+++ common/cpu.h
@@ -45,7 +45,7 @@
 #endif
 
 float cpu_percentage( unsigned );
-uint32_t get_cpu_count();
+uint8_t get_cpu_count();
 
 /** CPU percentage output mode.
  *
