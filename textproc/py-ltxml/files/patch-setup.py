--- setup.py.orig	Mon Nov  4 16:50:20 2002
+++ setup.py	Fri Jan 31 12:08:31 2003
@@ -16,10 +16,7 @@
     self.install_dir = getattr(install_cmd, 'install_lib')
     return install_data.run(self)
 
-datafiles=[('PyLTXML/example',
-            ['example/small.xml',
-             'example/gscore.dtd',
-             'example/simple.py'])] # only works for bdist and friends
+datafiles=[]
 
 if sys.platform.find("win32",0,5)==0:
   incldirs=['C:\Program Files\HCRC LTG\LT XML\include']
