--- src/window.c.orig	Tue Feb 22 17:19:49 2005
+++ src/window.c	Wed Jul  6 13:54:14 2005
@@ -238,7 +238,7 @@
 
 int most_read_from_minibuffer(char *prompt, char *what, unsigned int buflen)
 {
-   int i;
+   int i = 0;
    char *buf;
    unsigned int len;
 
