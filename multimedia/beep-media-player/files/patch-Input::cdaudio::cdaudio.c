--- Input/cdaudio/cdaudio.c.orig	Fri Nov 14 05:38:50 2003
+++ Input/cdaudio/cdaudio.c	Fri Nov 14 05:39:31 2003
@@ -695,10 +695,11 @@
 struct driveinfo* cdda_find_drive(char *filename)
 {
 	GList *node;
+	struct driveinfo *d;
 	
 	// FIXME: Will always return the first drive
 	node = cdda_cfg.drives;
-	struct driveinfo *d = node->data;
+	d = node->data;
 
 	for (node = cdda_cfg.drives; node; node = node->next)
 	{
