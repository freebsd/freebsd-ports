Index: source/smbd/filename.c
===================================================================
--- smbd/filename.c	(revision 842)
+++ smbd/filename.c	(working copy)
@@ -137,6 +137,10 @@
 	if (!*name) {
 		name[0] = '.';
 		name[1] = '\0';
+		if (SMB_VFS_STAT(conn,name,&st) == 0) {
+			*pst = st;
+		}
+		DEBUG(5,("conversion finished %s -> %s\n",orig_path, name));
 		return(True);
 	}
 
