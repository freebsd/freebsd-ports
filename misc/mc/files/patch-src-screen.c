--- src/screen.c.orig	Wed Jan 29 04:58:22 2003
+++ src/screen.c	Tue Jun 15 03:22:46 2004
@@ -672,7 +672,7 @@
 	int  len;
 
 	link = concat_dir_and_file (panel->cwd, panel->dir.list [panel->selected].fname);
-	len = mc_readlink (link, link_target, MC_MAXPATHLEN);
+	len = mc_readlink (link, link_target, MC_MAXPATHLEN - 1);
 	g_free (link);
 	if (len > 0){
 	    link_target[len] = 0;
@@ -1045,7 +1045,7 @@
     int  spaces, extra;
     int  side, width;
 
-    char *txt, buffer[30]; /*Hope that this is enough ;-) */
+    char *txt;
     if (!panel->split)
 	adjust_top_file (panel);
 
@@ -1071,18 +1071,14 @@
                 txt = format->title;
 
 		header_len = strlen (txt);
-		if (header_len > format->field_len){
-		    strcpy (buffer, txt);
-		    txt = buffer;
-		    txt [format->field_len] = 0;
-		    header_len = strlen (txt);
-		}
+		if (header_len > format->field_len)
+		    header_len = format->field_len;
 
                 attrset (MARKED_COLOR);
                 spaces = (format->field_len - header_len) / 2;
                 extra  = (format->field_len - header_len) % 2;
-		printw ("%*s%-s%*s", spaces, "",
-			 txt, spaces+extra, "");
+		printw ("%*s%.*s%*s", spaces, "",
+			 header_len, txt, spaces+extra, "");
 		width -= 2 * spaces + extra + header_len;
 	    } else {
 		attrset (NORMAL_COLOR);
@@ -2021,7 +2017,7 @@
 	int i;
 	struct stat mybuf;
 
-	i = readlink (selection (panel)->fname, buffer, MC_MAXPATHLEN);
+	i = readlink (selection (panel)->fname, buffer, MC_MAXPATHLEN - 1);
 	if (i < 0)
 	    return;
 	if (mc_stat (selection (panel)->fname, &mybuf) < 0)
