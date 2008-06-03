--- src/freebsd.c.orig	2008-05-26 11:23:57.000000000 -0400
+++ src/freebsd.c	2008-05-26 11:35:56.000000000 -0400
@@ -519,7 +519,7 @@ __inline__ unsigned long long int rdtsc(
 
 /* return system frequency in MHz (use divisor=1) or GHz (use divisor=1000) */
 void get_freq_dynamic(char *p_client_buffer, size_t client_buffer_size,
-		char *p_format, int divisor)
+		const char *p_format, int divisor)
 {
 #if  defined(__i386) || defined(__x86_64)
 	struct timezone tz;
@@ -549,7 +549,7 @@ void get_freq_dynamic(char *p_client_buf
 }
 
 /* void */
-char get_freq(char *p_client_buffer, size_t client_buffer_size, char *p_format,
+char get_freq(char *p_client_buffer, size_t client_buffer_size, const char *p_format,
 		int divisor, unsigned int cpu)
 {
 	int freq;
