--- src/e2_task_backend.c	Mon May  8 11:10:01 2006
+++ src/e2_task_backend.c.orig	Mon May  8 11:06:53 2006
@@ -573,7 +573,7 @@
 			return FALSE;
 		}
 
-		blksize_t buf_size = dest_sb.st_blksize;  //or src ??
+		__int32_t buf_size = dest_sb.st_blksize;  //or src ??
 		gchar *buf = g_alloca (buf_size);
 		//CHECKME suspend access-monitoirng here ...
 		for (;;)
