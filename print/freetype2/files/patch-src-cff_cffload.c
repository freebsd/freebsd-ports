diff --git a/src/cff/cffload.c b/src/cff/cffload.c
index 22163fb..24b899d 100644
--- src/cff/cffload.c
+++ src/cff/cffload.c
@@ -842,7 +842,20 @@
             goto Exit;
 
           for ( j = 1; j < num_glyphs; j++ )
-            charset->sids[j] = FT_GET_USHORT();
+          {
+            FT_UShort sid = FT_GET_USHORT();
+
+
+            /* this constant is given in the CFF specification */
+            if ( sid < 65000 )
+              charset->sids[j] = sid;
+            else
+            {
+              FT_ERROR(( "cff_charset_load:"
+                         " invalid SID value %d set to zero\n", sid ));
+              charset->sids[j] = 0;
+            }
+          }
 
           FT_FRAME_EXIT();
         }
@@ -875,6 +888,20 @@
                 goto Exit;
             }
 
+            /* check whether the range contains at least one valid glyph; */
+            /* the constant is given in the CFF specification             */
+            if ( glyph_sid >= 65000 ) {
+              FT_ERROR(( "cff_charset_load: invalid SID range\n" ));
+              error = CFF_Err_Invalid_File_Format;
+              goto Exit;
+            }
+
+            /* try to rescue some of the SIDs if `nleft' is too large */
+            if ( nleft > 65000 - 1 || glyph_sid >= 65000 - nleft ) {
+              FT_ERROR(( "cff_charset_load: invalid SID range trimmed\n" ));
+              nleft = 65000 - 1 - glyph_sid;
+            }
+
             /* Fill in the range of sids -- `nleft + 1' glyphs. */
             for ( i = 0; j < num_glyphs && i <= nleft; i++, j++, glyph_sid++ )
               charset->sids[j] = glyph_sid;
