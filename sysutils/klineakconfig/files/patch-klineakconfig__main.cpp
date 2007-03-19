--- klineakconfig/main.cpp.orig	Mon Mar 13 18:55:22 2006
+++ klineakconfig/main.cpp	Mon Mar 19 11:40:23 2007
@@ -33,7 +33,8 @@
 	
 static KCmdLineOptions options[] =
 {
-  { "verbose", I18N_NOOP("Show verbose output"), 0 }
+  { "verbose", I18N_NOOP("Show verbose output"), 0 },
+  KCmdLineLastOption
   // INSERT YOUR COMMANDLINE OPTIONS HERE
 };
 
