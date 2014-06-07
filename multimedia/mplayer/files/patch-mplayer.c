--- mplayer.c.orig	2014-04-06 20:46:45.000000000 +0200
+++ mplayer.c	2014-06-07 14:40:43.756655422 +0200
@@ -3707,7 +3707,8 @@
         if (use_gui) {
             if (!gui(GUI_SET_VIDEO, mpctx->sh_video))
                 goto goto_next_file;
-            gui(GUI_SET_AUDIO, mpctx->sh_audio);
+            if (mpctx->sh_audio)
+                gui(GUI_SET_AUDIO, mpctx->sh_audio);
         }
 #endif
 
