--- test/fakesmtp.c.orig	2023-12-04 03:00:44 UTC
+++ test/fakesmtp.c
@@ -35,13 +35,12 @@ enum {
 	SMTP_XOAUTH_ERR
 };
 
-static ssize_t getsmtp(int, char *);
+static int getsmtp(int, char *);
 
 int
 main(int argc, char *argv[])
 {
-	ssize_t rc;
-	int conn, smtp_state;
+	int rc, conn, smtp_state;
 	FILE *f;
 	const char *xoauth = getenv("XOAUTH");
 	const char *smtputf8 = getenv("SMTPUTF8");
@@ -74,8 +73,8 @@ main(int argc, char *argv[])
 		if (rc == -1)
 			break;	/* EOF */
 
-		fwrite(line, rc, 1, f);
-		fwrite("\n", 1, 1, f);
+                fputs(line, f);
+                putc('\n', f);
 
 		switch (smtp_state) {
 		case SMTP_DATA:
