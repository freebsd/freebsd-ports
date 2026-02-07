--- asciidoc/a2x.py.orig	2021-12-20 19:54:07 UTC
+++ asciidoc/a2x.py
@@ -520,6 +520,7 @@ class A2X(AttrDict):
         for attr in self.attributes:
             self.asciidoc_opts.append(('--attribute', attr))
 #        self.xsltproc_opts += ' --nonet'
+        self.xsltproc_opts += ' --nonet --path %%LOCALBASE%%/share/xsl/docbook/manpages/'
         if self.verbose:
             self.asciidoc_opts.append(('--verbose',))
             self.dblatex_opts += ' -V'
