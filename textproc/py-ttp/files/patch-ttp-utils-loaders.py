--- ttp/utils/loaders.py.orig	2020-09-14 21:20:38 UTC
+++ ttp/utils/loaders.py
@@ -33,7 +33,7 @@ def load_files(path, extensions=[], filters=[], read=F
     if os.path.isfile(path[:5000]):
         if read:
             try:
-                if _ttp_["python_major_version"] is 2:
+                if _ttp_["python_major_version"] == 2:
                     with open(path, 'r') as file_obj:
                         return [('text_data', file_obj.read(),)]
                 with open(path, 'r', encoding='utf-8') as file_obj:
@@ -53,10 +53,10 @@ def load_files(path, extensions=[], filters=[], read=F
         if read:
             ret = []
             for f in files:
-                if _ttp_["python_major_version"] is 2:  
+                if _ttp_["python_major_version"] == 2:  
                     with open((path + f), 'r') as file_obj:
                         ret.append(('text_data', file_obj.read(),))
-                elif _ttp_["python_major_version"] is 3:
+                elif _ttp_["python_major_version"] == 3:
                     with open((path + f), 'r', encoding='utf-8') as file_obj:
                         ret.append(('text_data', file_obj.read(),))
             return ret
@@ -111,7 +111,7 @@ def _get_include_data(text_data, include):
     return text_data
     
 def load_ini(text_data, include=None, **kwargs):
-    if _ttp_["python_major_version"] is 3:
+    if _ttp_["python_major_version"] == 3:
         import configparser
         cfgparser = configparser.ConfigParser()
         # to make cfgparser keep the case, e.g. VlaN222 will not become vlan222:
@@ -132,7 +132,7 @@ def load_ini(text_data, include=None, **kwargs):
                 log.error("ttp_utils.load_struct: Python3, Unable to load ini formatted data\n'{}'".format(text_data))
         # convert configparser object into dictionary
         result = {k: dict(cfgparser.items(k)) for k in list(cfgparser.keys())}
-    elif _ttp_["python_major_version"] is 2:
+    elif _ttp_["python_major_version"] == 2:
         import ConfigParser
         import StringIO
         cfgparser = ConfigParser.ConfigParser()
@@ -217,4 +217,4 @@ def load_csv(text_data, include=None, **kwargs):
             continue
         temp = {headers[index]: i for index, i in enumerate(row)}
         data[temp.pop(key)] = temp
-    return data
\ No newline at end of file
+    return data
