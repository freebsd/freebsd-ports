diff -urN -x .svn ../../vendor/vpopmail/vchangepw.c ./vchangepw.c
--- ../../vendor/vpopmail/vchangepw.c	Wed Oct  4 13:19:16 2006
+++ ./vchangepw.c	Wed Oct  4 15:44:20 2006
@@ -35,7 +35,7 @@
 
 int main(void)
 {
-	int i;
+	int i, bad;
 	struct vqpasswd *vpw = NULL;
 	char Email[MAX_BUFF];
 	char User[MAX_BUFF];
@@ -53,9 +53,15 @@
 
 	fputs("Please enter the email address: ", stdout);
 
-	fgets(Email, sizeof(Email), stdin);
-	i = strlen(Email) - 1;
-	if (Email[i] != '\n') {
+	bad = 0;
+	if (fgets(Email, sizeof(Email), stdin) == NULL) {
+		bad = 1;
+	} else {
+		i = strlen(Email) - 1;
+		if (i < 0 || (Email[i] != '\n' && Email[i] != '\r'))
+			bad = 1;
+	}
+	if (bad) {
 		puts("Error: email address too long");
 		return 3;
 	}
