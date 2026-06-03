--- ctm_smail/ctm_smail.c.ORI	2023-04-25 21:04:20.000000000 +0200
+++ ctm_smail/ctm_smail.c	2019-07-29 03:53:20.090358000 +0200
@@ -32,18 +32,18 @@
 #define LINE_LENGTH	72	/* Chars per encoded line. Divisible by 4. */
 
 int chop_and_send_or_queue(FILE *dfp, char *delta, off_t ctm_size,
-	long max_msg_size, char *mail_alias, char *queue_dir);
+	long max_msg_size, char *mail_alias, char *owner_alias, char *queue_dir);
 int chop_and_send(FILE *dfp, char *delta, long msg_size, int npieces,
-	char *mail_alias);
+	char *mail_alias, char *owner_alias);
 int chop_and_queue(FILE *dfp, char *delta, long msg_size, int npieces,
-	char *mail_alias, char *queue_dir);
+	char *mail_alias, char *owner_alias, char *queue_dir);
 void clean_up_queue(char *queue_dir);
 int encode_body(FILE *sm_fp, FILE *delta_fp, long msg_size, unsigned *sum);
-void write_header(FILE *sfp, char *mail_alias, char *delta, int pce,
+void write_header(FILE *sfp, char *mail_alias, char *owner_alias, char *delta, int pce,
 	int npieces);
 void write_trailer(FILE *sfp, unsigned sum);
 int apologise(char *delta, off_t ctm_size, long max_ctm_size,
-	char *mail_alias, char *queue_dir);
+	char *mail_alias, char *owner_alias, char *queue_dir);
 FILE *open_sendmail(void);
 int close_sendmail(FILE *fp);
 
@@ -53,6 +53,7 @@
     int status = 0;
     char *delta_file;
     char *mail_alias;
+    char *owner_alias = NULL;
     long max_msg_size = DEF_MAX_MSG;
     long max_ctm_size = 0;
     char *log_file = NULL;
@@ -63,11 +64,12 @@
 
     err_prog_name(argv[0]);
 
-    OPTIONS("[-l log] [-m maxmsgsize] [-c maxctmsize] [-q queuedir] ctm-delta mail-alias")
+    OPTIONS("[-l log] [-m maxmsgsize] [-c maxctmsize] [-q queuedir] [-o owner_alias] ctm-delta mail-alias")
 	NUMBER('m', max_msg_size)
 	NUMBER('c', max_ctm_size)
 	STRING('l', log_file)
 	STRING('q', queue_dir)
+	STRING('o', owner_alias)
     ENDOPTS
 
     if (argc != 3)
@@ -91,11 +93,11 @@
 	}
 
     if (max_ctm_size != 0 && sb.st_size > max_ctm_size)
-	status = apologise(delta, sb.st_size, max_ctm_size, mail_alias,
+	status = apologise(delta, sb.st_size, max_ctm_size, mail_alias, owner_alias,
 		queue_dir);
     else
 	status = chop_and_send_or_queue(dfp, delta, sb.st_size, max_msg_size,
-		mail_alias, queue_dir);
+		mail_alias, owner_alias, queue_dir);
 
     fclose(dfp);
 
@@ -109,7 +111,7 @@
  */
 int
 chop_and_send_or_queue(FILE *dfp, char *delta, off_t ctm_size,
-	long max_msg_size, char *mail_alias, char *queue_dir)
+	long max_msg_size, char *mail_alias, char *owner_alias, char *queue_dir)
     {
     int npieces;
     long msg_size;
@@ -133,10 +135,10 @@
 #undef howmany
 
     if (queue_dir == NULL)
-	status = chop_and_send(dfp, delta, msg_size, npieces, mail_alias);
+	status = chop_and_send(dfp, delta, msg_size, npieces, mail_alias, owner_alias);
     else
 	{
-	status = chop_and_queue(dfp, delta, msg_size, npieces, mail_alias,
+	status = chop_and_queue(dfp, delta, msg_size, npieces, mail_alias, owner_alias,
 		queue_dir);
 	if (status)
 	    clean_up_queue(queue_dir);
@@ -152,7 +154,7 @@
  */
 int
 chop_and_send(FILE *dfp, char *delta, long msg_size, int npieces,
-	char *mail_alias)
+	char *mail_alias, char *owner_alias)
     {
     int pce;
     FILE *sfp;
@@ -171,7 +173,7 @@
 	if ((sfp = open_sendmail()) == NULL)
 	    return 1;
 
-	write_header(sfp, mail_alias, delta, pce, npieces);
+	write_header(sfp, mail_alias, owner_alias, delta, pce, npieces);
 	read_error = encode_body(sfp, dfp, msg_size, &sum);
 	if (!read_error)
 	    write_trailer(sfp, sum);
@@ -204,7 +206,7 @@
  */
 int
 chop_and_queue(FILE *dfp, char *delta, long msg_size, int npieces,
-	char *mail_alias, char *queue_dir)
+	char *mail_alias, char *owner_alias, char *queue_dir)
     {
     int pce;
     FILE *qfp;
@@ -228,7 +230,7 @@
 	    return 1;
 	    }
 
-	write_header(qfp, mail_alias, delta, pce, npieces);
+	write_header(qfp, mail_alias, owner_alias, delta, pce, npieces);
 	if (encode_body(qfp, dfp, msg_size, &sum))
 	    return 1;
 	write_trailer(qfp, sum);
@@ -381,9 +383,12 @@
  * Write the mail header and data header.
  */
 void
-write_header(FILE *sfp, char *mail_alias, char *delta, int pce, int npieces)
+write_header(FILE *sfp, char *mail_alias, char *owner_alias, char *delta, int pce, int npieces)
     {
-    fprintf(sfp, "From: owner-%s\n", mail_alias);
+    if (owner_alias == NULL) 
+        fprintf(sfp, "From: owner-%s\n", mail_alias);
+    else
+        fprintf(sfp, "From: %s\n", owner_alias);
     fprintf(sfp, "To: %s\n", mail_alias);
     fprintf(sfp, "Subject: ctm-mail %s %d/%d\n\n", delta, pce, npieces);
 
@@ -406,7 +411,7 @@
  * Returns 0 on success, 1 on failure.
  */
 int
-apologise(char *delta, off_t ctm_size, long max_ctm_size, char *mail_alias,
+apologise(char *delta, off_t ctm_size, long max_ctm_size, char *mail_alias, char *owner_alias,
 	char *queue_dir)
     {
     FILE *sfp;
@@ -430,7 +435,10 @@
 	}
 
 
-    fprintf(sfp, "From: owner-%s\n", mail_alias);
+    if (owner_alias == NULL)
+        fprintf(sfp, "From: owner-%s\n", mail_alias);
+    else
+        fprintf(sfp, "From: %s\n", owner_alias);
     fprintf(sfp, "To: %s\n", mail_alias);
     fprintf(sfp, "Subject: ctm-notice %s\n\n", delta);
 
