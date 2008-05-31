--- FSForm.py.orig	2003-09-25 23:08:33.000000000 +0900
+++ FSForm.py	2008-03-13 07:13:15.000000000 +0900
@@ -5,10 +5,17 @@
     import Products.FileSystemSite
 except ImportError:
     # use CMF product
-    from Products.CMFCore.CMFCorePermissions import View
+    try:
+        from Products.CMFCore.permissions import View
+    except ImportError: # older CMF
+        from Products.CMFCore.CMFCorePermissions import View
     from Products.CMFCore.FSObject import FSObject
     from Products.CMFCore.DirectoryView import registerFileExtension,\
-                                               registerMetaType, expandpath
+                                               registerMetaType
+    try:
+        from Products.CMFCore.utils import expandpath
+    except ImportError:
+        from Products.CMFCore.DirectoryView import expandpath
 else:
     # use FileSystemSite product
     from Products.FileSystemSite.Permissions import View
