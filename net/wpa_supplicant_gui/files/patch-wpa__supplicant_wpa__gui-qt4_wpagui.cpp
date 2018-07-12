--- wpa_supplicant/wpa_gui-qt4/wpagui.cpp.orig	2015-09-27 19:02:05 UTC
+++ wpa_supplicant/wpa_gui-qt4/wpagui.cpp
@@ -302,7 +302,8 @@ int WpaGui::openCtrlConnection(const cha
 #endif /* _DIRENT_HAVE_D_TYPE */
 
 				if (strcmp(dent->d_name, ".") == 0 ||
-				    strcmp(dent->d_name, "..") == 0)
+				    strcmp(dent->d_name, "..") == 0 ||
+				    (strlen(dent->d_name) > strlen(".pid") && !strcmp(dent->d_name + strlen(dent->d_name) - strlen(".pid"), ".pid")))
 					continue;
 				debug("Selected interface '%s'",
 				      dent->d_name);
