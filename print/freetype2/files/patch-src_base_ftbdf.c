--- src/base/ftbdf.c.orig	Thu Apr 17 15:06:41 2003
+++ src/base/ftbdf.c	Thu Apr 17 15:07:16 2003
@@ -85,10 +85,13 @@
       FT_Driver              driver = face->driver;
       BDF_GetPropertyFunc    func;
 
-      func = (BDF_GetPropertyFunc) driver->root.clazz->get_interface(
-                             FT_MODULE( driver ), "get_bdf_property" );
-      if ( func )
-        error = func( face, prop_name, aproperty );
+      if (driver->root.clazz->get_interface)
+      {
+        func = (BDF_GetPropertyFunc) driver->root.clazz->get_interface(
+                               FT_MODULE( driver ), "get_bdf_property" );
+        if ( func )
+          error = func( face, prop_name, aproperty );
+      }
     }
     return error;
   }
