--- src/windows/preferences.py.orig	2023-04-20 05:27:15 UTC
+++ src/windows/preferences.py
@@ -325,7 +325,7 @@ class Preferences(QDialog):
                                 value_list.remove(value_item)
                             elif os_platform == "Windows" and v not in ("0", "3", "4"):
                                 value_list.remove(value_item)
-                            elif os_platform == "Linux" and v not in ("0", "1", "2", "6"):
+                            elif (os_platform == "FreeBSD" or os_platform == "Linux") and v not in ("0", "1", "2", "6"):
                                 value_list.remove(value_item)
 
                             # Add test button
