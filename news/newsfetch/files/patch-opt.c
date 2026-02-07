--- opt.c.orig	2016-06-20 15:59:53 UTC
+++ opt.c
@@ -192,8 +192,8 @@ opt_help(char *prog_name)
 {
 
 char *options=
-"	[-clsyvV] [-d dirname] [-f rcfile] [-t N] 
-	[-T timeout] [-w M ] [-pPY filter] [-x command]
+"	[-clsyvV] [-d dirname] [-f rcfile] [-t N]\n\
+	[-T timeout] [-w M ] [-pPY filter] [-x command]\n\
 ";	
 		fprintf(stderr,"Usage: %s nntp_server [options]\n", prog_name);
 		fprintf(stderr,"Options:\n%s\n",options);
