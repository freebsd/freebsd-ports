Disable auto update
--- oh-my-zsh.sh.orig	2021-10-01 23:40:04 UTC
+++ oh-my-zsh.sh
@@ -24,11 +24,6 @@ fi
 mkdir -p "$ZSH_CACHE_DIR/completions"
 (( ${fpath[(Ie)"$ZSH_CACHE_DIR/completions"]} )) || fpath=("$ZSH_CACHE_DIR/completions" $fpath)
 
-# Check for updates on initial load...
-if [ "$DISABLE_AUTO_UPDATE" != "true" ]; then
-  source $ZSH/tools/check_for_upgrade.sh
-fi
-
 # Initializes Oh My Zsh
 
 # add a function path
