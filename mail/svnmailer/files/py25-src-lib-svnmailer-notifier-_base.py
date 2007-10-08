--- src/lib/svnmailer/notifier/_base.py.orig	Mon Apr 17 14:29:06 2006
+++ src/lib/svnmailer/notifier/_base.py	Mon Oct  8 15:36:25 2007
@@ -345,7 +345,6 @@
             @return: The two encodings
             @rtype: C{tuple} of C{str}
         """
-        from encodings import exceptions
 
         enc1 = enc2 = default
         if not change.wasAdded() or change.wasCopied():
@@ -353,7 +352,7 @@
                 enc1 = self._getContentEncoding(
                     change.getBasePath(), change.getBaseRevision()
                 )
-            except exceptions.LookupError:
+            except LookupError:
                 # fall back
                 pass
 
@@ -364,7 +363,7 @@
                 enc2 = self._getContentEncoding(
                     change.path, change.revision
                 )
-            except exceptions.LookupError:
+            except LookupError:
                 # fall back
                 pass
 
@@ -389,7 +388,6 @@
             @exception encodings.exception.LookupError: The specified encoding
                 is not implemented or no encoding was specified
         """
-        from encodings import exceptions
 
         # first try the svn:mime-type
         enc = self.getEncodingFromMimeType(path, revision)
@@ -427,7 +425,7 @@
             codecs.lookup(enc)
             return enc
 
-        raise exceptions.LookupError("No Encoding configured")
+        raise LookupError("No Encoding configured")
 
 
     def getEncodingFromMimeType(self, path, revision):
