Obtained from:	https://bitbucket.org/tkoskine/sphinxcontrib-adadomain/commits/0adaafc635791511af623027bd2cf57375763a27

--- sphinxcontrib/adadomain.py.orig	2018-01-19 17:53:22 UTC
+++ sphinxcontrib/adadomain.py
@@ -18,13 +18,13 @@ import string
 
 from docutils import nodes
 from docutils.parsers.rst import directives
+from docutils.parsers.rst import Directive
 
-from sphinx import addnodes
+from sphinx import addnodes, version_info
 from sphinx.roles import XRefRole
 from sphinx.locale import l_, _
 from sphinx.directives import ObjectDescription
 from sphinx.domains import Domain, ObjType, Index
-from sphinx.util.compat import Directive
 from sphinx.util.nodes import make_refnode
 from sphinx.util.docfields import Field, TypedField
 
@@ -269,12 +269,12 @@ class AdaObject(ObjectDescription):
 
         indextext = self._get_index_text(name)
         if indextext:
-            self.indexnode['entries'].append(('single', indextext, name, name))
+            self.indexnode['entries'].append(('single', indextext, name, name, None))
 
         plain_name = pieces[-1]
         indextext = self._get_index_text(plain_name)
         if indextext:
-            self.indexnode['entries'].append(('single', indextext, name, plain_name))
+            self.indexnode['entries'].append(('single', indextext, name, plain_name, None))
 
 
 class AdaModule(Directive):
@@ -316,7 +316,7 @@ class AdaModule(Directive):
         if not noindex:
             indextext = _('%s (module)') % modname
             inode = addnodes.index(entries=[('single', indextext,
-                                             'module-' + modname, modname)])
+                                             'module-' + modname, modname, None)])
             ret.append(inode)
         return ret
 
