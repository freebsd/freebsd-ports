Fix build for FreeBSD-7.4
nmap 6.25 contains liblua5.2.1

http://lua-users.org/lists/lua-l/2011-12/msg00708.html
==============================================================
--- ./liblua/liolib.c.orig	2013-01-09 18:47:49.000000000 +0100
+++ ./liblua/liolib.c	2013-01-09 18:48:29.000000000 +0100
@@ -19,6 +19,7 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
+#include <sys/types.h>
 
 #define liolib_c
 #define LUA_LIB
