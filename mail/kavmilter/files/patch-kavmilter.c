--- kavmilter.c.orig	Fri Jul 18 12:24:16 2003
+++ kavmilter.c	Fri Jul 18 12:24:43 2003
@@ -402,8 +402,7 @@
 
   if (smfi_setconn(_KAV_milter_config.sendmail_pipe) == MI_FAILURE)
     {
-      syslog(LOG_ERR,"Set connection port (smfi_setconn) failed,
-      					port %s",_KAV_milter_config.sendmail_pipe);
+      syslog(LOG_ERR,"Set connection port (smfi_setconn) failed, port %s",_KAV_milter_config.sendmail_pipe);
       _KAV_milter_close(EX_SOFTWARE);
     }
 
