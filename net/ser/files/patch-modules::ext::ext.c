
$FreeBSD$

--- modules/ext/ext.c.orig	Sun Apr  6 23:25:51 2003
+++ modules/ext/ext.c	Tue May  4 19:11:40 2004
@@ -49,6 +50,8 @@
 #include "my_exec.h"
 #include "config.h"
 
+MODULE_VERSION
+
 #define MAX_BUFFER_LEN 1024
 
 
