--- opt.c.orig	Wed Nov 19 19:01:47 2003
+++ opt.c	Wed Nov 19 19:01:47 2003
@@ -192,8 +192,8 @@
 {
 
 char *options=
-"	[-clsyvV] [-d dirname] [-f rcfile] [-t N] 
-	[-T timeout] [-w M ] [-pPY filter] [-x command]
+"	[-clsyvV] [-d dirname] [-f rcfile] [-t N]\n\
+	[-T timeout] [-w M ] [-pPY filter] [-x command]\n\
 ";	
 		fprintf(stderr,"Usage: %s nntp_server [options]\n", prog_name);
 		fprintf(stderr,"Options:\n%s\n",options);
