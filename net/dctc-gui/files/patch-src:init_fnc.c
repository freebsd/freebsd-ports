--- src/init_fnc.c.orig	Sat Nov 24 07:23:17 2001
+++ src/init_fnc.c	Sat Nov 24 16:37:43 2001
@@ -1,3 +1,11 @@
+#ifdef HAVE_CONFIG_H
+#  include <config.h>
+#endif
+
+#ifdef HAVE_SYS_PARAM_H
+#  include <sys/param.h>
+#endif
+
 #include <stdio.h>
 #include <stdlib.h>
 #include <unistd.h>
@@ -7,11 +15,17 @@
 #include <math.h>
 #include <sys/types.h>
 #include <sys/stat.h>
-#include <linux/sem.h>		/* for the value of SEMVMX */
+#if !(defined(BSD) && (BSD >= 199103))  /* Not BSD */
+#  include <linux/sem.h>		/* for the value of SEMVMX */
+#endif
 #include <dirent.h>
 #include <string.h>
 #include <gnome.h>
 
+#ifndef SEMVMX
+#define SEMVMX	32767
+#endif
+
 #include "misc_gtk.h"
 #include "init_fnc.h"
 #include "main.h"
@@ -411,7 +425,7 @@
 		gtk_clist_freeze(GTK_CLIST(rhcw));
 		gtk_clist_clear(GTK_CLIST(rhcw));
 
-		f=popen("hublist","r");
+		f=popen("dc_hublist","r");
 		if(f!=NULL)
 		{
 			char *ent[4];
