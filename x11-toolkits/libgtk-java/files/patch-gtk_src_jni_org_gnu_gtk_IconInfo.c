--- gtk/src/jni/org_gnu_gtk_IconInfo.c.orig	Thu Feb 19 14:18:04 2004
+++ gtk/src/jni/org_gnu_gtk_IconInfo.c	Thu Feb 19 14:18:54 2004
@@ -129,12 +129,13 @@
 	GdkPoint** point = g_malloc(sizeof(GdkPoint*) * (gint)numPoints);
 	jint* elements = (*env)->GetIntArrayElements(env, points, NULL);
 	int index;
+	gint gNumPoints = (gint)numPoints;
 	
 	for (index = 0; index < (gint)numPoints; index++)
 	{
 		point[index] = (GdkPoint*)elements[index];
 	}
-	return gtk_icon_info_get_attach_points((GtkIconInfo*)info, point, &(gint)numPoints);
+	return gtk_icon_info_get_attach_points((GtkIconInfo*)info, point, &gNumPoints);
 }
 
 /*
