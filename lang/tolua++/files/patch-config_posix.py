--- ./config_posix.py.orig	Fri Jan 21 00:01:08 2005
+++ ./config_posix.py	Sun Aug 27 14:25:40 2006
@@ -5,7 +5,7 @@
 
 # flags for the compiler
 #CCFLAGS = []
-CCFLAGS = ['-O2', '-ansi', '-Wall']
+CCFLAGS = ['-O2', '-ansi', '-Wall', '-I%%LOCALBASE%%/include', '-I%%LUA_INCDIR%%']
 
 # this is the default directory for installation. Files will be installed on
 # <prefix>/bin, <prefix>/lib and <prefix>/include when you run 'scons install'
@@ -16,6 +16,6 @@
 prefix = '/usr/local'
 
 # libraries
-LIBS = ['lua', 'lualib', 'm']
-
+LIBS = ['lua-%%LUA_VER%%', 'lualib-%%LUA_VER%%', 'm']
+LINKFLAGS = ['-L%%LOCALBASE%%/lib', '-L%%LUA_LIBDIR%%']
 
