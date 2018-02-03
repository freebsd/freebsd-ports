--- pyhwp/hwp5/plat/olefileio.py.orig	2014-11-03 13:47:24 UTC
+++ pyhwp/hwp5/plat/olefileio.py
@@ -22,11 +22,10 @@ from hwp5.utils import cached_property
 
 def is_enabled():
     try:
-        import OleFileIO_PL
+        import olefile
     except Exception:
         return False
     else:
-        OleFileIO_PL
         return True
 
 
@@ -62,12 +61,12 @@ class OleStorage(OleStorageItem):
 
     def __init__(self, olefile, path='', parent=None):
         if not hasattr(olefile, 'openstream'):
-            from OleFileIO_PL import isOleFile
+            from olefile import isOleFile
             if not isOleFile(olefile):
                 from hwp5.errors import InvalidOleStorageError
                 errormsg = 'Not an OLE2 Compound Binary File.'
                 raise InvalidOleStorageError(errormsg)
-            from OleFileIO_PL import OleFileIO
+            from olefile import OleFileIO
             olefile = OleFileIO(olefile)
         OleStorageItem.__init__(self, olefile, path, parent)
 
