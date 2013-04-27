--- src/lib/svnmailer/notifier/_base.py.orig	2005-09-25 14:51:23.000000000 +0000
+++ src/lib/svnmailer/notifier/_base.py	2007-08-20 17:29:23.000000000 +0000
@@ -376,7 +376,6 @@
             :return: The two encodings (``('enc1', 'enc2')``)
             :rtype: ``tuple``
         """
-        from encodings import exceptions
 
         enc1 = enc2 = default
         if not change.wasAdded() or change.wasCopied():
@@ -384,7 +383,7 @@
                 enc1 = self._getContentEncoding(
                     change.getBasePath(), change.getBaseRevision()
                 )
-            except exceptions.LookupError:
+            except LookupError:
                 """ fall back """
                 pass
 
@@ -395,7 +394,7 @@
                 enc2 = self._getContentEncoding(
                     change.path, change.revision
                 )
-            except exceptions.LookupError:
+            except LookupError:
                 """ fall back """
                 pass
 
@@ -423,7 +422,6 @@
                 The specified encoding is not implemented or no encoding
                 was specified
         """
-        from encodings import exceptions
 
         # first try the svn:mime-type
         enc = self.getEncodingFromMimeType(path, revision)
@@ -461,7 +459,7 @@
             codecs.lookup(enc)
             return enc
 
-        raise exceptions.LookupError("No Encoding configured")
+        raise LookupError("No Encoding configured")
 
 
     def getEncodingFromMimeType(self, path, revision):
