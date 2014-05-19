--- partarray.cc.orig	2012-03-24 14:53:23.000000000 -0500
+++ partarray.cc	2014-05-17 13:05:40.000000000 -0500
@@ -39,9 +39,12 @@
   Array<int> nidx (dim_vector (maxdims, 1));
   // Octave-3.2.4 reports "missing symbol" with Array<Array< > >,
   // though 3.3.54+ does not
-  Array<octave_idx_type> bidc [maxdims], eidc [maxdims];
   //
   Array<octave_idx_type> step (dim_vector (maxdims, 1));
+  // Array<octave_idx_type> bidc [maxdims], eidc [maxdims];
+  Array<octave_idx_type> *bidc, *eidc;
+  bidc = new Array<octave_idx_type> [maxdims];
+  eidc = new Array<octave_idx_type> [maxdims];
   step(0) = 1;
   for (int i = 0; i < maxdims; i++)
     {
@@ -62,6 +65,8 @@
             {
               error ("%s: argument %i: wrong dimensions",
                      fname.c_str (), i + 2);
+              delete[](bidc);
+              delete[](eidc);
               return Cell ();
             }
           cnidx =
@@ -83,8 +88,11 @@
       if (i < maxdims - 1)
         step(i + 1) = step(i) * alldims(i);
     }
-  if (error_state)
+  if (error_state) {
+    delete[](bidc);
+    delete[](eidc);
     return Cell ();
+  }
 
   dim_vector rdv (nc, 1);
 
@@ -144,6 +152,8 @@
           }
     }
 
+  delete[](bidc);
+  delete[](eidc);
   return retval;
 }
 
