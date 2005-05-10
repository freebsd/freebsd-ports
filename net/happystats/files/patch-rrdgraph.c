--- rrdgraph.c.orig	Sun Feb  8 20:18:11 2004
+++ rrdgraph.c	Tue May 10 12:44:14 2005
@@ -13,6 +13,7 @@
 	char **calcpr;
 	int xsize, ysize ; 
 	/* int  end ; */
+	double ymin, ymax;
 
 	short unit_sec ;
 
@@ -237,7 +238,7 @@
 	/* Create Graph from rrd file and config */
 	optind = 0;
 	rrd_clear_error();
-	rc = rrd_graph(rrdargc,rrdcmd,&calcpr, &xsize, &ysize);
+	rc = rrd_graph(rrdargc,rrdcmd,&calcpr, &xsize, &ysize, NULL, &ymin, &ymax);
     
     
 	/* Check for Errors */
