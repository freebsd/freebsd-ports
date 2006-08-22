--- src/pcf/pcfdrivr.c.orig	Wed Jul 28 00:09:02 2004
+++ src/pcf/pcfdrivr.c	Tue Aug 22 21:39:43 2006
@@ -203,19 +203,24 @@ THE SOFTWARE.
 
     /* free properties */
     {
-      PCF_Property  prop = face->properties;
+      PCF_Property  prop;
       FT_Int        i;
 
 
-      for ( i = 0; i < face->nprops; i++ )
+      if ( face->properties )
       {
-        prop = &face->properties[i];
+	for ( i = 0; i < face->nprops; i++ )
+        {
+          prop = &face->properties[i];
 
-        FT_FREE( prop->name );
-        if ( prop->isString )
-          FT_FREE( prop->value );
-      }
+	  if ( prop ) {
+            FT_FREE( prop->name );
+	    if ( prop->isString )
+	      FT_FREE( prop->value.atom );
+	  }
+	}
 
+      }
       FT_FREE( face->properties );
     }
 
@@ -258,6 +263,8 @@ THE SOFTWARE.
       FT_Error  error2;
 
 
+      PCF_Face_Done( pcfface );
+
       /* this didn't work, try gzip support! */
       error2 = FT_Stream_OpenGzip( &face->gzip_stream, stream );
       if ( FT_ERROR_BASE( error2 ) == FT_Err_Unimplemented_Feature )
@@ -357,6 +364,7 @@ THE SOFTWARE.
 
   Fail:
     FT_TRACE2(( "[not a valid PCF file]\n" ));
+    PCF_Face_Done( pcfface );
     error = PCF_Err_Unknown_File_Format;  /* error */
     goto Exit;
   }
