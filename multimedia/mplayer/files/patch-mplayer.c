--- mplayer.c.orig	2015-06-10 21:17:35 UTC
+++ mplayer.c
@@ -3711,7 +3711,8 @@ goto_enable_cache:
         if (use_gui) {
             if (!gui(GUI_SET_VIDEO, mpctx->sh_video))
                 goto goto_next_file;
-            gui(GUI_SET_AUDIO, mpctx->sh_audio);
+            if (mpctx->sh_audio)
+                gui(GUI_SET_AUDIO, mpctx->sh_audio);
         }
 #endif
 
