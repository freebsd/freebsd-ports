--- agpg.c	2002-09-28 07:16:01.000000000 +0000
+++ agpg.c	2005-02-21 21:49:21.466050839 +0000
@@ -100,11 +100,13 @@
   if (id)
     free(buf);
   while ((len = getline(&line, &size, gpg)) > 0) {
-    if (len > 10 && !strncmp(line, "sec ", 4) && line[10] == '/') {
-      char *x;
-      if ((x = strchr(line + 11, ' ')) != NULL) {
-	*x = 0;
-	id = strdup(line + 11);
+#define GPG_SECKEYS_DELIM " \t/"
+    if (strncmp(line, "sec ", 4) == 0 &&
+      strtok(line, GPG_SECKEYS_DELIM) &&
+      strtok(NULL, GPG_SECKEYS_DELIM)) {
+    char *x;
+  if ((x = strtok(NULL, GPG_SECKEYS_DELIM)) != NULL) {
+    id = strdup(x);
 	free(line);
 	pclose(gpg);
 	return id;
