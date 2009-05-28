--- deluge/ui/gtkui/preferences.py.orig	2009-04-07 05:24:02.000000000 +0900
+++ deluge/ui/gtkui/preferences.py	2009-05-28 02:39:06.000000000 +0900
@@ -231,7 +231,6 @@
                 "chk_natpmp": ("active", self.core_config["natpmp"]),
                 "chk_utpex": ("active", self.core_config["utpex"]),
                 "chk_lsd": ("active", self.core_config["lsd"]),
-                "chk_new_releases": ("active", self.core_config["new_release_check"]),
                 "chk_send_info": ("active", self.core_config["send_info"]),
                 "combo_encin": ("active", self.core_config["enc_in_policy"]),
                 "combo_encout": ("active", self.core_config["enc_out_policy"]),
@@ -372,7 +371,6 @@
                 "chk_utpex",
                 "chk_lsd",
                 "chk_send_info",
-                "chk_new_releases",
                 "combo_encin",
                 "combo_encout",
                 "combo_enclevel",
@@ -438,10 +436,6 @@
         self.glade.get_widget("chk_show_rate_in_title").set_active(
             self.gtkui_config["show_rate_in_title"])
 
-        ## Other tab ##
-        self.glade.get_widget("chk_show_new_releases").set_active(
-            self.gtkui_config["show_new_releases"])
-
         ## Notification tab ##
         self.glade.get_widget("chk_ntf_tray_blink").set_active(
             self.gtkui_config["ntf_tray_blink"])
@@ -654,8 +648,6 @@
             new_gtkui_config["ntf_security"] = 'TLS'
 
         ## Other tab ##
-        new_gtkui_config["show_new_releases"] = \
-            self.glade.get_widget("chk_show_new_releases").get_active()
         new_core_config["send_info"] = \
             self.glade.get_widget("chk_send_info").get_active()
 
@@ -664,8 +656,6 @@
             self.glade.get_widget("spin_daemon_port").get_value_as_int()
         new_core_config["allow_remote"] = \
             self.glade.get_widget("chk_allow_remote_connections").get_active()
-        new_core_config["new_release_check"] = \
-            self.glade.get_widget("chk_new_releases").get_active()
 
         ## Proxy tab ##
         new_core_config["proxies"] = {}
