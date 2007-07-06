--- utils.h.orig	Mon Nov 27 06:21:58 2006
+++ utils.h	Sat Apr 28 13:45:23 2007
@@ -19,7 +19,7 @@
 void * mymalloc(int size, char *what);
 void * myrealloc(void *oldp, int newsize, char *what);
 char * mystrdup(char *in);
-char * mtstrndup(char *in, int len);
+char * mystrndup(char *in, int len);
 void myfree(void *p, char *what);
 ssize_t WRITE(int fd, char *whereto, size_t len);
 int get_filesize(char *filename);
