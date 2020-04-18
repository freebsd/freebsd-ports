--- share/functions/fish_vcs_prompt.fish.orig	2020-04-18 20:32:19 UTC
+++ share/functions/fish_vcs_prompt.fish
@@ -3,5 +3,8 @@ function fish_vcs_prompt --description "Print the prom
     # This is so we don't try svn if git already worked.
     fish_git_prompt
     or fish_hg_prompt
-    or fish_svn_prompt
+    # The svn prompt is disabled by default because it's quite slow on common svn repositories.
+    # To enable it uncomment it.
+    # You can also only use it in specific directories by checking $PWD.
+    # or fish_svn_prompt
 end
