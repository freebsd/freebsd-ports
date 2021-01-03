--- ttp/returners/terminal_returner.py.orig	2020-12-24 20:13:53 UTC
+++ ttp/returners/terminal_returner.py
@@ -33,12 +33,12 @@ def terminal_returner(data, **kwargs):
         for yeallow_word in yeallow_words:
             data = data.replace(yeallow_word, fttr.format(Y, yeallow_word, N))
     # print output
-    if _ttp_["python_major_version"] is 2:
+    if _ttp_["python_major_version"] == 2:
         if isinstance(data, str) or isinstance(data, unicode):
             print(data)
         else:
             print(str(data).replace("\\n", "\n"))
-    elif _ttp_["python_major_version"] is 3:
+    elif _ttp_["python_major_version"] == 3:
         if isinstance(data, str):
             print(data)
         else:
