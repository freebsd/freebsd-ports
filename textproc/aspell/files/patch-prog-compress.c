--- prog/compress.c.orig	Sat Aug 31 20:51:11 2002
+++ prog/compress.c	Sat Jun 19 16:10:04 2004
@@ -28,6 +28,11 @@
 
 #endif
 
+#define WORD_BUFF_SIZE 256
+
+int count = 0;
+
+
 void usage () 
 {
   fputs("Compresses or uncompresses sorted word lists.\n"     , stderr);
@@ -45,8 +50,9 @@
   if (c == EOF) return 0;
   do {
     *w++ = (char)(c);
-  } while (c = getc(in), c != EOF && c > 32);
+  } while (c = getc(in), c != EOF && c > 32 && count < (WORD_BUFF_SIZE - 1));
   *w = '\0';
+  count++;
   ungetc(c, in);
   if (c == EOF) return 0;
   else return 1;
@@ -61,8 +67,8 @@
     
   } else if (argv[1][0] == 'c') {
 
-    char s1[256];
-    char s2[256];
+    char s1[WORD_BUFF_SIZE];
+    char s2[WORD_BUFF_SIZE];
     char * prev = s2;
     char * cur = s1;
     *prev = '\0';
@@ -69,6 +75,7 @@
 
     SETBIN (stdout);
 
+	while (count < WORD_BUFF_SIZE) {
     while (get_word(stdin, cur)) {
       int i = 0;
       /* get the length of the prefix */
@@ -85,11 +92,12 @@
 	prev = s2; cur = s1;
       }
     }
+	}
     return 0;
 
   } else if (argv[1][0] == 'd') {
     
-    char cur[256];
+    char cur[WORD_BUFF_SIZE];
     int i;
     int c;
 
@@ -100,8 +108,11 @@
       if (i == 0)
 	i = getc(stdin);
       --i;  
-      while ((c = getc(stdin)) > 32)
+      while ((c = getc(stdin)) > 32 && i < (WORD_BUFF_SIZE -1)) {
 	cur[i++] = (char)c;
+	count++;
+	}
+
       cur[i] = '\0';
       fputs(cur, stdout);
       putc('\n', stdout);
