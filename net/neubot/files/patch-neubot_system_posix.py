--- neubot/system_posix.py.orig	2012-10-10 23:19:06.000000000 +0200
+++ neubot/system_posix.py	2012-10-18 16:53:57.000000000 +0200
@@ -32,13 +32,7 @@
 # the latter can.
 #
 
-#
-# By default use `nobody`, so it's possible to develop Neubot on UNIX systems
-# where the `_neubot` user does not exist.
-#
-USER = '@USER@'
-if USER.startswith('@'):
-    USER='nobody'
+USER = '_neubot'
 
 import pwd
 import os.path
