--- plone/supermodel/parser.py.orig	2011-04-29 22:24:50.000000000 +0400
+++ plone/supermodel/parser.py	2011-09-22 23:06:17.000000000 +0400
@@ -17,7 +17,7 @@
 from plone.supermodel.model import Model, Fieldset
 from plone.supermodel.interfaces import FIELDSETS_KEY
 
-from elementtree import ElementTree
+from xml.etree import ElementTree
 
 # Helper adapters
 
