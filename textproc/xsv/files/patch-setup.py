--- ./setup.py.orig	2008-01-18 13:17:40.000000000 +0100
+++ ./setup.py	2014-03-23 02:06:18.690868591 +0100
@@ -16,20 +16,10 @@
     self.install_dir = getattr(install_cmd, 'install_lib')
     return install_data.run(self)
 
-datafiles=[('XSV/example',
-            ['triv.xml',
-             'triv.xsd',
-             'tiny.xml',
-             'tiny.xsd']),
-           ('XSV',['XSV/nndump.xml',
+datafiles=[('XSV',['XSV/nndump.xml',
                    'XSV/XMLSchema.dtd',
                    'XSV/datatypes.dtd']),
-           ('XSV/pubtext',['xsv.xsl']),
-           ('XSV/doc',['COPYING',
-                       'COPYRIGHT',
-                       'pc-shrinkwrap',
-                       'xsv-status.xml',
-                       'xsv-status.html'])] # only works for bdist and friends
+           ('XSV/pubtext',['xsv.xsl'])]
 
 if sys.platform.find("win32",0,5)==0:
   platform="WIN32"
