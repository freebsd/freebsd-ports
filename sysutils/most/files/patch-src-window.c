--- src/window.c.orig	Sat Jul  2 05:04:58 2005
+++ src/window.c	Thu Sep 15 14:18:26 2005
@@ -238,7 +238,7 @@
 
 int most_read_from_minibuffer(char *prompt, char *what, unsigned int buflen)
 {
-   int i = 0;
+   int i = 1;
    char *buf;
    unsigned int len;
 
