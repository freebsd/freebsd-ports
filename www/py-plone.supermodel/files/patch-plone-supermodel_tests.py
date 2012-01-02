--- plone/supermodel/test.py.orig	2011-04-30 12:22:20.000000000 +0400
+++ plone/supermodel/tests.py	2011-09-22 23:07:10.000000000 +0400
@@ -1,5 +1,5 @@
 from cStringIO import StringIO
-from elementtree import ElementTree as etree
+from xml.etree import ElementTree as etree
 import doctest
 import unittest
 import zope.app.testing.placelesssetup
