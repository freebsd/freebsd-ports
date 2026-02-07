https://github.com/scimmia9286/aribb24/commit/58a34b8fabf4d0e9e1984fb603a97f52fb934a09
https://github.com/scimmia9286/aribb24/commit/fa54dee41aa38560f02868b24f911a24c33780a8
--- src/parser.c.orig	2019-09-16 15:57:19 UTC
+++ src/parser.c
@@ -79,7 +79,6 @@ static void parse_data_unit_DRCS( arib_parser_t *p_par
                                   uint8_t i_data_unit_parameter,
                                   uint32_t i_data_unit_size )
 {
-    p_parser->p_instance->p->i_drcs_num = 0;
 #ifdef ARIBSUB_GEN_DRCS_DATA
     if( p_parser->p_drcs_data != NULL )
     {
@@ -119,7 +118,7 @@ static void parse_data_unit_DRCS( arib_parser_t *p_par
 
     for( int i = 0; i < i_NumberOfCode; i++ )
     {
-        bs_skip( p_bs, 16 ); /* i_character_code */
+        int16_t i_CharacterCode = bs_read( p_bs, 16 ); /* i_character_code */
         p_parser->i_data_unit_size += 2;
         uint8_t i_NumberOfFont = bs_read( p_bs, 8 );
         p_parser->i_data_unit_size += 1;
@@ -139,7 +138,11 @@ static void parse_data_unit_DRCS( arib_parser_t *p_par
 
         for( int j = 0; j < i_NumberOfFont; j++ )
         {
+#ifdef ARIBSUB_GEN_DRCS_DATA
+            int8_t i_fontId = bs_read( p_bs, 4 ); /* i_fontID */
+#else
             bs_skip( p_bs, 4 ); /* i_fontID */
+#endif //ARUBSUB_GEN_DRCS_DATA
             uint8_t i_mode = bs_read( p_bs, 4 );
             p_parser->i_data_unit_size += 1;
 
@@ -206,18 +209,26 @@ static void parse_data_unit_DRCS( arib_parser_t *p_par
 
 #ifdef ARIBSUB_GEN_DRCS_DATA
                 save_drcs_pattern( p_parser->p_instance, i_width, i_height, i_depth + 2,
-                                   p_drcs_pattern_data->p_patternData );
+                                   p_drcs_pattern_data->p_patternData, i_CharacterCode );
 #else
                 save_drcs_pattern( p_parser->p_instance, i_width, i_height, i_depth + 2,
-                                   p_patternData );
+                                   p_patternData, i_CharacterCode );
                 free( p_patternData );
 #endif //ARIBSUB_GEN_DRCS_DATA
             }
             else
             {
+#ifdef ARIBSUB_GEN_DRCS_DATA
+                int8_t i_regionX = bs_read( p_bs, 8 ); /* i_regionX */
+#else
                 bs_skip( p_bs, 8 ); /* i_regionX */
+#endif //ARIBSUB_GEN_DRCS_DATA
                 p_parser->i_data_unit_size += 1;
+#ifdef ARIBSUB_GEN_DRCS_DATA
+                int8_t i_regionY = bs_read( p_bs, 8 ); /* i_regionY */
+#else
                 bs_skip( p_bs, 8 ); /* i_regionY */
+#endif //ARIBSUB_GEN_DRCS_DATA
                 p_parser->i_data_unit_size += 1;
                 uint16_t i_geometricData_length = bs_read( p_bs, 16 );
                 p_parser->i_data_unit_size += 2;
@@ -245,7 +256,11 @@ static void parse_data_unit_DRCS( arib_parser_t *p_par
 
                 for( int k = 0; k < i_geometricData_length ; k++ )
                 {
+#ifdef ARIBSUB_GEN_DRCS_DATA
+                    int8_t i_geometricData = bs_read( p_bs, 8 ); /* i_geometric_data */
+#else
                     bs_skip( p_bs, 8 ); /* i_geometric_data */
+#endif //ARIBSUB_GEN_DRCS_DATA
                     p_parser->i_data_unit_size += 1;
 
 #ifdef ARIBSUB_GEN_DRCS_DATA
@@ -344,6 +359,10 @@ static void parse_caption_management_data( arib_parser
     p_parser->i_data_unit_size = 0;
     p_parser->i_subtitle_data_size = 0;
     p_parser->psz_subtitle_data = NULL;
+    memset(p_parser->p_instance->p->i_drcs_num, 0,
+                        sizeof(p_parser->p_instance->p->i_drcs_num));
+    memset(p_parser->p_instance->p->drcs_hash_table, 0,
+                        sizeof(p_parser->p_instance->p->drcs_hash_table));
     if( i_data_unit_loop_length > 0 )
     {
         p_parser->psz_subtitle_data = (unsigned char*) calloc(
