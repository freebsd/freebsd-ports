--- vdelivermail.c.orig	Mon Oct 20 20:59:57 2003
+++ vdelivermail.c	Sat Nov  1 11:21:15 2003
@@ -62,6 +62,7 @@
 #define FILE_SIZE 156
 char hostname[FILE_SIZE];
 char loop_buf[FILE_SIZE];
+char spam_buf[FILE_SIZE];
 
 #define MSG_BUF_SIZE 5000
 char msgbuf[MSG_BUF_SIZE];
@@ -90,6 +91,10 @@
 void usernotfound(void);
 int is_loop_match( char *dt, char *address);
 int deliver_quota_warning(const char *dir, const char *q);
+#ifdef SPAM_THRESHOLD
+int is_spam(int threshold);
+int is_spam_match(char *xsl, int threshold);
+#endif
 
 static char local_file[156];
 static char local_file_new[156];
@@ -257,7 +262,7 @@
 
     /* check for wildcard if there's no match */
     if(tmpstr == NULL) {
-        for(i=strlen(TheUser);i >= 0 && j != 1;--i) {
+        for(i=strlen(TheUser);i > 0 && j != 1;--i) {
             if(TheUser[i-1]=='-') {
                 tmpuser[0] = '\0';
                 strncat(tmpuser,TheUser,i); 
@@ -444,6 +449,7 @@
  int inject = 0;
  FILE *fs;
  char tmp_file[256];
+ int pim[2];
 
     /* check if the email is looping to this user */
     if ( is_looping( address ) == 1 ) {
@@ -631,6 +637,51 @@
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
+                    while ((file_count = read(0, msgbuf, MSG_BUF_SIZE)) > 0)
+                        write(1, msgbuf, file_count);
+                    _exit(0);
+                }
+        }
+        close(pim[1]);
+        dup2(pim[0], 0);
+        close(pim[0]);
+    }
+#ifdef SPAM_THRESHOLD
+    /* silently delete message if spam level > SPAM_THRESHOLD */
+    if (is_spam(SPAM_THRESHOLD) == 1) {
+        close(write_fd);
+        if (unlink(local_file) != 0) {
+            printf("unlink failed %s errno = %d\n", local_file, errno);
+            return(errno);
+        }
+        return(0);
+    }
+
+#ifdef MAKE_SEEKABLE
+    if (!Seekable(0))
+        MakeSeekable(stdin);
+#endif
+
+    if (lseek(0, 0L, SEEK_SET) < 0) {
+        printf("lseek errno=%d\n", errno);
+        return(errno);
+    }
+#endif
+#endif
 
     /* read it in chunks and write it to the new file */
     while((file_count=read(0,msgbuf,MSG_BUF_SIZE))>0) {
@@ -881,6 +932,9 @@
         if (strncmp(loop_buf, "Delivered-To: ", 14) == 0 &&
             is_loop_match(loop_buf, address)==1 ) {
 
+            /* seek to the end of stdin */
+            fseek(stdin, 0L, SEEK_END);
+
             /* return the loop found */
             return(1);
 
@@ -919,6 +973,8 @@
              * looping not found value
             */
             if ( found == 0 ) {
+                /* seek to the end of stdin */
+                fseek(stdin, 0L, SEEK_END);
                 /* return not found looping message value */
                 return(0);
             }
@@ -1335,3 +1391,96 @@
    return(1);
 }
 
+#ifdef SPAM_THRESHOLD
+/* Check for a spam message
+ * This is done by checking for a matching line
+ * in the email headers for X-Spam-Level: which
+ * we put in each spam email
+ *
+ * Return 1 if spam
+ * Return 0 if not spam
+ * Return -1 on error
+ */
+int is_spam(int threshold)
+{
+ int i;
+ int found;
+
+#ifdef MAKE_SEEKABLE
+    if (!Seekable(0))
+        MakeSeekable(stdin);
+#endif
+
+    if ( lseek(0, 0L, SEEK_SET) < 0 ) {
+        printf("lseek errno=%d\n", errno);
+        return(errno);
+    }
+
+    while (fgets(spam_buf, sizeof(spam_buf), stdin) != NULL){
+
+        /* if we find the line, return error (looping) */
+        if (strncmp(spam_buf, "X-Spam-Level: ", 14) == 0 &&
+            is_spam_match(spam_buf, threshold) ==1) {
+
+            /* seek to the end of stdin */
+            fseek(stdin, 0L, SEEK_END);
+
+            /* return the spam found */
+            return(1);
+
+            /* check for the start of the body, we only need
+            * to check the headers.
+            */
+        } else {
+
+            /* walk through the charaters in the body */
+            for (i = 0, found = 0; spam_buf[i] != 0 && found == 0; ++i) {
+                switch(spam_buf[i]) {
+
+                    /* skip blank spaces and new lines */
+                    case ' ':
+                    case '\n':
+                    case '\t':
+                    case '\r':
+                        break;
+
+                    /* found a non blank, so we are still
+                    * in the headers
+                    */
+                    default:
+
+                        /* set the found non blank char flag */
+                        found = 1;
+                        break;
+                }
+            }
+
+            /* if the line only had blanks, then it is the
+             * delimiting line between the headers and the
+             * body. We don't need to check the body for
+             * the X-Spam-Level: line. Hence, we
+             * are done with our search and can return the
+             * spam not found value
+            */
+            if (found == 0) {
+                /* seek to the end of stdin */
+                fseek(stdin, 0L, SEEK_END);
+                /* return not found spam message value */
+                return(0);
+            }
+        }
+    }
+
+    /* if we get here then the there is either no body
+     * or the logic above failed and we scanned
+     * the whole email, headers and body.
+     */
+    return(0);
+}
+
+int is_spam_match(char *xsl, int threshold)
+{
+    if (strlen(xsl) - strlen("X-Spam-Level: ") > threshold) return(1);
+    else return(0);
+}
+#endif
