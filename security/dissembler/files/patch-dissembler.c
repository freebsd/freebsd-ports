--- dissembler.c.orig	Wed Mar 19 04:21:37 2003
+++ dissembler.c	Sun Mar 13 14:45:45 2005
@@ -21,6 +21,8 @@
 #include <ctype.h>
 #include <time.h>
 #include <stdlib.h>
+#include <string.h>
+#include <unistd.h>
 
 #define VERSION "0.9"
 #define CHR "%_01234567890abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ-"
@@ -29,6 +31,29 @@
 void usage(char *);
 void banner();
 char *gen(unsigned int, unsigned int, char *);
+char *strfry(char *);
+
+
+char *strfry(char *string) {
+  int len, a, b;
+  int init = 0;
+  char c;
+
+  if (!init) {
+      srand(time((time_t *)NULL));
+      init = 1;
+  }
+
+  len = strlen (string);
+  for (a = 0; a < len; ++a) {
+      b = rand () % len;
+      c = string[a];
+      string[a] = string[b];
+      string[b] = c;
+  }
+
+  return string;
+}
 
 int main(int argc, char* argv[])
 {
@@ -214,8 +239,9 @@
 			fprintf(fh, "P");
 	}
 	fprintf(fh,"\n");
-	if(fh != stdout) close(fh);
+	if(fh != stdout) fclose(fh);
 	free(mem-21);
+	return 0;
 }
 
 void banner()
