--- ./src/augrun.c.orig	2012-02-11 04:26:33.948339055 -0500
+++ ./src/augrun.c	2012-02-11 04:29:28.090339060 -0500
@@ -988,6 +988,16 @@
     &cmd_def_last
 };
 
+char *strchrnul(const char *s, int c) {
+  char *i;
+  for (i = (char*)s; *i != '\0'; ++i) {
+    if (*i == c) {
+      return i;
+    }
+  }
+  return i;
+}
+
 int aug_srun(augeas *aug, FILE *out, const char *text) {
     char *line = NULL;
     const char *eol;
