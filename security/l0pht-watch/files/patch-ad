--- list_utils.c.orig	Thu Dec 24 00:00:44 1998
+++ list_utils.c	Sun Aug 13 23:55:23 2000
@@ -102,9 +102,11 @@
   char filemodes[11];
   char outputStr[(MAXNAMLEN * 2) + 256];
   char linkbuf[MAXNAMLEN + 1];
+  struct winsize winsize;
   struct passwd *pwent;
   struct group *groupent;
   int ret;
+  unsigned short width;
 
   switch(action){
     case ADDITION:
@@ -143,11 +145,16 @@
 
   getfilemodes(&list->statbuf, filemodes);
 
+  if (ioctl(1, TIOCGWINSZ, &winsize) == 0)
+    width = winsize.ws_col;
+  else
+    width = 80;
+
   sprintf(outputStr,"%.2s %-11.20s %-2d %-8.20s %-8.20s %-6ld %-10.20s "
-                    "%.20s",
+                    "%.*s",
           (action == ADDITION) ? "+ " : "- ", filemodes, 
           (int)list->statbuf.st_nlink, username, groupname,
-          (long)list->statbuf.st_size, timehold, list->filename);
+          (long)list->statbuf.st_size, timehold, width - 60, list->filename);
 
   if (S_ISLNK(list->statbuf.st_mode) ){
     ret = readlink(list->filename, linkbuf, sizeof(linkbuf));
@@ -168,7 +175,7 @@
 
   
 
-#ifdef 0
+#if 0
   printf("%-11s %-2d %-8s %-8s %-6ld %-10s %-10s\n", filemodes,
           (int)list->statbuf.st_nlink, username, groupname, 
           list->statbuf.st_size, timehold, list->filename);
