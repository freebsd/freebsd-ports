--- xferstats.x	Thu Jan 11 19:49:22 2001
+++ xferstats.c	Thu Jan 11 19:50:31 2001
@@ -2486,6 +2486,7 @@
 {
   pointers_t * pointers;
   char * default_logfile;
+  int first = 1;
 
   /* unbuffer stdout and stderr so output isn't lost */
   setbuf(stdout, NULL);
@@ -2559,10 +2560,11 @@
 
     G_BLOW_CHUNKS();
 
-    if (!pointers->first_ftp_line) {
+    if (first && !pointers->first_ftp_line) {
       fprintf(stderr, "No data to process.\n");
       exit(0);
     }
+    first = 0;
 
     generate_daily_data(pointers, pointers->first_ftp_line);
     if (pointers->config->dow_traffic)
