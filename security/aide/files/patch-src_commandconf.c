--- src/commandconf.c.orig	2022-01-19 12:03:06.000000000 -0800
+++ src/commandconf.c	2022-01-23 14:49:37.915576000 -0800
@@ -226,8 +226,8 @@
       c=fgetc(db->fp);
       if(c==(unsigned char)'\213'){
     log_msg(LOG_LEVEL_DEBUG,"db_input_wrapper(): handle gzip header");
-    lseek(fileno(db->fp),0L,SEEK_SET);
-    db->gzp=gzdopen(fileno(db->fp),"rb");
+    lseek(fileno((FILE *)(db->fp)),0L,SEEK_SET);
+    db->gzp=gzdopen(fileno((FILE *)(db->fp)),"rb");
     c=gzgetc(db->gzp);
     log_msg(LOG_LEVEL_DEBUG, "db_input_wrapper(): first character after gzip header is: %c(%#X)\n",c,c);
   if(c==-1) {
