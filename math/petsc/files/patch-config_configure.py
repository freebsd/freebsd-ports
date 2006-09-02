--- ./config/configure.py.orig	Sat Sep  2 02:24:13 2006
+++ ./config/configure.py	Sat Sep  2 23:23:33 2006
@@ -97,7 +97,7 @@
     print '             *** Do not run configure as root, or using sudo. ***'
     print '             ***** That should be reserved for installation *****'
     print '================================================================================='
-    sys.exit(3)
+    %%PACKAGE%%sys.exit(3)
 
   # Check for broken cygwin
   if chkcygwin():
