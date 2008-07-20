--- src/tsp/tsp_setup.c.orig	2008-07-20 23:56:23.000000000 +1000
+++ src/tsp/tsp_setup.c	2008-07-20 23:57:19.000000000 +1000
@@ -273,7 +273,7 @@
   //
   if( buffer[0] == 0x00 )
   {
-    snprintf( buffer, sizeof buffer, "%s%c%s.%s", ScriptDir, DirSeparator, pConfig->template, ScriptExtension);
+    snprintf( buffer, sizeof buffer, "%s%cgw6c-%s.%s", ScriptDir, DirSeparator, pConfig->template, ScriptExtension);
 
     f_test = fopen( buffer, "r" );
     if( f_test == NULL )
@@ -290,13 +290,13 @@
     if( ScriptInterpretor != NULL )
     {
       snprintf( buffer, sizeof buffer, 
-               "%s \"%s%c%s.%s\"", 
+               "%s \"%s%cgw6c-%s.%s\"", 
                ScriptInterpretor, ScriptDir, DirSeparator, pConfig->template, ScriptExtension);
     }
     else
     {
       snprintf( buffer, sizeof buffer, 
-                "\"%s%c%s.%s\"",  
+                "\"%s%cgw6c-%s.%s\"",  
                 ScriptDir, DirSeparator, pConfig->template, ScriptExtension);
     }
   }
