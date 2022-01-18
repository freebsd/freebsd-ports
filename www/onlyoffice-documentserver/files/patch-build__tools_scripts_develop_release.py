--- build_tools/scripts/develop/release.py.orig	2021-12-08 10:18:20 UTC
+++ build_tools/scripts/develop/release.py
@@ -44,7 +44,7 @@ repositories.update(base.get_plugins('autocomplete, ea
 # Add other repositories
 repositories['core-ext'] = [True, False]
 
-base.update_repositories(repositories)
+#base.update_repositories(repositories)
 
 repositories['onlyoffice'] = [True, False]
 
