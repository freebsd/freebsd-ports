--- src/mail.c.orig
+++ src/mail.c
@@ -61,6 +61,8 @@
 #define POP3_TYPE 1
 #define IMAP_TYPE 2
 
+#define MAXFOLDERSIZE 128
+
 struct mail_s {			// for imap and pop3
 	unsigned long unseen;
 	unsigned long messages;
@@ -74,7 +76,7 @@ struct mail_s {			// for imap and pop3
 	char user[128];
 	char pass[128];
 	char command[1024];
-	char folder[128];
+	char folder[MAXFOLDERSIZE];
 	timed_thread *p_timed_thread;
 	char secure;
 };
@@ -465,17 +467,20 @@ struct mail_s *parse_mail_args(char type, const char *arg)
 	if (type == IMAP_TYPE) {
 		tmp = strstr(arg, "-f ");
 		if (tmp) {
-			int len = 1024;
+			int len = MAXFOLDERSIZE-1;
 			tmp += 3;
 			if (tmp[0] == '\'') {
 				len = strstr(tmp + 1, "'") - tmp - 1;
-				if (len > 1024) {
-					len = 1024;
+				if (len > MAXFOLDERSIZE-1) {
+					len = MAXFOLDERSIZE-1;
 				}
+				tmp++;
 			}
-			strncpy(mail->folder, tmp + 1, len);
+			strncpy(mail->folder, tmp, len);
+			mail->folder[len-1] = 0;
 		} else {
-			strncpy(mail->folder, "INBOX", 128);	// default imap inbox
+			strncpy(mail->folder, "INBOX", MAXFOLDERSIZE-1);	// default imap inbox
+			mail->folder[MAXFOLDERSIZE-1] = 0;
 		}
 	}
 	tmp = strstr(arg, "-e ");
