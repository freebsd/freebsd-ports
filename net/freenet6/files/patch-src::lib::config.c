--- src/lib/config.c.orig	Wed Jun 30 01:06:13 2004
+++ src/lib/config.c	Sat Nov 20 14:44:44 2004
@@ -270,7 +270,7 @@
 int tspInitialize(int argc, char *argv[], tConf *Conf)
 {
   tConf CmdLine;
-  char *Templ = "template";
+  char *Templ = "bin";
 
   Conf->tsp_dir      = NULL;
   Conf->server       = "";
