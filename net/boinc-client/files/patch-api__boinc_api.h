--- api/boinc_api.h.orig	2012-04-13 09:59:23.000000000 +0200
+++ api/boinc_api.h	2012-06-06 14:40:16.000000000 +0200
@@ -83,7 +83,6 @@
 
 extern int boinc_init(void);
 extern int boinc_finish(int status);
-extern int boinc_temporary_exit(int delay, const char* reason=NULL);
 extern int boinc_get_init_data_p(struct APP_INIT_DATA*);
 extern int boinc_parse_init_data_file(void);
 extern int boinc_send_trickle_up(char* variety, char* text);
@@ -139,6 +138,7 @@
     double cpu_time, double checkpoint_cpu_time, double _fraction_done,
     int other_pid, double bytes_sent, double bytes_received
 );
+extern int boinc_temporary_exit(int delay, const char* reason=NULL);
 
 /////////// API ENDS HERE
 
