--- oh-my-zsh.sh.orig	2024-12-04 21:57:15 UTC
+++ oh-my-zsh.sh
@@ -67,9 +67,6 @@ mkdir -p "$ZSH_CACHE_DIR/completions"
 mkdir -p "$ZSH_CACHE_DIR/completions"
 (( ${fpath[(Ie)$ZSH_CACHE_DIR/completions]} )) || fpath=("$ZSH_CACHE_DIR/completions" $fpath)
 
-# Check for updates on initial load...
-source "$ZSH/tools/check_for_upgrade.sh"
-
 # Initializes Oh My Zsh
 
 # add a function path
