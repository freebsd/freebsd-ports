--- src/global_config.py.orig	2025-06-16 11:23:57 UTC
+++ src/global_config.py
@@ -7,7 +7,7 @@ from configparser import ConfigParser
 from configparser import ConfigParser
 
 
-DIR_PATH = os.path.dirname(os.path.realpath(__file__))
+DIR_PATH = "/usr/local/share/onedrivegui"
 PROFILES_FILE = os.path.expanduser("~/.config/onedrive-gui/profiles")
 
 
