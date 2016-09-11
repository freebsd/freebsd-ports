--- ./i7z.c.orig	2012-09-11 08:15:54.000000000 +0200
+++ ./i7z.c	2012-12-11 14:41:28.000000000 +0100
@@ -184,11 +184,11 @@
 {
     //below when just logging
     if(prog_options.logging==1) {
-        fprintf(fp_log_file_freq,"%d.%.9d\n",value->tv_sec,value->tv_nsec); //newline, replace \n with \t to get everything separated with tabs
+        fprintf(fp_log_file_freq,"%jd.%.9ld\n",(intmax_t)value->tv_sec,value->tv_nsec); //newline, replace \n with \t to get everything separated with tabs
     }
     //below when appending
     if(prog_options.logging==2) {
-        fprintf(fp_log_file_freq,"%d.%.9d\t",value->tv_sec,value->tv_nsec);
+        fprintf(fp_log_file_freq,"%jd.%.9ld\t",(intmax_t)value->tv_sec,value->tv_nsec);
     }
 }
 
@@ -264,20 +264,20 @@
     if(socket_num==0){
         //below when just logging
         if(prog_options.logging==1)
-            fprintf(fp_log_file_freq_1,"%d.%.9d\n",value->tv_sec,value->tv_nsec); //newline, replace \n with \t to get everything separated with tabs
+            fprintf(fp_log_file_freq_1,"%jd.%.9ld\n",(intmax_t)value->tv_sec,value->tv_nsec); //newline, replace \n with \t to get everything separated with tabs
 
         //below when appending
         if(prog_options.logging==2)
-             fprintf(fp_log_file_freq_1,"%d.%.9d\t",value->tv_sec,value->tv_nsec);
+             fprintf(fp_log_file_freq_1,"%jd.%.9ld\t",(intmax_t)value->tv_sec,value->tv_nsec);
     }
     if(socket_num==1){
         //below when just logging
         if(prog_options.logging==1)
-            fprintf(fp_log_file_freq_2,"%d.%.9d\n",value->tv_sec,value->tv_nsec); //newline, replace \n with \t to get everything separated with tabs
+            fprintf(fp_log_file_freq_2,"%jd.%.9ld\n",(intmax_t)value->tv_sec,value->tv_nsec); //newline, replace \n with \t to get everything separated with tabs
 
         //below when appending
         if(prog_options.logging==2)
-             fprintf(fp_log_file_freq_2,"%d.%.9d\t",value->tv_sec,value->tv_nsec);
+             fprintf(fp_log_file_freq_2,"%jd.%.9ld\t",(intmax_t)value->tv_sec,value->tv_nsec);
     }
 }
 
@@ -315,7 +315,7 @@
 {
     //below when just logging
     if(prog_options.logging != 0) {
-        fprintf(fp_log_file_Cstates,"%d.%.9d",value->tv_sec,value->tv_nsec); //newline, replace \n with \t to get everything separated with tabs
+        fprintf(fp_log_file_Cstates,"%jd.%.9ld",(intmax_t)value->tv_sec,value->tv_nsec); //newline, replace \n with \t to get everything separated with tabs
     }
 }
 
@@ -366,12 +366,12 @@
     if(socket_num==0){
         //below when just logging
         if(prog_options.logging != 0)
-            fprintf(fp_log_file_Cstates_1,"%d.%.9d",value->tv_sec,value->tv_nsec); //newline, replace \n with \t to get everything separated with tabs    
+            fprintf(fp_log_file_Cstates_1,"%jd.%.9ld",(intmax_t)value->tv_sec,value->tv_nsec); //newline, replace \n with \t to get everything separated with tabs    
     }
     if(socket_num==1){
         //below when just logging
         if(prog_options.logging != 0)
-            fprintf(fp_log_file_Cstates_2,"%d.%.9d",value->tv_sec,value->tv_nsec); //newline, replace \n with \t to get everything separated with tabs
+            fprintf(fp_log_file_Cstates_2,"%jd.%.9ld",(intmax_t)value->tv_sec,value->tv_nsec); //newline, replace \n with \t to get everything separated with tabs
     }
 }
 
@@ -386,7 +386,11 @@
 
 void modprobing_msr()
 {
+#ifdef __linux__
     system("modprobe msr");
+#elif __FreeBSD__
+    system("kldload cpuctl");
+#endif
 }
 
 //Info: I start from index 1 when i talk about cores on CPU
