--- ./setup.py.orig	2008-01-11 15:26:31.000000000 +0100
+++ ./setup.py	2014-03-24 17:33:02.100042933 +0100
@@ -6,9 +6,7 @@
 from distutils.core import setup, Extension
 from distutils import sysconfig
 
-datafiles= ['example/small.xml',
-             'example/gscore.dtd',
-             'example/simple.py'] # only works for bdist and friends
+datafiles=[]
 
 if sys.platform.find("win32",0,5)==0:
   incldirs=['C:\\Program Files\\msys\\1.0\\include\\ltxml12','C:\\Program Files\\msys\\1.0\\include']
@@ -32,8 +30,6 @@
   libs=['ltapi12','ltstd12', 'z']
   macros=[('FOR_LT', '1')] # ,('ALLOC_DEBUG', '1')
 
-  data_files=[( sysconfig.get_python_lib() + "/PyLTXML/example",
-                datafiles)]
   if sys.platform.find("sunos",0,5)==0:
     extra_link_args=['-mimpure-text']
     extra_compile_args=['-mimpure-text']
@@ -65,5 +61,4 @@
       See 00README for details""",
       platforms=[platform],
       packages=['PyLTXML'],
-      data_files=data_files,
       ext_modules=[pyltxml])
