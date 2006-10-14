--- src/pcf/pcfread.c.orig	2006-01-23 17:35:18.000000000 +0100
+++ src/pcf/pcfread.c
@@ -102,7 +102,8 @@ THE SOFTWARE.
       return PCF_Err_Cannot_Open_Resource;
 
     if ( toc->version != PCF_FILE_VERSION                 ||
-         toc->count   >  FT_ARRAY_MAX( face->toc.tables ) )
+         toc->count   >  FT_ARRAY_MAX( face->toc.tables ) ||
+         toc->count   == 0                                )
       return PCF_Err_Invalid_File_Format;
 
     if ( FT_NEW_ARRAY( face->toc.tables, toc->count ) )
@@ -116,6 +117,41 @@ THE SOFTWARE.
       tables++;
     }
 
+    /* Sort tables and check for overlaps.  Because they are almost      */
+    /* always ordered already, an in-place bubble sort with simultaneous */
+    /* boundary checking seems appropriate.                              */
+    tables = face->toc.tables;
+
+    for ( n = 0; n < toc->count - 1; n++ )
+    {
+      FT_UInt  i, have_change;
+
+
+      have_change = 0;
+
+      for ( i = 0; i < toc->count - 1 - n; i++ )
+      {
+        PCF_TableRec  tmp;
+
+
+        if ( tables[i].offset > tables[i + 1].offset )
+        {
+          tmp           = tables[i];
+          tables[i]     = tables[i + 1];
+          tables[i + 1] = tmp;
+
+          have_change = 1;
+        }
+
+        if ( ( tables[i].size   > tables[i + 1].offset )                  ||
+             ( tables[i].offset > tables[i + 1].offset - tables[i].size ) )
+          return PCF_Err_Invalid_Offset;
+      }
+
+      if ( !have_change )
+        break;
+    }
+
 #if defined( FT_DEBUG_LEVEL_TRACE )
 
     {
@@ -130,7 +166,8 @@ THE SOFTWARE.
       tables = face->toc.tables;
       for ( i = 0; i < toc->count; i++ )
       {
-        for( j = 0; j < sizeof ( tableNames ) / sizeof ( tableNames[0] ); j++ )
+        for ( j = 0; j < sizeof ( tableNames ) / sizeof ( tableNames[0] );
+              j++ )
           if ( tables[i].type == (FT_UInt)( 1 << j ) )
             name = tableNames[j];
 
@@ -153,13 +190,15 @@ THE SOFTWARE.
   }
 
 
+#define PCF_METRIC_SIZE  12
+
   static
   const FT_Frame_Field  pcf_metric_header[] =
   {
 #undef  FT_STRUCTURE
 #define FT_STRUCTURE  PCF_MetricRec
 
-    FT_FRAME_START( 12 ),
+    FT_FRAME_START( PCF_METRIC_SIZE ),
       FT_FRAME_SHORT_LE( leftSideBearing ),
       FT_FRAME_SHORT_LE( rightSideBearing ),
       FT_FRAME_SHORT_LE( characterWidth ),
@@ -176,7 +215,7 @@ THE SOFTWARE.
 #undef  FT_STRUCTURE
 #define FT_STRUCTURE  PCF_MetricRec
 
-    FT_FRAME_START( 12 ),
+    FT_FRAME_START( PCF_METRIC_SIZE ),
       FT_FRAME_SHORT( leftSideBearing ),
       FT_FRAME_SHORT( rightSideBearing ),
       FT_FRAME_SHORT( characterWidth ),
@@ -187,13 +226,15 @@ THE SOFTWARE.
   };
 
 
+#define PCF_COMPRESSED_METRIC_SIZE  5
+
   static
   const FT_Frame_Field  pcf_compressed_metric_header[] =
   {
 #undef  FT_STRUCTURE
 #define FT_STRUCTURE  PCF_Compressed_MetricRec
 
-    FT_FRAME_START( 5 ),
+    FT_FRAME_START( PCF_COMPRESSED_METRIC_SIZE ),
       FT_FRAME_BYTE( leftSideBearing ),
       FT_FRAME_BYTE( rightSideBearing ),
       FT_FRAME_BYTE( characterWidth ),
@@ -221,7 +262,7 @@ THE SOFTWARE.
                ? pcf_metric_msb_header
                : pcf_metric_header;
 
-      /* the following sets 'error' but doesn't return in case of failure */
+      /* the following sets `error' but doesn't return in case of failure */
       (void)FT_STREAM_READ_FIELDS( fields, metric );
     }
     else
@@ -261,17 +302,19 @@ THE SOFTWARE.
     for ( i = 0; i < ntables; i++ )
       if ( tables[i].type == type )
       {
-        if ( stream->pos > tables[i].offset ) {
+        if ( stream->pos > tables[i].offset )
+        {
           error = PCF_Err_Invalid_Stream_Skip;
           goto Fail;
         }
 
-        if ( FT_STREAM_SKIP( tables[i].offset - stream->pos ) ) {
+        if ( FT_STREAM_SKIP( tables[i].offset - stream->pos ) )
+        {
           error = PCF_Err_Invalid_Stream_Skip;
           goto Fail;
         }
 
-        *asize   = tables[i].size;  /* unused - to be removed */
+        *asize   = tables[i].size;
         *aformat = tables[i].format;
 
         return PCF_Err_Ok;
@@ -298,13 +341,15 @@ THE SOFTWARE.
   }
 
 
+#define PCF_PROPERTY_SIZE  9
+
   static
   const FT_Frame_Field  pcf_property_header[] =
   {
 #undef  FT_STRUCTURE
 #define FT_STRUCTURE  PCF_ParsePropertyRec
 
-    FT_FRAME_START( 9 ),
+    FT_FRAME_START( PCF_PROPERTY_SIZE ),
       FT_FRAME_LONG_LE( name ),
       FT_FRAME_BYTE   ( isString ),
       FT_FRAME_LONG_LE( value ),
@@ -318,7 +363,7 @@ THE SOFTWARE.
 #undef  FT_STRUCTURE
 #define FT_STRUCTURE  PCF_ParsePropertyRec
 
-    FT_FRAME_START( 9 ),
+    FT_FRAME_START( PCF_PROPERTY_SIZE ),
       FT_FRAME_LONG( name ),
       FT_FRAME_BYTE( isString ),
       FT_FRAME_LONG( value ),
@@ -353,8 +398,8 @@ THE SOFTWARE.
                       PCF_Face   face )
   {
     PCF_ParseProperty  props      = 0;
-    PCF_Property       properties = 0;
-    FT_Int             nprops, i;
+    PCF_Property       properties;
+    FT_UInt            nprops, i;
     FT_ULong           format, size;
     FT_Error           error;
     FT_Memory          memory     = FT_FACE(face)->memory;
@@ -390,6 +435,15 @@ THE SOFTWARE.
 
     FT_TRACE4(( "  nprop = %d\n", nprops ));
 
+    /* rough estimate */
+    if ( nprops > size / PCF_PROPERTY_SIZE )
+    {
+      error = PCF_Err_Invalid_Table;
+      goto Bail;
+    }
+
+    face->nprops = nprops;
+
     if ( FT_NEW_ARRAY( props, nprops ) )
       goto Bail;
 
@@ -427,6 +481,13 @@ THE SOFTWARE.
 
     FT_TRACE4(( "  string_size = %ld\n", string_size ));
 
+    /* rough estimate */
+    if ( string_size > size - nprops * PCF_PROPERTY_SIZE )
+    {
+      error = PCF_Err_Invalid_Table;
+      goto Bail;
+    }
+
     if ( FT_NEW_ARRAY( strings, string_size ) )
       goto Bail;
 
@@ -437,13 +498,24 @@ THE SOFTWARE.
     if ( FT_NEW_ARRAY( properties, nprops ) )
       goto Bail;
 
+    face->properties = properties;
+
     for ( i = 0; i < nprops; i++ )
     {
-      /* XXX: make atom */
+      FT_Long  name_offset = props[i].name;
+
+
+      if ( ( name_offset < 0 )                     ||
+           ( (FT_ULong)name_offset > string_size ) )
+      {
+        error = PCF_Err_Invalid_Offset;
+        goto Bail;
+      }
+
       if ( FT_NEW_ARRAY( properties[i].name,
-                         ft_strlen( strings + props[i].name ) + 1 ) )
+                         ft_strlen( strings + name_offset ) + 1 ) )
         goto Bail;
-      ft_strcpy( properties[i].name, strings + props[i].name );
+      ft_strcpy( properties[i].name, strings + name_offset );
 
       FT_TRACE4(( "  %s:", properties[i].name ));
 
@@ -451,8 +523,18 @@ THE SOFTWARE.
 
       if ( props[i].isString )
       {
+        FT_Long  value_offset = props[i].value;
+
+
+        if ( ( value_offset < 0 )                     ||
+             ( (FT_ULong)value_offset > string_size ) )
+        {
+          error = PCF_Err_Invalid_Offset;
+          goto Bail;
+        }
+
         if ( FT_NEW_ARRAY( properties[i].value.atom,
-                           ft_strlen( strings + props[i].value ) + 1 ) )
+                           ft_strlen( strings + value_offset ) + 1 ) )
           goto Bail;
         ft_strcpy( properties[i].value.atom, strings + props[i].value );
 
@@ -466,14 +548,8 @@ THE SOFTWARE.
       }
     }
 
-    face->properties = properties;
-    face->nprops = nprops;
-
-    FT_FREE( props );
-    FT_FREE( strings );
-
-    return PCF_Err_Ok;
-
+    error = PCF_Err_Ok;
+    
   Bail:
     FT_FREE( props );
     FT_FREE( strings );
@@ -488,11 +564,9 @@ THE SOFTWARE.
   {
     FT_Error    error    = PCF_Err_Ok;
     FT_Memory   memory   = FT_FACE(face)->memory;
-    FT_ULong    format   = 0;
-    FT_ULong    size     = 0;
+    FT_ULong    format, size;
     PCF_Metric  metrics  = 0;
-    int         i;
-    int         nmetrics = -1;
+    FT_ULong    nmetrics, i;
 
 
     error = pcf_seek_to_table_type( stream,
@@ -504,7 +578,8 @@ THE SOFTWARE.
     if ( error )
       return error;
 
-    error = FT_READ_ULONG_LE( format );
+    if ( FT_READ_ULONG_LE( format ) )
+      goto Bail;
 
     if ( !PCF_FORMAT_MATCH( format, PCF_DEFAULT_FORMAT )     &&
          !PCF_FORMAT_MATCH( format, PCF_COMPRESSED_METRICS ) )
@@ -524,16 +599,30 @@ THE SOFTWARE.
       else
         (void)FT_READ_USHORT_LE( nmetrics );
     }
-    if ( error || nmetrics == -1 )
+    if ( error )
       return PCF_Err_Invalid_File_Format;
 
     face->nmetrics = nmetrics;
 
+    FT_TRACE4(( "pcf_get_metrics:\n" ));
+
+    FT_TRACE4(( "  number of metrics: %d\n", nmetrics ));
+
+    /* rough estimate */
+    if ( PCF_FORMAT_MATCH( format, PCF_DEFAULT_FORMAT ) )
+    {
+      if ( nmetrics > size / PCF_METRIC_SIZE )
+        return PCF_Err_Invalid_Table;
+    }
+    else
+    {
+      if ( nmetrics > size / PCF_COMPRESSED_METRIC_SIZE )
+        return PCF_Err_Invalid_Table;
+    }
+
     if ( FT_NEW_ARRAY( face->metrics, nmetrics ) )
       return PCF_Err_Out_Of_Memory;
 
-    FT_TRACE4(( "pcf_get_metrics:\n" ));
-
     metrics = face->metrics;
     for ( i = 0; i < nmetrics; i++ )
     {
@@ -541,7 +630,7 @@ THE SOFTWARE.
 
       metrics[i].bits = 0;
 
-      FT_TRACE4(( "  idx %d: width=%d, "
+      FT_TRACE5(( "  idx %d: width=%d, "
                   "lsb=%d, rsb=%d, ascent=%d, descent=%d, swidth=%d\n",
                   i,
                   ( metrics + i )->characterWidth,
@@ -557,6 +646,8 @@ THE SOFTWARE.
 
     if ( error )
       FT_FREE( face->metrics );
+
+  Bail:
     return error;
   }
 
@@ -597,14 +688,16 @@ THE SOFTWARE.
     if ( !PCF_FORMAT_MATCH( format, PCF_DEFAULT_FORMAT ) )
       return PCF_Err_Invalid_File_Format;
 
+    FT_TRACE4(( "pcf_get_bitmaps:\n" ));
+
+    FT_TRACE4(( "  number of bitmaps: %d\n", nbitmaps ));
+
     if ( nbitmaps != face->nmetrics )
       return PCF_Err_Invalid_File_Format;
 
     if ( FT_NEW_ARRAY( offsets, nbitmaps ) )
       return error;
 
-    FT_TRACE4(( "pcf_get_bitmaps:\n" ));
-
     for ( i = 0; i < nbitmaps; i++ )
     {
       if ( PCF_BYTE_ORDER( format ) == MSBFirst )
@@ -612,7 +705,7 @@ THE SOFTWARE.
       else
         (void)FT_READ_LONG_LE( offsets[i] );
 
-      FT_TRACE4(( "  bitmap %d: offset %ld (0x%lX)\n",
+      FT_TRACE5(( "  bitmap %d: offset %ld (0x%lX)\n",
                   i, offsets[i], offsets[i] ));
     }
     if ( error )
@@ -640,15 +733,22 @@ THE SOFTWARE.
     FT_UNUSED( sizebitmaps );       /* only used for debugging */
 
     for ( i = 0; i < nbitmaps; i++ )
-      face->metrics[i].bits = stream->pos + offsets[i];
+    {
+      /* rough estimate */
+      if ( ( offsets[i] < 0 )              ||
+           ( (FT_ULong)offsets[i] > size ) )
+      {
+        FT_ERROR(( "pcf_get_bitmaps:"));
+        FT_ERROR(( " invalid offset to bitmap data of glyph %d\n", i ));
+      }
+      else
+        face->metrics[i].bits = stream->pos + offsets[i];
+    }
 
     face->bitmapsFormat = format;
 
-    FT_FREE ( offsets );
-    return error;
-
   Bail:
-    FT_FREE ( offsets );
+    FT_FREE( offsets );
     return error;
   }
 
@@ -734,7 +834,7 @@ THE SOFTWARE.
 
         tmpEncoding[j].glyph = (FT_Short)encodingOffset;
 
-        FT_TRACE4(( "  code %d (0x%04X): idx %d\n",
+        FT_TRACE5(( "  code %d (0x%04X): idx %d\n",
                     tmpEncoding[j].enc, tmpEncoding[j].enc,
                     tmpEncoding[j].glyph ));
 
@@ -828,7 +928,8 @@ THE SOFTWARE.
     if ( error )
       goto Bail;
 
-    error = FT_READ_ULONG_LE( format );
+    if ( FT_READ_ULONG_LE( format ) )
+      goto Bail;
 
     if ( !PCF_FORMAT_MATCH( format, PCF_DEFAULT_FORMAT )    &&
          !PCF_FORMAT_MATCH( format, PCF_ACCEL_W_INKBOUNDS ) )
@@ -876,7 +977,6 @@ THE SOFTWARE.
       accel->ink_minbounds = accel->minbounds; /* I'm not sure about this */
       accel->ink_maxbounds = accel->maxbounds;
     }
-    return error;
 
   Bail:
     return error;
@@ -1082,11 +1182,12 @@ THE SOFTWARE.
       else
         root->family_name = NULL;
 
-      /* Note: We shift all glyph indices by +1 since we must
+      /* 
+       * Note: We shift all glyph indices by +1 since we must
        * respect the convention that glyph 0 always corresponds
-       * to the "missing glyph".
+       * to the `missing glyph'.
        *
-       * This implies bumping the number of "available" glyphs by 1.
+       * This implies bumping the number of `available' glyphs by 1.
        */
       root->num_glyphs = face->nmetrics + 1;
 
@@ -1171,7 +1272,7 @@ THE SOFTWARE.
   Exit:
     if ( error )
     {
-      /* this is done to respect the behaviour of the original */
+      /* This is done to respect the behaviour of the original */
       /* PCF font driver.                                      */
       error = PCF_Err_Invalid_File_Format;
     }
