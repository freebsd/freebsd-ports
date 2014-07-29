--- filewin.c.orig	Sat Jun 16 23:16:26 2001
+++ filewin.c	Sat Jun 16 23:17:06 2001
@@ -626,7 +626,7 @@
 				      sym_link_name
 				    );
 #else
-		      (void) sprintf( format, "%%c%%c%%-%ds %%10s %%3d %%7d %%12s -> %%-%ds", 
+		      (void) sprintf( format, "%%c%%c%%-%ds %%10s %%3d %%7qd %%12s -> %%-%ds", 
 				      max_filename_len,
 				      max_linkname_len
 				    );
@@ -661,7 +661,7 @@
 				      modify_time
 				    );
 #else
-		      (void) sprintf( format, "%%c%%c%%%c%ds %%10s %%3d %%7d %%12s", 
+		      (void) sprintf( format, "%%c%%c%%%c%ds %%10s %%3d %%7qd %%12s", 
                                       justify,
 				      max_filename_len 
 				    );
