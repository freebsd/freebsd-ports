--- libdnf/dnf-repo.cpp.orig	2025-11-25 05:00:01 UTC
+++ libdnf/dnf-repo.cpp
@@ -968,7 +968,7 @@ dnf_repo_conf_load_overrides(DnfRepo *repo, const char
             const auto & section = cfg_parser_data_iter.first;
             g_autofree gchar * repo_id_pattern = dnf_repo_substitute(repo, section.c_str());
 
-            if (fnmatch(repo_id_pattern, repoId, FNM_EXTMATCH) != 0) {
+            if (fnmatch(repo_id_pattern, repoId, 0/*FNM_EXTMATCH*/) != 0) {
                 continue;
             }
 
