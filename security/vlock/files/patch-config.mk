--- config.mk.orig	2007-09-08 20:04:25.000000000 +0200
+++ config.mk	2008-03-15 10:57:43.866012457 +0100
@@ -9,18 +9,13 @@
 
 # group to install vlock-all and vlock-nosysrq as
 # defaults to 'root')
-VLOCK_GROUP =
+VLOCK_GROUP = wheel
 # mode to install vlock-all and vlock-nosysrq as
 # defaults to 4711 if group is unset and 4710 otherwise
 VLOCK_MODE =
 
 # root's group
-ROOT_GROUP = root
-
-# installation prefix
-PREFIX = /usr/local
-# installation root
-DESTDIR =
+ROOT_GROUP = wheel
 
 # c compiler
 CC = gcc
@@ -30,7 +25,7 @@
 LDFLAGS = 
 
 # linker flags needed for pam
-PAM_LIBS = -ldl -lpam
+PAM_LIBS = -lpam
 
 # gnu install
 INSTALL = install
