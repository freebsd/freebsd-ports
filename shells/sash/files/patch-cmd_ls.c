--- cmd_ls.c.orig	Fri Sep  3 15:18:46 2004
+++ cmd_ls.c	Fri Sep  3 15:19:18 2004
@@ -380,7 +380,7 @@
 	 */
 	if (flags & LSF_INODE)
 	{
-		sprintf(cp, "%7ld ", statBuf->st_ino);
+		sprintf(cp, "%7d ", statBuf->st_ino);
 		cp += strlen(cp);
 	}
 
@@ -434,7 +434,7 @@
 				((unsigned long) statBuf->st_rdev) & 0xff);
 		}
 		else
-			sprintf(cp, "%8ld ", statBuf->st_size);
+			sprintf(cp, "%8lld ", statBuf->st_size);
 
 		cp += strlen(cp);
 
