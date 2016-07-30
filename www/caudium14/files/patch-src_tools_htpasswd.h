--- src/tools/htpasswd.h.orig	2011-09-15 05:13:13 UTC
+++ src/tools/htpasswd.h
@@ -2,7 +2,7 @@
 #define HTPASSWD_H
 char *strd(char *s);
 void getword(char *word, char *line, char stop);
-int getline(char *s, int n, FILE *f);
+int get_line(char *s, int n, FILE *f);
 void putline(FILE *f,char *l);
 void to64(register char *s, register long v, register int n);
 void add_password(char *user, FILE *f);
