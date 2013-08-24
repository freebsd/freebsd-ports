--- folder.c.orig	2007-12-07 00:06:06.000000000 +0100
+++ folder.c	2007-12-07 00:06:26.000000000 +0100
@@ -883,8 +883,8 @@ Folder *createNewFolder(pathname, toplev
   EZ_Widget    *pframe, *tmp;
   int          type = (ftype == 0 ? defaultFolderType: ftype);
 
-  if(which != 0 && which != 1) return;
-  if(toplevel->folder[which] != NULL) return;
+  if(which != 0 && which != 1) return NULL;
+  if(toplevel->folder[which] != NULL) return NULL;
 
   folder= (Folder *)   EZ_Malloc(sizeof(Folder));
   finfo  = (FileInfo *) EZ_Malloc(sizeof(FileInfo));
@@ -2118,7 +2118,7 @@ static void renameEntryCb(entry, data) E
           else
             {
               char *err = (errno >= 0 && errno <sys_nerr)? 
-                sys_errlist[errno] : "Unknown error";
+                (char *)sys_errlist[errno] : "Unknown error";
               ezfmWarning("Rename File Failed", err);                
             }
         }
