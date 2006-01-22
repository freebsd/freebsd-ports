--- config_posix.py.orig	Thu Jan 20 20:01:08 2005
+++ config_posix.py	Wed Jan 18 11:05:32 2006
@@ -5,7 +5,7 @@
 
 # flags for the compiler
 #CCFLAGS = []
-CCFLAGS = ['-O2', '-ansi', '-Wall']
+CCFLAGS = ['-O2', '-ansi', '-Wall', '-I/usr/local/include']
 
 # this is the default directory for installation. Files will be installed on
 # <prefix>/bin, <prefix>/lib and <prefix>/include when you run 'scons install'
@@ -17,5 +17,5 @@
 
 # libraries
 LIBS = ['lua', 'lualib', 'm']
-
+LINKFLAGS = ['-L/usr/local/lib']
 
