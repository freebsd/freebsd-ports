--- src/utils.c.orig	Tue May 27 21:37:18 2003
+++ src/utils.c	Sun Dec 28 14:25:22 2003
@@ -366,6 +366,8 @@
 		
 	gulong divisor = 1;
 	gint type = 0;
+	gulong mod;
+	gulong nice;
 		
 	if (size >= 1000000){
 		divisor = 1000000;
@@ -375,8 +377,8 @@
 		type = 1;
 	}
 	
-	gulong mod = size % divisor;
-	gulong nice = size / divisor;
+	mod = size % divisor;
+	nice = size / divisor;
 	strcpy(format, (mod == 0)?"%.0f":"%.2f");
 	strcat(format, (nice == 1 && mod == 0?gettext(qtys[type][0]):gettext(qtys[type][1])));
 	return g_strdup_printf(format, (gfloat) size / divisor);
