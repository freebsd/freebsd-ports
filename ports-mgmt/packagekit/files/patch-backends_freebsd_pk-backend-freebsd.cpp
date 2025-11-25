--- backends/freebsd/pk-backend-freebsd.cpp.orig	2025-10-02 19:55:22 UTC
+++ backends/freebsd/pk-backend-freebsd.cpp
@@ -859,7 +859,7 @@ pk_backend_install_update_packages_thread (PkBackendJo
     names.reserve (size);
     for (guint i = 0; i < size; i++) {
         PackageView pkg(package_ids[i]);
-        names.push_back(g_strdup(pkg.nameversion()));
+        names.push_back(installRole ? g_strdup(pkg.nameversion()) : g_strdup(pkg.name()));
     }
 
     jobs.add (MATCH_EXACT, names);
