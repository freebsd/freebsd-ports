--- src/wtools.c.orig	Thu Nov 14 13:25:19 2002
+++ src/wtools.c	Tue Jun 15 03:15:09 2004
@@ -412,8 +412,7 @@
 /* we need a unique name for tkname because widget.c:history_tool()
    needs a unique name for each dialog - using the header is ideal */
 
-    strncpy (tk_name + 3, header, 60);
-    tk_name[63] = '\0';
+    g_strlcpy (tk_name + 3, header, 61);
     quick_widgets[2].tkname = tk_name;
 
     len = max (strlen (header), msglen (text, &lines)) + 4;
