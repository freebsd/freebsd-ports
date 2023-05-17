--- src/freebsd.cc.orig	2023-05-15 21:39:11 UTC
+++ src/freebsd.cc
@@ -544,14 +544,12 @@ char get_freq(char *p_client_buffer, size_t client_buf
 char get_freq(char *p_client_buffer, size_t client_buffer_size,
               const char *p_format, int divisor, unsigned int cpu) {
   int freq;
-  char *freq_sysctl;
+  char freq_sysctl[16] = {0};
 
   if (!p_client_buffer || client_buffer_size <= 0 || !p_format ||
       divisor <= 0) {
     return 0;
   }
-
-  char freq_sysctl[16] = {0};
 
   snprintf(freq_sysctl, sizeof(freq_sysctl), "dev.cpu.%d.freq", (cpu - 1));
 
