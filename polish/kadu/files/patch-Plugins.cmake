--- Plugins.cmake.orig	2016-10-16 20:09:16 UTC
+++ Plugins.cmake
@@ -106,12 +106,12 @@ if (UNIX AND NOT APPLE)
 	# docking
 		# Indicator docking support
 		# Comment if you are not compilign under Ubuntu flavor
-		indicator_docking
+		#indicator_docking
 
 	# integration
 		# integration with Unity
 		# Comment if you are not compilign under Ubuntu flavor
-		unity_integration
+		#unity_integration
 
 	# notifiers
 		# Freedesktop notification support
