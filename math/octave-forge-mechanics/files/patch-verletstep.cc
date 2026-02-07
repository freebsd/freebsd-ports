--- verletstep.cc.orig	2021-02-21 22:24:16 UTC
+++ verletstep.cc
@@ -45,12 +45,12 @@ DEFUN_DLD (verletstep, args, nargout, "Verlet velocity
                 newargs(3) = V.row(jpart);
 
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
@@ -82,12 +82,12 @@ DEFUN_DLD (verletstep, args, nargout, "Verlet velocity
                 newargs(3) = V.row(jpart);
 
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
