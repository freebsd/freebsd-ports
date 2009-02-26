--- wmwork.c.orig	2009-02-26 07:19:00.000000000 +0100
+++ wmwork.c	2009-02-26 07:22:35.000000000 +0100
@@ -590,9 +590,9 @@
 	p = first;
 	do {
 		if (F == stderr)
-			fprintf(F, "%s: > %s:%li:%s\n", PACKAGE_NAME, p->name, p->time, p->comment ? p->comment : "");
+			fprintf(F, "%s: > %s:%u:%s\n", PACKAGE_NAME, p->name, p->time, p->comment ? p->comment : "");
 		else
-			fprintf(F, "%s:%li:%s\n", p->name, p->time, p->comment ? p->comment : "");
+			fprintf(F, "%s:%u:%s\n", p->name, p->time, p->comment ? p->comment : "");
 		p = p->next;
 	} while (p != first);
 
@@ -614,7 +614,7 @@
 	if (sess_time == 0)
 		return 1;
 	strftime(tbuff, sizeof(tbuff), "%a, %d %b %Y %H:%M:%S %z", localtime(&now.tv_sec));
-	snprintf(rbuff, sizeof(rbuff), "%s %03li:%02li:%02li", tbuff, sess_time / 3600, sess_time / 60 % 60, sess_time % 60);
+	snprintf(rbuff, sizeof(rbuff), "%s %03i:%02i:%02i", tbuff, sess_time / 3600, sess_time / 60 % 60, sess_time % 60);
 
 	if ((fname = malloc(path_len)) == NULL) {
 		fprintf(stderr, "%s: cannot allocate memory for path variable\n", PACKAGE_NAME);
