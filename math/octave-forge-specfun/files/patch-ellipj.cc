--- ellipj.cc.orig	2021-02-21 22:11:36 UTC
+++ ellipj.cc
@@ -190,7 +190,7 @@ return @code{NaN}.\n\
 
           if (u_arg.is_scalar_type ()) {   /*  u scalar */
             /*{{{*/
-            if (u_arg.is_real_type ()) {  // u real
+            if (u_arg.isreal ()) {  // u real
               double  u = args(0).double_value ();
 
               if (! error_state) {
@@ -265,7 +265,7 @@ return @code{NaN}.\n\
            int nc = m.cols ();
            Matrix err (nr, nc);
 
-           if (u_arg.is_real_type ()) {
+           if (u_arg.isreal ()) {
              double  u = u_arg.double_value ();
              Matrix sn (nr, nc), cn (nr, nc), dn (nr, nc);
              if (! error_state) {
@@ -296,7 +296,7 @@ return @code{NaN}.\n\
            /*}}}*/
          } else {    // u is matrix  (m is matrix)
            /*{{{*/
-           if (u_arg.is_real_type ()) {  // u real matrix
+           if (u_arg.isreal ()) {  // u real matrix
 
               Matrix u = u_arg.matrix_value ();
               if (! error_state) {
