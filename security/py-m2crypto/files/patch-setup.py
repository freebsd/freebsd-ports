--- setup.py.orig	Sun Mar 28 08:06:59 2004
+++ setup.py	Fri Mar 18 22:44:10 2005
@@ -12,56 +12,6 @@
 from distutils.core import setup, Extension
 from distutils.command import build_ext
 
-# This copy of swig_sources is from Python 2.2.
-
-def swig_sources (self, sources):
-
-    """Walk the list of source files in 'sources', looking for SWIG
-    interface (.i) files.  Run SWIG on all that are found, and
-    return a modified 'sources' list with SWIG source files replaced
-    by the generated C (or C++) files.
-    """
-
-    new_sources = []
-    swig_sources = []
-    swig_targets = {}
-
-    # XXX this drops generated C/C++ files into the source tree, which
-    # is fine for developers who want to distribute the generated
-    # source -- but there should be an option to put SWIG output in
-    # the temp dir.
-
-    if self.swig_cpp:
-        target_ext = '.cpp'
-    else:
-        target_ext = '.c'
-
-    for source in sources:
-        (base, ext) = os.path.splitext(source)
-        if ext == ".i":             # SWIG interface file
-            new_sources.append(base + target_ext)
-            swig_sources.append(source)
-            swig_targets[source] = new_sources[-1]
-        else:
-            new_sources.append(source)
-
-    if not swig_sources:
-        return new_sources
-
-    swig = self.find_swig()
-    swig_cmd = [swig, "-python", "-ISWIG"]
-    if self.swig_cpp:
-        swig_cmd.append("-c++")
-
-    for source in swig_sources:
-        target = swig_targets[source]
-        self.announce("swigging %s to %s" % (source, target))
-        self.spawn(swig_cmd + ["-o", target, source])
-
-    return new_sources
-
-build_ext.build_ext.swig_sources = swig_sources
-
 my_inc = os.path.join(os.getcwd(), 'SWIG')
 
 if os.name == 'nt':
