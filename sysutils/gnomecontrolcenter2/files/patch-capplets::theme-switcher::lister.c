
$FreeBSD$

--- capplets/theme-switcher/lister.c	2002/03/29 12:43:59	1.1
+++ capplets/theme-switcher/lister.c	2002/03/29 12:45:18
@@ -115,8 +115,7 @@
   char *errstring = NULL;
   int out_fd;
 #ifndef HAVE_GETLINE
-  char line[1024];
-  char *lineptr = line;
+  char *lineptr = (char *)malloc(1024);
 #else
   char *lineptr = NULL;
 #endif
