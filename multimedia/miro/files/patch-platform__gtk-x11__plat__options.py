--- platform/gtk-x11/plat/options.py.orig	2009-02-12 06:37:07.000000000 +0900
+++ platform/gtk-x11/plat/options.py	2009-02-12 18:24:15.000000000 +0900
@@ -39,7 +39,7 @@
 from miro.prefs import Pref
 
 USE_RENDERER = Pref(key="useRenderer",
-                    default=u"gstreamer",
+                    default=u"xine",
                     platformSpecific=False,
                     alias="renderer",
                     help="Which renderer to use.  (gstreamer, xine)" )
@@ -51,7 +51,7 @@
                   help="Which visualization plugin to use for audio files.  (goom or none)" )
 
 USE_XINE_XV_HACK = Pref(key="UseXineXVHack",
-                        default=True,
+                        default=False,
                         platformSpecific=False,
                         alias="xine-xvhack",
                         help="Whether or not to use the Xine xv hack.  (true, false)" )
