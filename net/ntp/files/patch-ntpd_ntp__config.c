Index: ntpd/ntp_config.c
===================================================================
--- ntpd/ntp_config.c	(revision 359675)
+++ ntpd/ntp_config.c	(revision 359676)
@@ -202,6 +202,8 @@
 
 extern char *stats_drift_file;	/* name of the driftfile */
 
+psl_item psl[17-3+1];
+
 #ifdef BC_LIST_FRAMEWORK_NOT_YET_USED
 /*
  * backwards compatibility flags
