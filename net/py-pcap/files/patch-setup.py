--- setup.py.orig	Mon Dec 20 01:50:10 2004
+++ setup.py	Mon Dec 20 01:50:19 2004
@@ -21,7 +21,7 @@
 #    self.run_command('make_clean')
 
 class pcap_build_ext(build_ext):
-  def swig_sources(self, sources):
+  def swig_sources(self, sources, ext=None):
   
       """Walk the list of source files in 'sources', looking for SWIG
       interface (.i) files.  Run SWIG on all that are found, and
