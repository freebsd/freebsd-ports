--- search.c.orig
+++ search.c
@@ -520,11 +520,11 @@
               r != sorted.end() && max_results-- > 0 && out; ++r
         ) {
             // cast gets rid of warning
-            int rank = static_cast<int>( r->second * normalize );
-            if ( !rank )
-                rank = 1;
+            int my_rank = static_cast<int>( r->second * normalize );
+            if ( !my_rank )
+                my_rank = 1;
             format->result(
-                rank,
+                my_rank,
                 file_info(
                     reinterpret_cast<unsigned char const*>( files[ r->first ] )
                 )
