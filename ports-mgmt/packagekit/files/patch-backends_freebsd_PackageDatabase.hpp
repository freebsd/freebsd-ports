--- backends/freebsd/PackageDatabase.hpp.orig	2026-04-22 10:56:14 UTC
+++ backends/freebsd/PackageDatabase.hpp
@@ -255,7 +255,7 @@ class PackageDatabase { (private)
 
         // We don't want libpkg to interactively ask us questions about OS
         // versions mismatch. Provide a default "no" reply.
-        pkg_set_ignore_osversion (FALSE);
+        pkg_set_ignore_osversion (TRUE);
     }
 
     struct cleanup_cb
