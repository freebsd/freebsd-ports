--- lib/python/Products/SiteAccess/tests/testVirtualHostMonster.py.orig	Thu Aug 11 09:11:19 2005
+++ lib/python/Products/SiteAccess/tests/testVirtualHostMonster.py	Wed Sep  7 12:19:37 2005
@@ -12,6 +12,7 @@
 
 from Testing.makerequest import makerequest
 
+from __future__ import generators
 import Zope2
 Zope2.startup()
 
