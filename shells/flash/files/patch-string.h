--- string.h.orig	2001-11-03 18:09:21 UTC
+++ string.h
@@ -2,14 +2,13 @@
 #   define __STRING_H
 
 #include <ctype.h>
-#include <wchar.h>
 
 #define CR '\n'
 #define TAB '\t'
 
 char *readline(FILE *fp);
 char *findline(char *start, int *foundend);
-int getline(const char *, char *);
+int get_line(const char *, char *);
 int substr(const char *, char *, char);
 int strtokenize(char *line, char delim, char **tokens, int maxtokens);
 char *stradp(char *filename);
