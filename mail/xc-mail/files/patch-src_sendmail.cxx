--- src/sendmail.cxx.orig	Wed Aug 17 10:22:27 2005
+++ src/sendmail.cxx	Wed Aug 17 10:22:37 2005
@@ -796,7 +796,7 @@
 static indicator *spool_indi=NULL;
 static char 	 spool_txtbuf[150]="";
 
-static void spstatus(char *t,int v=0)
+static void spstatus(char *t,int v)
 {
 	if (spool_indi)
 	{
