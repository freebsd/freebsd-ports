--- platform/freebsd/tsp_local.c.bak	Wed Mar 31 00:27:35 2004
+++ platform/freebsd/tsp_local.c	Mon Jul 11 18:12:14 2005
@@ -59,13 +59,13 @@
 #include "tsp_tun.h"   /* freebsd's tun */
 
 
-char *FileName  = "tspc.conf";
-char *LogFile   = "tspc.log";
+char *FileName  = "PREFIX/etc/tspc.conf";
+char *LogFile   = "/var/log/tspc.log";
 char *LogFileName = NULL;
 char *ScriptInterpretor = "/bin/sh";
 char *ScriptExtension = "sh";
 char *ScriptDir = NULL;
-char *TspHomeDir = "/usr/local/etc/tsp";
+char *TspHomeDir = "PREFIX/share/tspc2";
 char DirSeparator = '/';
 
 int Verbose = 0;
