--- code/reposadolib/reposadocommon.py.org	2012-06-23 21:35:41.103519893 +0900
+++ code/reposadolib/reposadocommon.py	2012-06-23 21:43:57.289520798 +0900
@@ -58,7 +58,7 @@
 
 def prefsFilePath():
     '''Returns path to our preferences file.'''
-    return os.path.join(get_main_dir(), 'preferences.plist')
+    return os.path.join('%%LOCALBASE%%/etc/', 'preferences.plist')
 
 
 def pref(prefname):
@@ -71,7 +71,7 @@
 'http://swscan.apple.com/content/catalogs/others/index-lion-snowleopard-leopard.merged-1.sucatalog',
 'http://swscan.apple.com/content/catalogs/others/index-mountainlion-lion-snowleopard-leopard.merged-1.sucatalog'],
         'PreferredLocalizations': ['English', 'en'],
-        'CurlPath': '/usr/bin/curl'
+        'CurlPath': '%%LOCALBASE%%/bin/curl'
     }
     try:
         prefs = plistlib.readPlist(prefsFilePath())
