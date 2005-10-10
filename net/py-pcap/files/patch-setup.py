--- setup.py.orig	Mon Jul  4 08:14:31 2005
+++ setup.py	Mon Oct 10 23:40:45 2005
@@ -75,7 +75,7 @@
               new_sources.append(source)
       return new_sources
     
-  def swig_sources(self, sources):
+  def swig_sources(self, sources, ext=None):
   
       """Walk the list of source files in 'sources', looking for SWIG
       interface (.i) files.  Run SWIG on all that are found, and
@@ -121,11 +121,6 @@
           self.announce("swigging %s to %s" % (source, target))
           self.spawn(swig_cmd + ["-o", target, source])
 
-          self.announce('doc-ifying swig-generated source file %s' % target)
-          self.spawn(['./build-tools/docify.py', target])
-
-          self.announce('doc-ifying swig-generated shadow class file %s' % 'pcap.py')
-          self.spawn(['./build-tools/docify-shadow.py', 'pcap.py'])
   
       return new_sources
 
