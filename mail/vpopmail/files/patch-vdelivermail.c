--- vdelivermail.c.orig	Mon Oct 20 20:59:57 2003
+++ vdelivermail.c	Fri Oct 24 18:31:45 2003
@@ -257,7 +257,7 @@
 
     /* check for wildcard if there's no match */
     if(tmpstr == NULL) {
-        for(i=strlen(TheUser);i >= 0 && j != 1;--i) {
+        for(i=strlen(TheUser);i > 0 && j != 1;--i) {
             if(TheUser[i-1]=='-') {
                 tmpuser[0] = '\0';
                 strncat(tmpuser,TheUser,i); 
@@ -444,6 +444,7 @@
  int inject = 0;
  FILE *fs;
  char tmp_file[256];
+ int pim[2];
 
     /* check if the email is looping to this user */
     if ( is_looping( address ) == 1 ) {
@@ -631,6 +632,30 @@
         }
     }
 
+#ifdef SPAMC
+    /* fork the SpamAssassin client - patch by Alex Dupre */
+    if (!pipe(pim)) {
+        pid = vfork();
+        switch (pid) {
+            case -1:
+                close(pim[0]);
+                close(pim[1]);
+                break;
+            case 0:
+                close(pim[0]);
+                dup2(pim[1], 1);
+                close(pim[1]);
+                if (execl(SPAMC, SPAMC, "-u", maildir_to_email(address), 0) == -1) {
+                    while ((file_count=read(0, msgbuf, MSG_BUF_SIZE)) > 0)
+                        write(1, msgbuf, file_count);
+                    _exit(0);
+                }
+        }
+        close(pim[1]);
+        dup2(pim[0], 0);
+        close(pim[0]);
+    }
+#endif
 
     /* read it in chunks and write it to the new file */
     while((file_count=read(0,msgbuf,MSG_BUF_SIZE))>0) {
