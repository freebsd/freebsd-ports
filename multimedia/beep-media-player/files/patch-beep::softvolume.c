--- beep/softvolume.c.orig	Sat Feb  7 18:18:57 2004
+++ beep/softvolume.c	Sat Feb  7 18:20:03 2004
@@ -27,11 +27,12 @@
 void soft_volume_load(char *section, SoftVolumeConfig * c)
 {
     ConfigFile *cfgfile;
+	char *sec;
 
     if (c == NULL)
 	return;
 
-    char *sec = (section == NULL ? "xmms" : section);
+    sec = (section == NULL ? "xmms" : section);
 
     c->enabled = FALSE;
     c->volume_left = 0;
