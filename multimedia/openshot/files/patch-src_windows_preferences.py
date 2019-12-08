--- src/windows/preferences.py.orig	2019-11-11 07:57:57 UTC
+++ src/windows/preferences.py
@@ -293,7 +293,7 @@ class Preferences(QDialog):
                                 value_list.remove(value_item)
                             elif os_platform == "Windows" and v not in ("0", "3", "4", "7"):
                                 value_list.remove(value_item)
-                            elif os_platform == "Linux" and v not in ("0", "1", "2", "6", "7"):
+                            elif (os_platform == "FreeBSD" or os_platform == "Linux") and v not in ("0", "1", "2", "6", "7"):
                                 value_list.remove(value_item)
 
                         # Remove hardware mode items which cannot decode the example video
