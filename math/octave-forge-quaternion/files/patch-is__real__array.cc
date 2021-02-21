--- is_real_array.cc.orig	2021-02-21 22:03:11 UTC
+++ is_real_array.cc
@@ -46,8 +46,8 @@ Avoid nasty stuff like @code{true = isreal (\"a\")}.\n
         {
             // args(i).ndims () should be always >= 2
             if (args(i).ndims () < 2
-                || ! ((args(i).is_numeric_type () && args(i).is_real_type ())
-                      || args(i).is_bool_type ()))
+                || ! ((args(i).isnumeric () && args(i).isreal ())
+                      || args(i).islogical ()))
             {
                 retval = false;
                 break;
