--- plugins/e2p_crypt.c.orig	2007-11-22 22:23:11.000000000 +0100
+++ plugins/e2p_crypt.c	2008-04-03 15:45:48.000000000 +0200
@@ -1545,7 +1545,7 @@
 	{
 		sep = strchr (execpath, ':');	//ascii scan ok
 		if (sep != NULL)
-			execpath = strndup (execpath, sep-execpath);
+			execpath = g_strndup (execpath, sep-execpath);
 		//FIXME preserve execpath so that later members can be used
 	}
 #ifdef E2_VFS
@@ -1849,7 +1849,7 @@
 		}
 	}
 
-	fdatasync (fdesc);
+	fsync (fdesc);
 
 	retval = TRUE;
 cleanup:
