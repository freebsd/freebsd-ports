Index: src/truetype/ttgload.c
===================================================================
RCS file: /cvsroot/freetype/freetype2/src/truetype/ttgload.c,v
retrieving revision 1.131
retrieving revision 1.132
diff -u -r1.131 -r1.132
--- src/truetype/ttgload.c	13 Oct 2004 05:15:44 -0000	1.131
+++ src/truetype/ttgload.c	19 Nov 2004 10:35:52 -0000	1.132
@@ -797,12 +797,10 @@
     if ( IS_HINTED( load->load_flags ) )
     {
       FT_Pos  x = zone->org[n_points-4].x;
-      FT_Pos  y = zone->org[n_points-2].y;
 
 
       x = FT_PIX_ROUND( x ) - x;
-      y = FT_PIX_ROUND( y ) - y;
-      translate_array( n_points, zone->org, x, y );
+      translate_array( n_points, zone->org, x, 0 );
 
       org_to_cur( n_points, zone );
 
