--- src/tspc.c.orig	Wed Sep 10 07:44:23 2003
+++ src/tspc.c	Thu Oct 23 11:13:55 2003
@@ -205,7 +205,7 @@
 int Initialise(int argc, char *argv[], tConf *Conf)
 {
   tConf CmdLine;
-  char *Templ = "template";
+  char *Templ = "bin";
 
   Conf->tsp_dir      = NULL;
   Conf->server       = "";
