--- wafhelpers/asciidoc.py.orig	2019-07-06 22:32:43 UTC
+++ wafhelpers/asciidoc.py
@@ -70,4 +70,4 @@ def run_a2x(self, node):
     out = "%s.%s" % (n_file.replace("-man.adoc.man-tmp", ""), self.section)
     out_n = self.bld.path.find_or_declare(out)
     self.create_task('a2x', node, out_n)
-    self.bld.install_files("${MANDIR}/man%s/" % self.section, out_n)
+    self.bld.install_files("${MANDIR}/../../man/man%s/" % self.section, out_n)
