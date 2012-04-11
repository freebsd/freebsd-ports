--- odepkg_auxiliary_functions.cc-orig	2012-03-30 23:51:38.000000000 +0000
+++ odepkg_auxiliary_functions.cc	2012-03-30 23:52:36.000000000 +0000
@@ -454,8 +454,8 @@
       // eg. if the code should be debuged or something like this
       vt = octave_value (vtstore);
       vy = octave_value (vystore);
-      vt.print_with_name (octave_stdout, "vt", true);
-      vy.print_with_name (octave_stdout, "vy", true);
+      vt.print_with_name (octave_stdout, "vt");
+      vy.print_with_name (octave_stdout, "vy");
       break;
   }
 
