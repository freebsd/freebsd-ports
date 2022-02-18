--- lib/nn/delaunay.c.orig	2019-06-01 23:24:33 UTC
+++ lib/nn/delaunay.c
@@ -35,7 +35,7 @@
 #include <float.h>
 #ifdef USE_QHULL
 #ifdef HAS_LIBQHULL_INCLUDE
-#include <libqhull/qhull_a.h>
+#include <libqhull_r/qhull_ra.h>
 #else
 #include <qhull/qhull_a.h>
 #endif
@@ -388,7 +388,9 @@ delaunay* delaunay_build( int np, point points[], int 
     // climax
     //
 
-    exitcode = qh_new_qhull( dim, np, qpoints, ismalloc,
+    qhT context = { 0 };
+    qhT *qh = &context;
+    exitcode = qh_new_qhull(qh, dim, np, qpoints, ismalloc,
         flags, outfile, errfile );
 
     if ( !exitcode )
@@ -433,8 +435,8 @@ delaunay* delaunay_build( int np, point points[], int 
             }
         }
 
-        qh_findgood_all( qh facet_list );
-        qh_countfacets( qh facet_list, NULL, !qh_ALL, &numfacets,
+        qh_findgood_all (qh, qh->facet_list);
+        qh_countfacets(qh, qh->facet_list, NULL, !qh_ALL, &numfacets,
             &numsimplicial, &totneighbors, &numridges,
             &numcoplanars, &numtricoplanars );
 
@@ -462,7 +464,7 @@ delaunay* delaunay_build( int np, point points[], int 
 
                 j = 0;
                 FOREACHvertex_( facet->vertices )
-                t->vids[j++] = qh_pointid( vertex->point );
+                t->vids[j++] = qh_pointid(qh, vertex->point );
 
                 j = 0;
                 FOREACHneighbor_( facet )
@@ -548,8 +550,8 @@ delaunay* delaunay_build( int np, point points[], int 
     }
 
     free( qpoints );
-    qh_freeqhull( !qh_ALL );               // free long memory
-    qh_memfreeshort( &curlong, &totlong ); // free short memory and memory allocator
+    qh_freeqhull(qh, !qh_ALL );               // free long memory
+    qh_memfreeshort(qh, &curlong, &totlong ); // free short memory and memory allocator
     if ( curlong || totlong )
         fprintf( errfile,
             "qhull: did not free %d bytes of long memory (%d pieces)\n",
