--- ssmtp.c.orig	Sat Nov  8 18:51:19 2003
+++ ssmtp.c	Sat Nov  8 19:01:07 2003
@@ -14,6 +14,7 @@
 */
 #define VERSION "2.60.4"
 
+#include <sys/types.h>
 #include <sys/socket.h>
 #include <netinet/in.h>
 #include <sys/param.h>
@@ -366,9 +367,36 @@
 {
 	char buf[(BUF_SZ + 1)], *p;
 	FILE *fp;
-
+#ifdef USERPREFS
+	char *file=NULL;
+	if (pw->pw_dir != NULL) {
+		file = (char *)malloc (strlen (pw->pw_dir) + 1 + strlen (".ssmtprc") + 1);
+		sprintf (file, "%s/.ssmtprc", pw->pw_dir);
+	}
+
+	if ((file != NULL) && (fp = fopen(file, "r")) ) {
+		while(fgets(buf, sizeof(buf), fp)) {
+				/* Make comments invisible */
+				if((p = strchr(buf, '#'))) {
+					*p = (char)NULL;
+				}
+
+			/* Ignore malformed lines and comments */
+				if(strchr(buf, '@') == (char *)NULL) {
+					continue;
+				}
+				if((p = strtok(buf, "\n"))) {
+                                        if((uad = strdup(p)) == (char *)NULL) {
+                                                die("revaliases() -- strdup() failed");
+                                        }
+				}
+			}
+		fclose(fp);
 	/* Try to open the reverse aliases file */
-	if((fp = fopen(REVALIASES_FILE, "r"))) {
+	} else if ((fp = fopen(REVALIASES_FILE, "r"))) {
+#else
+	if ((fp = fopen(REVALIASES_FILE, "r"))) {
+#endif
 		/* Search if a reverse alias is defined for the sender */
 		while(fgets(buf, sizeof(buf), fp)) {
 			/* Make comments invisible */
