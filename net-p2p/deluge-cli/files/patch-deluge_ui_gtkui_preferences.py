Closing upstream bug-report: https://dev.deluge-torrent.org/ticket/3039

Index: deluge/ui/gtkui/preferences.py
===================================================================
--- deluge/ui/gtkui/preferences.py.orig	2017-05-12 12:57:19 UTC
+++ deluge/ui/gtkui/preferences.py
@@ -318,11 +318,8 @@ class Preferences(component.Component):
             }
             # Add proxy stuff
 
-            # Display workaround for single proxy in libtorrent >v0.16
-            try:
-                lt_single_proxy = component.get("PreferencesManager").LT_SINGLE_PROXY
-            except AttributeError:
-                lt_single_proxy = False
+            # Display workaround for single proxy in libtorrent >= v0.16
+            lt_single_proxy = True
 
             for t in ("peer", "web_seed", "tracker", "dht"):
                 if lt_single_proxy and not t == "peer":
