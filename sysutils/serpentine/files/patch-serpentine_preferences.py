--- serpentine/preferences.py.orig	Mon Jun 27 16:30:18 2005
+++ serpentine/preferences.py	Mon Jun 27 16:31:13 2005
@@ -93,7 +93,8 @@
 		# temp
 		self.__tmp = gaw.GConfValue (
 			key = "/apps/serpentine/temporary_dir",
-			data_spec = gaw.Spec.STRING
+			data_spec = gaw.Spec.STRING,
+			default = "."
 		)
 		
 		# Pool
