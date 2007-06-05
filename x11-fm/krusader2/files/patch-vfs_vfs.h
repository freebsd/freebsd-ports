--- krusader/VFS/vfs.h.orig	Sat Oct  8 22:48:24 2005
+++ krusader/VFS/vfs.h	Sun May 27 21:40:25 2007
@@ -134,7 +134,7 @@
 
 protected:
 	/// Feel the vfs dictionary with vfiles, must be implemented for each vfs
-	virtual bool populateVfsList(const KURL& origin, bool showHidden) = 0L;
+	virtual bool populateVfsList(const KURL& origin, bool showHidden) = 0;
 	/// Set the vfile list pointer
 	void setVfsFilesP(vfileDict* dict);
 	/// clear and delete all current vfiles

--Boundary-00=_8WeWGysQhMJYgoy--
