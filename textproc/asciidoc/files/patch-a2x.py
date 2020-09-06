--- a2x.py.orig	2018-01-13 22:10:35 UTC
+++ a2x.py
@@ -498,7 +498,7 @@ class A2X(AttrDict):
             self.asciidoc_opts += ' --doctype %s' % self.doctype
         for attr in self.attributes:
             self.asciidoc_opts += ' --attribute "%s"' % attr
-#        self.xsltproc_opts += ' --nonet'
+        self.xsltproc_opts += ' --nonet --path %%LOCALBASE%%/share/xsl/docbook/manpages/'
         if self.verbose:
             self.asciidoc_opts += ' --verbose'
             self.dblatex_opts += ' -V'
