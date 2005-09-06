--- plugins/dateresend/dateresend.cxx.orig	Wed Aug 17 10:09:32 2005
+++ plugins/dateresend/dateresend.cxx	Wed Aug 17 10:10:28 2005
@@ -47,7 +47,7 @@
 			addmenu(4,"Resend in 1 week");
 	}
 }
-void dateresend::resendmail(int mode,char *datestr=NULL)
+void dateresend::resendmail(int mode,char *datestr)
 {
 	int size;
 	char *body=sm->ml->mailbody(size,1);
@@ -379,7 +379,7 @@
 		addmenu(MPMENU_GENERAL,1,"Send me @ date...");
 	}
 }
-void datesender::sendmail(char *subject,char *body,char *datestr=NULL)
+void datesender::sendmail(char *subject,char *body,char *datestr)
 {
 	int size;
 	createmail *cm=new createmail;
