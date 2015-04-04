--- src/EOFs.c.orig	2015-03-26 15:40:12.000000000 +0800
+++ src/EOFs.c	2015-04-04 04:31:05.863824152 +0800
@@ -378,7 +378,7 @@
 	      npack = 0;
 	      for ( i = 0; i < gridsize; ++i )
 		{
-		  if ( !DBL_IS_EQUAL(weight[i], 0) && !DBL_IS_EQUAL(weight[i], missval) &&
+		  if ( !DBL_IS_EQUAL(weight[i], (double)0) && !DBL_IS_EQUAL(weight[i], missval) &&
 		       !DBL_IS_EQUAL(in[i], missval) )
 		    pack[npack++] = i;
 		}
@@ -393,7 +393,7 @@
 	  ipack = 0;
 	  for ( i = 0; i < gridsize; ++i )
 	    {
-	      if ( !DBL_IS_EQUAL(weight[i], 0) && !DBL_IS_EQUAL(weight[i], missval) &&
+	      if ( !DBL_IS_EQUAL(weight[i], (double)0) && !DBL_IS_EQUAL(weight[i], missval) &&
 		   !DBL_IS_EQUAL(in[i], missval) && pack[ipack++] != i )
 		{
 		  cdoAbort("Missing values unsupported!");
