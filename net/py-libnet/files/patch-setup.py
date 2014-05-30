--- ./setup.py.orig	2011-08-02 17:53:25.000000000 +0200
+++ ./setup.py	2014-05-30 12:55:01.000000000 +0200
@@ -5,8 +5,8 @@
 import os
 import sys
 
-include_dir = None
-lib_dir = None
+include_dir = '/usr/local/include/libnet11/'
+lib_dir = '/usr/local/lib/libnet11'
 
 
 package_version = '3.0-beta-rc1'
