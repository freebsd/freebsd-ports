--- setup.py.orig	Sat Jan 22 02:42:00 2005
+++ setup.py	Thu Jan 27 17:49:21 2005
@@ -77,7 +77,7 @@
 data.extend(glob.glob('images/*.ppm'))
 data.append('.matplotlibrc')
 
-data_files=[('share/matplotlib', data),]
+data_files=[('share/py-matplotlib', data),]
 
 # Figure out which array packages to provide binary support for
 # and define the NUMERIX value: Numeric, numarray, or both.
