https://github.com/scimmia9286/aribb24/commit/58a34b8fabf4d0e9e1984fb603a97f52fb934a09
https://github.com/scimmia9286/aribb24/commit/fa54dee41aa38560f02868b24f911a24c33780a8
--- src/drcs.c.orig	2019-09-16 15:57:19 UTC
+++ src/drcs.c
@@ -127,32 +127,39 @@ static bool create_arib_datadir( arib_instance_t *p_in
 
 bool apply_drcs_conversion_table( arib_instance_t *p_instance )
 {
-    for( int i = 0; i < p_instance->p->i_drcs_num; i++ )
+    for( int i = 0; i < 15; i++ )
     {
-        unsigned int uc = 0;
-        drcs_conversion_t *p_drcs_conv = p_instance->p->p_drcs_conv;
-        while( p_drcs_conv != NULL )
+        for( int j = 0; j < p_instance->p->i_drcs_num[i]; j++ )
         {
-            if( strcmp( p_drcs_conv->hash, p_instance->p->drcs_hash_table[i] ) == 0 )
+            if (p_instance->p->drcs_hash_table[i][j][0] != 0)
             {
-                uc = p_drcs_conv->code;
-                break;
-            }
-            p_drcs_conv = p_drcs_conv->p_next;
-        }
+                unsigned int uc = 0;
+                drcs_conversion_t *p_drcs_conv = p_instance->p->p_drcs_conv;
+                while( p_drcs_conv != NULL )
+                {
+                    if( strcmp( p_drcs_conv->hash, p_instance->p->drcs_hash_table[i][j] ) == 0 )
+                    {
+                        uc = p_drcs_conv->code;
+                        break;
+                    }
+                    p_drcs_conv = p_drcs_conv->p_next;
+                }
+
 #ifdef DEBUG_ARIBSUB
-        if( uc )
-        {
-            arib_log( p_instance, "Mapping [%s=U+%04x] will be used.",
-                      p_instance->p->drcs_hash_table[i], uc );
-        }
-        else
-        {
-            arib_log( p_instance, "Mapping for hash[%s] is not found.",
-                      p_instance->p->drcs_hash_table[i] );
-        }
+                if( uc )
+                {
+                    arib_log( p_instance, "Mapping [%s=U+%04x] will be used.",
+                              p_instance->p->drcs_hash_table[i][j], uc );
+                }
+                else
+                {
+                    arib_log( p_instance, "Mapping for hash[%s] is not found.",
+                              p_instance->p->drcs_hash_table[i][j] );
+                }
 #endif
-        p_instance->p->drcs_conv_table[i] = uc;
+                p_instance->p->drcs_conv_table[i][j] = uc;
+            }
+        }
     }
     return true;
 }
@@ -406,15 +413,19 @@ png_create_write_struct_failed:
 void save_drcs_pattern(
         arib_instance_t *p_instance,
         int i_width, int i_height,
-        int i_depth, const int8_t* p_patternData )
+        int i_depth, const int8_t* p_patternData,
+	int16_t i_CharacterCode )
 {
+    int i_drcsPlane = ((i_CharacterCode >> 8) & 0xff) - 0x40;
+    int i_code = (i_CharacterCode & 0xff) - 0x20;
     char* psz_hash = get_drcs_pattern_data_hash( p_instance,
             i_width, i_height, i_depth, p_patternData );
 
-    strncpy( p_instance->p->drcs_hash_table[p_instance->p->i_drcs_num], psz_hash, 32 );
-    p_instance->p->drcs_hash_table[p_instance->p->i_drcs_num][32] = '\0';
+    strncpy( p_instance->p->drcs_hash_table[i_drcsPlane-1][i_code-1], psz_hash, 32 );
+    p_instance->p->drcs_hash_table[i_drcsPlane-1][i_code-1][32] = '\0';
 
-    p_instance->p->i_drcs_num++;
+    p_instance->p->i_drcs_num[i_drcsPlane-1] = i_code > p_instance->p->i_drcs_num[i_drcsPlane-1] ?
+                                i_code : p_instance->p->i_drcs_num[i_drcsPlane-1];
 
     save_drcs_pattern_data_image( p_instance, psz_hash,
             i_width, i_height, i_depth, p_patternData );
