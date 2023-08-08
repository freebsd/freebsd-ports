--- qats/app/gui.py.orig	2023-01-03 17:37:48 UTC
+++ qats/app/gui.py
@@ -48,7 +48,7 @@ LOGGING_LEVELS = dict(
 if sys.platform == "win32":
     SETTINGS_FILE = os.path.join(os.getenv("APPDATA", os.getenv("USERPROFILE", "")), "qats.settings")
 else:
-    SETTINGS_FILE = os.path.join("var", "lib", "qats.settings")
+    SETTINGS_FILE = os.path.join("/home", os.getlogin(), ".config", "qats.settings")
 ICON_FILE = resource_filename("qats.app", "qats.ico")
 
 STATS_ORDER = ["name", "min", "max", "mean", "std", "skew", "kurt", "tz", "wloc", "wscale", "wshape",
