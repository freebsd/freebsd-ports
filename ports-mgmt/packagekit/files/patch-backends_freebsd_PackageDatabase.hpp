--- backends/freebsd/PackageDatabase.hpp.orig	2026-01-28 19:54:23 UTC
+++ backends/freebsd/PackageDatabase.hpp
@@ -252,6 +252,10 @@ class PackageDatabase { (private)
             if (lockType != PKGDB_LOCK_READONLY)
                 pk_backend_job_set_locked (job, FALSE);
         });
+
+        // We don't want libpkg to interactively ask us questions about OS
+        // versions mismatch. Provide a default "no" reply.
+        pkg_set_ignore_osversion (FALSE);
     }
 
     struct cleanup_cb
