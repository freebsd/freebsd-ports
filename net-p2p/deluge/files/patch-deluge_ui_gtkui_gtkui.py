--- deluge/ui/gtkui/gtkui.py.orig	2009-04-10 01:40:52.000000000 +0900
+++ deluge/ui/gtkui/gtkui.py	2009-05-27 04:37:04.000000000 +0900
@@ -81,7 +81,6 @@
     "start_in_tray": False,
     "lock_tray": False,
     "tray_password": "",
-    "check_new_releases": True,
     "default_load_path": None,
     "window_maximized": False,
     "window_x_pos": 0,
@@ -101,7 +100,6 @@
     "autoadd_enable": False,
     "autoadd_location": "",
     "choose_directory_dialog_path": deluge.common.get_default_download_dir(),
-    "show_new_releases": True,
     "signal_port": 40000,
     "ntf_tray_blink": True,
     "ntf_sound": False,
