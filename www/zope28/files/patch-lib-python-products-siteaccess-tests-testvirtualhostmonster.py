--- lib/python/Products/SiteAccess/tests/testVirtualHostMonster.py.orig	Thu Jun 17 13:38:08 2004
+++ lib/python/Products/SiteAccess/tests/testVirtualHostMonster.py	Thu Jun 17 13:38:24 2004
@@ -12,6 +12,7 @@
 
 from Testing.makerequest import makerequest
 
+from __future__ import generators
 import Zope
 Zope.startup()
 
