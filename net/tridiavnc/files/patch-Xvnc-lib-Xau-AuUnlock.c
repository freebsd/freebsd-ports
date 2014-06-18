--- Xvnc/lib/Xau/AuUnlock.c.orig	2000-04-12 11:18:27.000000000 -0700
+++ Xvnc/lib/Xau/AuUnlock.c	2013-10-30 23:24:19.000000000 -0700
@@ -44,7 +44,7 @@
     char	link_name[1025];
 
     if (strlen (file_name) > 1022)
-	return;
+	return(0);
 #ifndef WIN32
     (void) strcpy (creat_name, file_name);
     (void) strcat (creat_name, "-c");
