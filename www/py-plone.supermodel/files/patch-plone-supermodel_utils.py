--- plone/supermodel/utils.py.orig	2011-04-29 22:24:50.000000000 +0400
+++ plone/supermodel/utils.py	2011-09-22 23:06:55.000000000 +0400
@@ -2,7 +2,7 @@
 import sys
 import re
 
-from elementtree import ElementTree
+from xml.etree import ElementTree
 
 from zope.interface import directlyProvidedBy, directlyProvides
 from zope.schema.interfaces import IField, IFromUnicode, IDict, ICollection
