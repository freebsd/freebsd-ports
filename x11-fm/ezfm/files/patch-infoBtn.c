--- infoBtn.c.orig	1998-11-16 06:02:59.000000000 +0100
+++ infoBtn.c	2007-12-07 00:09:30.000000000 +0100
@@ -214,7 +214,7 @@
 	  if(chmod(ptr->pathname, ptr->mode) != 0)
 	    {
 	      char *err= (errno >= 0 && errno <sys_nerr)? 
-		sys_errlist[errno] : "Unknown error";
+		(char *)sys_errlist[errno] : "Unknown error";
 	      ezfmWarning("chmod() failed due to the following error", err);
 	      haserr++;
 	    }
@@ -245,7 +245,7 @@
 		if(chown(ptr->pathname, pswd->pw_uid, grp->gr_gid) != 0)
 		  {
 		    char *err= (errno >= 0 && errno <sys_nerr)? 
-		      sys_errlist[errno] : "Unknown error";
+		      (char *)sys_errlist[errno] : "Unknown error";
 		    ezfmWarning("chown() failed due to the following error", err);
 		    haserr++;
 		  }
@@ -260,7 +260,7 @@
 	    if(rename(ptr->pathname, nname) < 0)
 	      {
 		char *err= (errno >= 0 && errno <sys_nerr)? 
-		  sys_errlist[errno] : "Unknown error";
+		  (char *)sys_errlist[errno] : "Unknown error";
 		ezfmWarning("rename() failed due to the following error", err);
 		haserr++;	      
 	      }
@@ -290,7 +290,7 @@
     }
 }
 /**************************************************************************/
-static void setmode(widget, data)  EZ_Widget *widget; void *data; 
+static void _setmode(widget, data)  EZ_Widget *widget; void *data; 
 {
   char str[12];
   infoControl *ptr = (infoControl *)data;
@@ -347,7 +347,7 @@
 			       EZ_GRID_CELL_GEOMETRY,  2, idx , 1, 1,
 			       EZ_CLIENT_INT_DATA,     rr,
 			       EZ_CLIENT_PTR_DATA,     clabel,
-			       EZ_CALLBACK,            setmode, data,
+			       EZ_CALLBACK,            _setmode, data,
 			       NULL);
   label =      EZ_CreateWidget(EZ_WIDGET_CHECK_BUTTON, tframe,
 			       EZ_LABEL_STRING,        "write",
@@ -358,7 +358,7 @@
 			       EZ_CLIENT_INT_DATA,     ww,
 			       EZ_CLIENT_PTR_DATA,     clabel,
 			       EZ_GRID_CELL_GEOMETRY,  3, idx , 1, 1, 
-			       EZ_CALLBACK,            setmode, data,
+			       EZ_CALLBACK,            _setmode, data,
 			       NULL);
   label =      EZ_CreateWidget(EZ_WIDGET_CHECK_BUTTON, tframe,
 			       EZ_LABEL_STRING,        "execute",
@@ -369,7 +369,7 @@
 			       EZ_CLIENT_PTR_DATA,     clabel,
 			       EZ_CHECK_BUTTON_ON_OFF,  xx&mode,
 			       EZ_GRID_CELL_GEOMETRY,  4, idx , 1, 1, 
-			       EZ_CALLBACK,            setmode, data,
+			       EZ_CALLBACK,            _setmode, data,
 			       NULL);
 }
 
