--- src/output-plugins/spo_syslog_full.c.orig	2018-10-06 12:59:49 UTC
+++ src/output-plugins/spo_syslog_full.c
@@ -1711,7 +1711,7 @@ OpSyslog_Data *OpSyslog_ParseArgs(char *
 int UDPConnect(OpSyslog_Data *op_data) 
 {
     
-    if( (op_data == NULL))
+    if (op_data == NULL)
     {
 	/* XXX */
 	return 1;
