--- gui/wm/ws.c.orig	2015-11-18 16:16:39 UTC
+++ gui/wm/ws.c
@@ -193,8 +193,18 @@ void wsInit(Display *display)
         int localdisp  = 1;
 
         if (dispname && *dispname != ':') {
-            localdisp = 0;
-            wsUseXShm = False;
+            // check [Bug 206050] x11/slim: force use unix sockets
+            //localdisp = 0;
+            //wsUseXShm = False;
+            const char *udspfx = "unix:";
+            size_t strsz = strlen(udspfx);
+            char substr[strsz];
+            strncpy(substr, dispname, strsz);
+            substr[strsz] = '\0';
+            if(strcmp(substr, udspfx) != 0) {
+                localdisp = 0;
+                wsUseXShm = False;
+            }
         }
 
         mp_msg(MSGT_GPLAYER, MSGL_DBG2, "[ws] display name: %s => %s display.\n", dispname, localdisp ? "local" : "REMOTE");
