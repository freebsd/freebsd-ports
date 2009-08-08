--- platform/gtk-x11/plat/options.py.orig	2009-07-25 12:41:11.000000000 +0900
+++ platform/gtk-x11/plat/options.py	2009-07-30 15:45:34.000000000 +0900
@@ -46,12 +46,12 @@
         self.help = help
 
 USE_RENDERER = GTKPref(key="useRenderer",
-                       default=u"gstreamer",
+                       default=u"xine",
                        alias="renderer",
                        help="Which renderer to use.  (gstreamer, xine)" )
 
 USE_XINE_XV_HACK = GTKPref(key="UseXineXVHack",
-                           default=True,
+                           default=False,
                            alias="xine-xvhack",
                            help="Whether or not to use the Xine xv hack.  (true, false)" )
 
