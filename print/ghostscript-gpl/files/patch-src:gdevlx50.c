--- src/gdevlx50.c.orig	Fri Dec 17 19:31:43 2004
+++ src/gdevlx50.c	Fri Dec 17 22:31:26 2004
@@ -1120,18 +1120,18 @@
 
 				/* Allocate a buffer for a single scan line */
 	    lineBuffer	= (byte *)gs_alloc_byte_array
-		( &gs_memory_default, lx5000dev->scanLineBytes, 1,
+		( lx5000dev->memory, lx5000dev->scanLineBytes, 1,
 		  "lx5000_print_page(lineBuffer)" );
 
 	    swipeBuf	= (byte *)gs_alloc_byte_array
-		( &gs_memory_default, lx5000dev->swipeBufSize, 1,
+		( lx5000dev->memory, lx5000dev->swipeBufSize, 1,
 		  "lx5000_print_page(swipeBuf)" );
 
 	    for ( colour = 0 ; colour < numColours; colour++ )
 	    {
 		if ( ( colourBufs[colour] =
 		       (byte *)gs_alloc_byte_array
-		       ( &gs_memory_default, lx5000dev->penBufSize, 1,
+		       ( lx5000dev->memory, lx5000dev->penBufSize, 1,
 			 "lx5000_print_page(colourBufs)"
 			 )
 		       ) == NULL )
@@ -1172,19 +1172,19 @@
 	for ( colour = 0; colour < numColours; colour++ )
 	{
 	    if ( colourBufs[colour] != NULL )
-		gs_free_object( &gs_memory_default,
+		gs_free_object( lx5000dev->memory,
 				(char *)colourBufs[colour],
 				"lx5000_print_page(colourBufs)" );
 	    colourBufs[ colour ]	= NULL;
 	    colourBufPtrs[ colour ]	= NULL;
 	}
 	if ( swipeBuf != NULL )
-	    gs_free_object( &gs_memory_default,
+	    gs_free_object( lx5000dev->memory,
 			    (char *)swipeBuf, "lx5000_print_page(swipeBuf)" );
 	swipeBuf	= NULL;
 	*swipeBufPtr	= NULL;
 	if ( lineBuffer != NULL )
-	    gs_free_object( &gs_memory_default,
+	    gs_free_object( lx5000dev->memory,
 		    (char *)lineBuffer, "lx5000_print_page(lineBuffer)" );
 	lineBuffer	= NULL;
 	*lineBufferPtr	= NULL;
@@ -2603,9 +2603,12 @@
 
 /* Map CMYK to color. */
 private gx_color_index
-lx5000_map_cmyk_color(gx_device * dev, gx_color_value cyan,
-	gx_color_value magenta, gx_color_value yellow, gx_color_value black)
+lx5000_map_cmyk_color(gx_device * dev, const gx_color_value cv[])
 {
+    gx_color_value cyan = cv[0];
+    gx_color_value magenta = cv[1];
+    gx_color_value yellow = cv[2];
+    gx_color_value black = cv[3];
     int bpc = dev->color_info.depth / 4;
     int drop = sizeof(gx_color_value) * 8 - bpc;
     gx_color_index color =
