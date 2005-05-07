--- mail.c.orig	Fri May  6 10:47:22 2005
+++ mail.c	Fri May  6 19:17:15 2005
@@ -12,30 +12,26 @@
 static double last_mail_update;
 
 void update_mail_count() {
-  struct stat buf;
+  struct stat sbuf;
 
   if (current_mail_spool == NULL) return;
 
   /* TODO: use that fine file modification notify on Linux 2.4 */
 
-  /* don't check mail so often (9.5s is minimum interval) */
-  if (current_update_time - last_mail_update < 9.5)
+  /* don't check mail so often (5.5s is minimum interval) */
+  if (current_update_time - last_mail_update < 5.5)
     return;
   else
     last_mail_update = current_update_time;
 
-  if (stat(current_mail_spool, &buf)) {
-    static int rep;
-    if (!rep) {
+  if (stat(current_mail_spool, &sbuf) == -1) {
       ERR("can't stat %s: %s", current_mail_spool, strerror(errno));
-      rep = 1;
-    }
-    return;
+      return;
   }
 
 #if HAVE_DIRENT_H
   /* maildir format */
-	if (S_ISDIR(buf.st_mode)){
+	if (S_ISDIR(sbuf.st_mode)){
 		DIR *dir;
 		char *dirname;
 		struct dirent *dirent;
@@ -95,7 +91,7 @@
 	/* mbox format */
 
 
-  if (buf.st_mtime != last_mail_mtime) {
+  if (sbuf.st_ctime != last_mail_mtime) {
     /* yippee, modification time has changed, let's read mail count! */
     static int rep;
     FILE *fp;
@@ -127,7 +123,6 @@
             reading_status = 1;
         }
       }
-      else {
         if (reading_status && strncmp(buf, "X-Mozilla-Status:", 17) == 0) {
           /* check that mail isn't already read */
           if (strchr(buf+21, '0'))
@@ -144,7 +139,6 @@
           reading_status = 0;
           continue;
         }
-      }
 
       /* skip until \n */
       while (strchr(buf, '\n') == NULL && !feof(fp))
@@ -155,7 +149,7 @@
 
     if (reading_status) info.new_mail_count++;
 
-    last_mail_mtime = buf.st_mtime;
+    last_mail_mtime = sbuf.st_mtime;
   }
 }
 
--------------------- patch -----------------------------


