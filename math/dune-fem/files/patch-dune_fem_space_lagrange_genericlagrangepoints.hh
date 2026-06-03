--- dune/fem/space/lagrange/genericlagrangepoints.hh	2026-03-31 03:33:40.502407000 -0700
+++ dune/fem/space/lagrange/genericlagrangepoints.hh	2026-03-31 03:36:29.065524000 -0700
@@ -428,7 +428,7 @@
         if( !useDimReduction( coordinate ) )
         {
           --(*coordinate);
-          OrderReductionType::template dofSubEntity( coordinate, codim, subEntity, dofNumber );
+          OrderReductionType::dofSubEntity( coordinate, codim, subEntity, dofNumber );
           ++(*coordinate);
 
           if( bottom )
