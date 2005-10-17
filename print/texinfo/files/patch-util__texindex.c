--- util/texindex.c.orig	Mon Oct 17 21:41:08 2005
+++ util/texindex.c	Mon Oct 17 21:41:52 2005
@@ -390,7 +390,9 @@
 maketempname (int count)
 {
   static char *tempbase = NULL;
+  char *tempname;
   char tempsuffix[10];
+  int fd;
 
   if (!tempbase)
     {
@@ -403,7 +405,12 @@
     }
 
   sprintf (tempsuffix, ".%d", count);
-  return concat (tempbase, tempsuffix);
+  tempname = concat (tempbase, tempsuffix);
+  fd = open (tempname, O_CREAT|O_EXCL|O_WRONLY, 0600);
+  if (fd == -1)
+    pfatal_with_name (tempname);
+  close (fd);
+  return tempname;
 }
 
 
