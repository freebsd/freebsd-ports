--- FileList/FileList.xs.orig	Thu Jul 24 04:33:37 2003
+++ FileList/FileList.xs	Mon Jan 12 10:27:51 2004
@@ -93,8 +93,9 @@
 PROTOTYPES: DISABLE
 
 File::RsyncP::FileList
-new(packname = "File::RsyncP::FileList", SV* opts = NULL)
+new(packname = "File::RsyncP::FileList", opts = NULL)
 	char *packname
+	SV* opts
     CODE:
     {
         RETVAL = flist_new();
@@ -187,14 +188,14 @@
         if ( file->sum )
             hv_store(rh, "sum",      3, newSVpv(file->sum, 0), 0);
         hv_store(rh, "name",    4, newSVpv(f_name(file), 0), 0);
-        hv_store(rh, "uid",     3, newSVuv(file->uid), 0);
-        hv_store(rh, "gid",     3, newSVuv(file->gid), 0);
-        hv_store(rh, "mode",    4, newSVuv(file->mode), 0);
-        hv_store(rh, "mtime",   5, newSVuv(file->modtime), 0);
+        hv_store(rh, "uid",     3, newSViv(file->uid), 0);
+        hv_store(rh, "gid",     3, newSViv(file->gid), 0);
+        hv_store(rh, "mode",    4, newSViv(file->mode), 0);
+        hv_store(rh, "mtime",   5, newSViv(file->modtime), 0);
         hv_store(rh, "size",    4, newSVnv(file->length), 0);
         hv_store(rh, "dev",     3, newSVnv(file->dev), 0);
         hv_store(rh, "inode",   5, newSVnv(file->inode), 0);
-        hv_store(rh, "rdev",    4, newSVuv(file->rdev), 0);
+        hv_store(rh, "rdev",    4, newSViv(file->rdev), 0);
         RETVAL = newRV((SV*)rh);
     }
     OUTPUT:
@@ -210,9 +211,10 @@
     }
 
 void
-encode(flist, SV* data)
+encode(flist, data)
     INPUT:
 	File::RsyncP::FileList	flist
+	SV* data
     CODE:
     {
         struct file_struct file, *fileCopy;
