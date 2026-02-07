--- list_utils.c.orig	1998-12-24 05:00:44 UTC
+++ list_utils.c
@@ -1,3 +1,5 @@
+#include <string.h>
+
 #include "check_tmp.h"
 
 static void printnode(struct listStruct *, int);
@@ -102,9 +104,11 @@ printnode(struct listStruct *list, int action){
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
@@ -143,11 +147,16 @@ printnode(struct listStruct *list, int action){
 
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
@@ -168,7 +177,7 @@ printnode(struct listStruct *list, int action){
 
   
 
-#ifdef 0
+#if 0
   printf("%-11s %-2d %-8s %-8s %-6ld %-10s %-10s\n", filemodes,
           (int)list->statbuf.st_nlink, username, groupname, 
           list->statbuf.st_size, timehold, list->filename);
