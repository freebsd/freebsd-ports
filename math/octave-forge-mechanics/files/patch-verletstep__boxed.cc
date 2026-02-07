--- verletstep_boxed.cc.orig	2021-02-21 22:23:14 UTC
+++ verletstep_boxed.cc
@@ -65,12 +65,12 @@ DEFUN_DLD (verletstep_boxed, args, nargout, "Verlet ve
                 newargs(1) = V.row(ipart) - V.row(jpart);
 
                 if (fcn_str)
-                  retval = feval (args (4).string_value (), newargs, nargout);
+                  retval = octave::feval (args (4).string_value (), newargs, nargout);
                 else
                 {
                   fcn = args(4).function_value ();
                   if (! error_state)
-                    retval = feval (fcn, newargs, nargout);
+                    retval = octave::feval (fcn, newargs, nargout);
                 }
 
                 A.insert (retval(0).row_vector_value () + 
@@ -101,12 +101,12 @@ DEFUN_DLD (verletstep_boxed, args, nargout, "Verlet ve
                 newargs(1) = V.row(ipart) - V.row(jpart);
 
                 if (fcn_str)
-                  retval = feval (args (4).string_value (), newargs, nargout);
+                  retval = octave::feval (args (4).string_value (), newargs, nargout);
                 else
                 {
                   fcn = args(4).function_value ();
                   if (! error_state)
-                    retval = feval (fcn, newargs, nargout);
+                    retval = octave::feval (fcn, newargs, nargout);
                 }
 
                 A.insert (retval(0).row_vector_value () + 
