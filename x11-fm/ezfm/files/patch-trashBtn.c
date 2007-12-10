--- trashBtn.c.orig	2007-12-07 00:11:13.000000000 +0100
+++ trashBtn.c	2007-12-07 00:11:21.000000000 +0100
@@ -173,7 +173,7 @@
   else
     {
       char *err = (errno >= 0 && errno <sys_nerr)? 
-	sys_errlist[errno] : "Unknown error";
+	(char *)sys_errlist[errno] : "Unknown error";
       ezfmWarning("Error Deleting File", err);
     }
 }
