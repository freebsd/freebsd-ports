Description: SpamAssassin support, build optimization
 Add SpamAssassin support.
 Drop the unneeded MAX_ENV_BUFF definition.
 Add DELIVER_TO_STDOUT support
Forwarded: not-needed
Author: Alex Dupre <ale@FreeBSD.org>,
	Peter Pentchev <roam@FreeBSD.org>,
	Bryan Drewery <bdrewery@FreeBSD.org>
Last-Update: 2013-07-23

--- vdelivermail.c.orig	2010-11-08 09:02:52.000000000 -0600
+++ vdelivermail.c	2013-07-23 10:44:11.392127088 -0500
@@ -74,6 +74,7 @@
 int is_spam();
 #endif
 int  DeleteMail = 0;
+int  MoveMail = 0;
 int  local = 1;
 
 #define MSG_BUF_SIZE 5000
@@ -353,7 +354,6 @@
 
 int fdcopy (int write_fd, int read_fd, const char *extra_headers, size_t headerlen, char *address)
 {
-  char msgbuf[4096];
   ssize_t file_count;
   struct vlimits limits;
 #ifdef SPAMASSASSIN
@@ -393,7 +393,7 @@
             close(pim[1]);
             if (execl(SPAMC_PROG, SPAMC_PROG, "-f", "-u",
                  address, 0) == -1) {
-              while ((file_count = read(0, msgbuf, MSG_BUF_SIZE)) > 0) {
+              while ((file_count = read(0, msgbuf, sizeof(msgbuf))) > 0) {
                 write(1, msgbuf, file_count);
               }
               _exit(0);
@@ -421,18 +421,36 @@
     /* read it in chunks and write it to the new file */
     while ((file_count = read(read_fd, msgbuf, sizeof(msgbuf))) > 0) {
 #ifdef SPAMASSASSIN
-        if ( local==1 && InHeaders==1 &&
-             (limits.delete_spam==1 || vpw->pw_gid & DELETE_SPAM) ) {
-          printf("check is_spam\n");
-          if (is_spam(msgbuf) == 1) {
+        if ( local==1 && InHeaders==1
+#if defined(SPAM_THRESHOLD) || defined(SPAM_JUNKFOLDER)
+             ) {
+#else
+             && (limits.delete_spam==1 || vpw->pw_gid & DELETE_SPAM) ) {
+#endif
+          switch (is_spam(msgbuf, file_count)) {
+          case 2:
+#ifdef SPAM_THRESHOLD
             DeleteMail = 1;
             return(0);
+#endif
+          case 1:
+            if (limits.delete_spam==1 || vpw->pw_gid & DELETE_SPAM) {
+              DeleteMail = 1;
+              return(0);
+            }
+#ifdef SPAM_JUNKFOLDER
+            MoveMail = 1;
+#endif
           }
         }
 #endif
         if ( write(write_fd, msgbuf, file_count) == -1 ) return -1;
     }
-    
+#ifdef SPAMASSASSIN
+    /* No body */
+    if (InHeaders==1) DeleteMail = 1;
+#endif
+
     return 0;
 }
 
@@ -481,8 +499,8 @@
 int deliver_to_maildir (
     const char *maildir,
     const char *extra_headers,
-    int read_fd,
-    ssize_t msgsize)
+    int read_fd
+    )
 {
 #ifdef HOST_NAME_MAX
   char hostname[HOST_NAME_MAX];
@@ -493,21 +511,36 @@
   char local_file_tmp[FILE_SIZE];
   char local_file_new[FILE_SIZE];
   size_t headerlen;
+  struct stat sb;
+  size_t msgsize;
   int write_fd;
   char quota[80];
+#ifdef SPAM_JUNKFOLDER
+  struct stat mystatbuf;
+  char dir[MAX_BUFF];
+  char calling_dir[MAX_BUFF];
+#endif
 
     headerlen = strlen (extra_headers);
-    msgsize += headerlen;
     
+    if ((getenv("DELIVER_TO_STDOUT")) != NULL) {
+        if (fdcopy (1, read_fd, extra_headers, headerlen,
+                maildir_to_email(maildir)) != 0) {
+            printf("echo to stdout failed\n");
+            return -2;
+        } else{
+            /* Email sent to STDOUT */
+            return 0;
+        }
+    }
+
     /* Format the email file name */
     /* we get the whole hostname, even though we only use 32 chars of it */
     gethostname(hostname, sizeof(hostname));
     pid = (long unsigned) getpid();
     tm = (long unsigned) time((time_t *) NULL);
-    snprintf(local_file_tmp, sizeof(local_file_tmp), "%stmp/%lu.%lu.%.32s,S=%lu",
-        maildir, tm, pid, hostname, (long unsigned) msgsize);
-    snprintf(local_file_new, sizeof(local_file_new), "%snew/%lu.%lu.%.32s,S=%lu",
-        maildir, tm, pid, hostname, (long unsigned) msgsize);
+    snprintf(local_file_tmp, sizeof(local_file_tmp), "%stmp/%lu.%lu.%.32s",
+        maildir, tm, pid, hostname);
 
     read_quota_from_maildir (maildir, quota, sizeof(quota));
 
@@ -548,6 +581,9 @@
 #endif
         close (write_fd) == 0 ) {
 
+        if (stat(local_file_tmp, &sb) == -1)
+            DeleteMail = 1;
+
 	if(DeleteMail == 1) {
 	    if (unlink(local_file_tmp) != 0) {
                 printf("unlink failed %s errno = %d\n", local_file_tmp, errno);
@@ -556,7 +592,29 @@
             return(0);
 	}
 
+        msgsize = sb.st_size;
+        snprintf(local_file_new, sizeof(local_file_new), "%snew/%lu.%lu.%.32s,S=%lu",
+            maildir, tm, pid, hostname, (long unsigned) msgsize);
+
         /* if this succeeds link the file to the new directory */
+#ifdef SPAM_JUNKFOLDER
+        if (MoveMail == 1) {
+            snprintf(dir, sizeof(local_file_new), "%s/.Junk", maildir);
+            if (stat(dir, &mystatbuf) == -1) {
+                  /* record the dir where the vdelivermail command was run from */
+                  getcwd(calling_dir, sizeof(calling_dir));
+                  if (mkdir(dir,VPOPMAIL_DIR_MODE) == -1) { chdir(calling_dir); unlink(local_file_tmp); return(-2); }
+                  if (chdir(dir) == -1) { chdir(calling_dir); unlink(local_file_tmp); return(-2); }
+                  if (mkdir("cur",VPOPMAIL_DIR_MODE) == -1) { chdir(calling_dir); unlink(local_file_tmp); return(-2); }
+                  if (mkdir("new",VPOPMAIL_DIR_MODE) == -1) { chdir(calling_dir); unlink(local_file_tmp); return(-2); }
+                  if (mkdir("tmp",VPOPMAIL_DIR_MODE) == -1) { chdir(calling_dir); unlink(local_file_tmp); return(-2); }
+                  /* change back to the original dir */
+                  chdir(calling_dir);
+            }
+            snprintf(local_file_new, sizeof(local_file_new), "%s/.Junk/new/%lu.%lu.%.32s,S=%lu",
+                maildir, tm, pid, hostname, (long unsigned) msgsize);
+        }
+#endif
         if ( link( local_file_tmp, local_file_new ) == 0 ) {
             /* file was successfully delivered, remove temp file */
             if ( unlink(local_file_tmp) != 0 ) {
@@ -616,6 +674,9 @@
     /* rewind the message */
     lseek(0,0L,SEEK_SET);
 
+    /* reinitialize for each dot-qmail line */
+    DeleteMail = 0;
+
     /* This is an command */
     if ( *address == '|' ) { 
 
@@ -723,7 +784,7 @@
                 email);
         }
     
-        switch (deliver_to_maildir (address, DeliveredTo, 0, message_size)) {
+        switch (deliver_to_maildir (address, DeliveredTo, 0)) {
             case -1:
                 vexiterr (EXIT_OVERQUOTA, "user is over quota");
                 break;
@@ -898,9 +959,6 @@
  */
 void run_command(char *prog)
 {
-
-#define MAX_ENV_BUFF 100
-
  int child;
  char *(args[4]);
  int wstat;
@@ -1186,7 +1244,7 @@
             maildir_to_email(newdir), date_header());
     }
 
-    err = deliver_to_maildir (dir, DeliveredTo, read_fd, sb.st_size);
+    err = deliver_to_maildir (dir, DeliveredTo, read_fd);
 
     close (read_fd);
     
@@ -1214,19 +1272,22 @@
  *   * in the email headers for X-Spam-Level: which
  *    * we put in each spam email
  *     *
- *      * Return 1 if spam
+ *      * Return 2 if heavy spam
+ *      * Return 1 if light spam
  *       * Return 0 if not spam
  *        * Return -1 on error
  *         */
-int is_spam(char *spambuf)
+int is_spam(char *spambuf, int len)
 {
  int i,j,k;
  int found;
+ int spam = 0;
+ int rowlen;
 
-    for(i=0,j=0;spambuf[i]!=0;++i) {
+    for(i=0,j=0;i<len;++i) {
 
        /* found a line */
-       if (spambuf[i]=='\n' || spambuf[i]=='\r' ) {
+       if (spambuf[i]=='\n') {
 
          /* check for blank line, end of headers */
          for(k=j,found=0;k<i;++k) {
@@ -1249,13 +1310,19 @@
          }
          if ( found == 0 ) {
            InHeaders=0;
-           return(0);
+           return(spam);
          }
 
          /* still in the headers check for spam header */
-         if ( strncmp(&spambuf[j], "X-Spam-Flag: YES", 16 ) == 0 ) return(1);
+         rowlen = i - j;
+         if ( spam == 0 && rowlen == 16 && strncmp(&spambuf[j], "X-Spam-Flag: YES", 16 ) == 0 )
+           spam = 1;
+#ifdef SPAM_THRESHOLD
+         else if ( rowlen > 14 + SPAM_THRESHOLD && strncmp(&spambuf[j], "X-Spam-Level: ", 14 ) == 0 )
+	   return(2);
+#endif
 
-         if (spambuf[i+1]!=0) j=i+1;
+         j=i+1;
        }
      }
      return(0);
