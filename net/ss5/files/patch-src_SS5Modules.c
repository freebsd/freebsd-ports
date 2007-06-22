--- src/SS5Modules.c.orig	Thu Apr  5 02:28:26 2007
+++ src/SS5Modules.c
@@ -29,7 +29,7 @@ S5RetCode S5LoadModules( void ) 
 {
   S5RetCode (*InitModule)(struct _module *m);
 
-  char *error;
+  const char *error;
   char libpath[128];
 
   /*
