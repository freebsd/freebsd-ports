--- setup.py.orig	2010-05-06 04:30:03.000000000 +0800
+++ setup.py	2010-05-09 03:20:33.000000000 +0800
@@ -49,13 +49,9 @@
                 ],
     data_files = [
         ("share/xyzcmd/conf", glob.glob("conf/*")),
-        ("share/doc/xyzcmd/api", glob.glob("doc/api/*")),
         ("share/xyzcmd/skins", glob.glob("skins/*")),
-        ("share/doc/xyzcmd", ["ChangeLog", "doc/overview.pdf"]),
         ] +
-    include_rec("plugins", "share/xyzcmd/%s") +
-    include_rec("doc/user-manual", "share/doc/xyzcmd/%s",
-                lambda x: x.replace("doc/user-manual", "user-manual")),
+    include_rec("plugins", "share/xyzcmd/%s"),
     
     requires = ["urwid"],
 
