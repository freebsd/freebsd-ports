--- src/data.c.orig	Thu Apr 10 21:59:12 2003
+++ src/data.c	Thu Apr 10 22:45:59 2003
@@ -171,6 +171,9 @@
 {
   if ( mount )
   {
+    char *c = strchr(mount->machine, '@');  // remove user name from smb name
+    if (c) 
+      memmove(mount->machine, c+1, strlen(c)+1);
     if ( mount_list_search_by_mountpoint(mount->mountpoint) == NULL )
     {
       mountlist = g_slist_append(mountlist, mount);
