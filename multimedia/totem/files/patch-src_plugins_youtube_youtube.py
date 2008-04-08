--- src/plugins/youtube/youtube.py.orig	2008-04-08 15:37:02.979444610 -0400
+++ src/plugins/youtube/youtube.py	2008-04-08 15:37:16.056825001 -0400
@@ -52,7 +52,7 @@
 				import gst
 
 				registry = gst.registry_get_default ()
-				if registry.find_plugin ("flvdemux") == None or registry.find_plugin ("souphttpsrc") == None:
+				if registry.find_plugin ("flvdemux") == None or registry.find_plugin ("soup") == None:
 					"""This means an error will be displayed when they try to play anything"""
 					self.gstreamer_plugins_present = False
 			except ImportError:
