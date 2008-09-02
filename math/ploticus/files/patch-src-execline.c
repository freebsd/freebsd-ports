--- src/execline.c.orig	2008-09-03 00:52:18.000000000 -0500
+++ src/execline.c	2008-09-03 00:53:46.000000000 -0500
@@ -352,7 +352,7 @@
 if( PLS.eready ) Eflush();
 n = report_convmsgcount();
 if( PLS.debug && n > 0 ) {
-	fprintf( PLS.diagfp, "note: pl proc %s encountered %d unplottable data values\n", procname, n );
+	fprintf( PLS.diagfp, "note: ploticus proc %s encountered %d unplottable data values\n", procname, n );
 	zero_convmsgcount();
 	}
 return( stat );
