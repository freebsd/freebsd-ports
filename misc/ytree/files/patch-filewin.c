--- filewin.c.orig
+++ filewin.c
@@ -92,14 +92,14 @@
     case MODE_1: len =  (max_visual_linkname_len) ? max_visual_linkname_len + 4 : 0; /* linkname + " -> " */
 		 len += max_visual_filename_len + 38; /* filename + format */
 #ifdef HAS_LONGLONG
-                 len += 4;  /* %11lld instead of %7d */
+                 len += 4;  /* %11lld instead of %7qd */
 #endif
                  break;
 
     case MODE_2: len =  (max_visual_linkname_len) ? max_visual_linkname_len + 4 : 0; /* linkname + " -> " */
 		 len += max_visual_filename_len + 40; /* filename + format */
 #ifdef HAS_LONGLONG
-                 len += 4;  /* %11lld instead of %7d */
+                 len += 4;  /* %11lld instead of %7qd */
 #endif
                  break;
 
@@ -602,7 +602,7 @@
 				      sym_link_name
 				    );
 #else
-		      (void) sprintf( format, "%%c%%c%%-%ds %%10s %%3d %%7d %%12s -> %%-%ds", 
+		      (void) sprintf( format, "%%c%%c%%-%ds %%10s %%3d %%7qd %%12s -> %%-%ds", 
 				      filename_width,
 				      linkname_width
 				    );
@@ -637,7 +637,7 @@
 				      modify_time
 				    );
 #else
-		      (void) sprintf( format, "%%c%%c%%%c%ds %%10s %%3d %%7d %%12s", 
+		      (void) sprintf( format, "%%c%%c%%%c%ds %%10s %%3d %%7qd %%12s", 
                                       justify,
 				      filename_width 
 				    );
