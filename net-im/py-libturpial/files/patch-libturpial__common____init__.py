--- ./libturpial/common/__init__.py.orig	2013-07-14 22:25:31.000000000 +0000
+++ ./libturpial/common/__init__.py	2014-02-22 11:24:15.000000000 +0000
@@ -12,6 +12,8 @@
 NUM_STATUSES = 20
 
 OS_LINUX = 'linux'  #: Constant to identify Linux based operating systems
+OS_FREEBSD = 'freebsd'  #: Constant to identify FreeBSD based operating systems
+OS_DFLY = 'dragonfly'  #: Constant to identify DragonFly based operating systems
 OS_WINDOWS = 'windows'  #: Constant to identify Windows operating systems
 OS_MAC = 'darwin'  #: Constant to identify Mac operating systems
 OS_JAVA = 'java'  #: Constant to identify Java based operating systems
