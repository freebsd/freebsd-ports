--- src/profile.c.orig	Mon Jan 20 20:33:02 2003
+++ src/profile.c	Tue Jun 15 03:15:09 2004
@@ -325,8 +325,7 @@
     
     s = GetSetProfileChar (set, AppName, KeyName, Default, FileName);
     if (!set){
-	ReturnedString [Size-1] = 0;
-	strncpy (ReturnedString, s, Size-1);
+	g_strlcpy (ReturnedString, s, Size);
    }
     return 1;
 }
