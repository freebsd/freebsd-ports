--- etc/cnid_dbd/cmd_dbd_scanvol.c.orig	2014-03-18 17:42:49.000000000 -0400
+++ etc/cnid_dbd/cmd_dbd_scanvol.c	2014-03-18 17:43:31.000000000 -0400
@@ -616,7 +616,7 @@ static int check_orphaned(const char *na
     struct stat sb;
 
     if (strlen(name) < 3)
-        return;
+        return 0;
 
     rc = lstat(&name[2], &sb);
 
