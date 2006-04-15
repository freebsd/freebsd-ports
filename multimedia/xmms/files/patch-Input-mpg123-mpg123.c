--- Input/mpg123/mpg123.c.orig	Tue Feb 28 16:56:08 2006
+++ Input/mpg123/mpg123.c	Tue Feb 28 16:57:40 2006
@@ -397,6 +397,8 @@
 			if (!strncasecmp(ext, ".rm", 3) || 
 			    !strncasecmp(ext, ".ra", 3)  ||
 			    !strncasecmp(ext, ".rpm", 4)  ||
+			    !strncasecmp(ext, ".fla", 4) ||
+			    !strncasecmp(ext, ".flac", 5) ||
 			    !strncasecmp(ext, ".ram", 4))
 				return FALSE;
 		}
