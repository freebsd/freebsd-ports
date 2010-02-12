--- src/tsp/tsp_setup.c.orig	2009-11-15 20:06:20.000000000 +0100
+++ src/tsp/tsp_setup.c	2009-11-15 20:07:10.000000000 +0100
@@ -262,7 +262,7 @@
   //
   if( buffer[0] == 0x00 )
   {
-    pal_snprintf( buffer, sizeof buffer, "%s%c%s.%s", ScriptDir, DirSeparator, pConfig->template, ScriptExtension);
+    pal_snprintf( buffer, sizeof buffer, "%s%cgw6c-%s.%s", ScriptDir, DirSeparator, pConfig->template, ScriptExtension);
 
     f_test = fopen( buffer, "r" );
     if( f_test == NULL )
@@ -279,13 +279,13 @@
     if( ScriptInterpretor != NULL )
     {
       pal_snprintf( buffer, sizeof buffer,
-               "%s \"%s%c%s.%s\"",
+               "%s \"%s%cgw6c-%s.%s\"",
                ScriptInterpretor, ScriptDir, DirSeparator, pConfig->template, ScriptExtension);
     }
     else
     {
       pal_snprintf( buffer, sizeof buffer,
-                "\"%s%c%s.%s\"",
+                "\"%s%cgw6c-%s.%s\"",
                 ScriptDir, DirSeparator, pConfig->template, ScriptExtension);
     }
   }
