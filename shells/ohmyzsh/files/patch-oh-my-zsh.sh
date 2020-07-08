--- oh-my-zsh.sh.orig	2020-07-06 15:31:40 UTC
+++ oh-my-zsh.sh
@@ -1,12 +1,7 @@
 # Set ZSH_CACHE_DIR to the path where cache files should be created
 # or else we will use the default cache/
 if [[ -z "$ZSH_CACHE_DIR" ]]; then
-  ZSH_CACHE_DIR="$ZSH/cache"
-fi
-
-# Check for updates on initial load...
-if [ "$DISABLE_AUTO_UPDATE" != "true" ]; then
-  source $ZSH/tools/check_for_upgrade.sh
+  ZSH_CACHE_DIR="$HOME/.oh-my-zsh/cache"
 fi
 
 # Initializes Oh My Zsh
