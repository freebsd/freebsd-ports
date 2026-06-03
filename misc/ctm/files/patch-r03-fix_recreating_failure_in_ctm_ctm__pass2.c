--- ctm/ctm_pass2.c.ORI	2023-12-29 08:41:10.082775000 +0100
+++ ctm/ctm_pass2.c	2023-12-29 08:43:18.156987000 +0100
@@ -15,6 +15,8 @@
 #include "ctm.h"
 #define BADREAD 32
 
+char LastRemoved[ PATH_MAX + 1 ] = "";
+
 /*---------------------------------------------------------------------------*/
 /* Pass2 -- Validate the incoming CTM-file.
  */
@@ -86,6 +88,11 @@
 	    switch (j & CTM_F_MASK) {
 		case CTM_F_Name:
 		    GETNAMECOPY(name,sep,j,0);
+
+		    /* If we remove anything, record its name */
+		    if( strcmp(sp->Key,"FR") == 0 || strcmp(sp->Key,"DR") == 0 || strcmp(sp->Key,"LR") == 0 )
+		      strncpy( LastRemoved, name, sizeof LastRemoved -1 );
+
 		    /* If `keep' was specified, we won't remove any files,
 		       so don't check if the file exists */
 		    if (KeepIt &&
@@ -104,6 +111,11 @@
 
 		    /* XXX Check DR DM rec's for parent-dir */
 		    if(j & CTM_Q_Name_New) {
+
+			/* Don't check for existence of the new item if it had
+			   been removed just before. */
+			if( strcmp( LastRemoved, name ) != 0 )
+
 			/* XXX Check DR FR rec's for item */
 			if(-1 != stat(name,&st)) {
 			    fprintf(stderr,"  %s: %s exists.\n",
