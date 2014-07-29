--- transparent.c.orig	Fri Aug 29 17:47:44 2003
+++ transparent.c	Fri Aug 29 17:48:01 2003
@@ -417,9 +417,9 @@ void makeDialogue()
 }
 /********************************************************************************/
 static char *transparentResource = 
-"
-*tileOrigin: 2 0 0
-*fileIcon.labeledIcon: 3
+"\n\
+*tileOrigin: 2 0 0\n\
+*fileIcon.labeledIcon: 3\n\
 "
 ;
 /********************************************************************************/
@@ -535,7 +535,7 @@ void ezfmPopupWarning(lab1, lab2, lab3, 
   }
 }
 /***************************************************************************/  
-static setroot(obj, data, scale)
+static void setroot(obj, data, scale)
      void *obj, *data; int scale;
 {
   FileInfo *finfo = (FileInfo *)data;
