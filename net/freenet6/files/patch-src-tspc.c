--- src/tspc.c.orig	Tue Sep 11 23:41:05 2001
+++ src/tspc.c	Thu Oct 11 13:27:31 2001
@@ -178,7 +178,7 @@
 int Initialise(int argc, char *argv[], tConf *Conf)
 {
   tConf CmdLine;
-  char *Templ = "template";
+  char *Templ = "bin";
   extern int ReadConfigFile(char *File, tConf *Conf);
 
   Conf->tsp_dir      = NULL;
@@ -554,7 +554,7 @@
   SetEnv("TSP_VERBOSE",           buf, 1);
   SetEnv("TSP_HOME_DIR",          TspHomeDir, 1);
 
-  snprintf(buf, sizeof buf, "%s%s%c%s.%s", ScriptInterpretor, ScriptDir, DirSeparator, Conf.template, ScriptExtension);
+  snprintf(buf, sizeof buf, "%s%s%ctspc-%s.%s", ScriptInterpretor, ScriptDir, DirSeparator, Conf.template, ScriptExtension);
 
   Display(2, ELInfo, "SetUpInterface", "Executing configuration script.\n");
   Display(2, ELInfo, "SetUpInterface", buf);

