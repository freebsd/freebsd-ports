
ZMI ControlPanel DTML Bug
https://bugs.launchpad.net/zope2/+bug/838978

--- src/App/CacheManager.py.orig	2011-09-22 12:52:48.000000000 +0400
+++ src/App/CacheManager.py	2011-09-22 13:09:20.000000000 +0400
@@ -102,7 +102,7 @@
         if REQUEST is not None:
             # format as text
             REQUEST.RESPONSE.setHeader('Content-Type', 'text/plain')
-            return '\n'.join('%6d %s'%(count, name) for count, name in detail)
+            return '\n'.join('%6d %s'%(count, name) for name, count in detail)
         else:
             # raw
             return detail
