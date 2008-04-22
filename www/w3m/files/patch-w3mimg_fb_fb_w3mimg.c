--- w3mimg/fb/fb_w3mimg.c.orig	Wed Aug  4 17:32:28 2004
+++ w3mimg/fb/fb_w3mimg.c	Mon Dec  3 10:42:23 2007
@@ -153,10 +153,15 @@
 	return 0;
     if (strncmp(tty, "/dev/", 5) == 0)
 	tty += 5;
+#if defined(__linux__)
     if (strncmp(tty, "tty", 3) == 0 && isdigit(*(tty + 3)))
 	return 1;
     if (strncmp(tty, "vc/", 3) == 0 && isdigit(*(tty + 3)))
 	return 1;
+#elif defined(__FreeBSD__)
+    if (strncmp(tty, "ttyv", 4) == 0 && isxdigit(*(tty + 4)))
+	return 1;
+#endif
     return 0;
 }
 #else
@@ -172,7 +177,9 @@
 	return NULL;
     memset(wop, 0, sizeof(w3mimg_op));
 
-    if (!check_tty_console(getenv("W3M_TTY")) && strcmp("jfbterm", getenv("TERM")) != 0) {
+    if (!check_tty_console(getenv("W3M_TTY")) &&
+	strcmp("jfbterm", getenv("TERM")) != 0 &&
+	strncmp("jfbterm-", getenv("TERM"), 8) != 0) {
 	fprintf(stderr, "w3mimgdisplay/fb: tty is not console\n");
 	goto error;
     }
