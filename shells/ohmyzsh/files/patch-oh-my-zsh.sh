--- oh-my-zsh.sh.orig	2023-09-16 14:01:58 UTC
+++ oh-my-zsh.sh
@@ -65,9 +65,6 @@ mkdir -p "$ZSH_CACHE_DIR/completions"
 mkdir -p "$ZSH_CACHE_DIR/completions"
 (( ${fpath[(Ie)"$ZSH_CACHE_DIR/completions"]} )) || fpath=("$ZSH_CACHE_DIR/completions" $fpath)
 
-# Check for updates on initial load...
-source "$ZSH/tools/check_for_upgrade.sh"
-
 # Initializes Oh My Zsh
 
 # add a function path
