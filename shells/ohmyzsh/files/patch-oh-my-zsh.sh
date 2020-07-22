Disable auto update
Respect XDG cache directory if present.
--- oh-my-zsh.sh.orig	2020-07-18 17:06:08 UTC
+++ oh-my-zsh.sh
@@ -1,12 +1,8 @@
 # Set ZSH_CACHE_DIR to the path where cache files should be created
-# or else we will use the default cache/
+# or else we will use the default .cache/
 if [[ -z "$ZSH_CACHE_DIR" ]]; then
-  ZSH_CACHE_DIR="$ZSH/cache"
-fi
-
-# Check for updates on initial load...
-if [ "$DISABLE_AUTO_UPDATE" != "true" ]; then
-  source $ZSH/tools/check_for_upgrade.sh
+  ZSH_CACHE_DIR="${XDG_CACHE_HOME:-$HOME/.cache}/oh-my-zsh"
+  mkdir -p ${ZSH_CACHE_DIR}
 fi
 
 # Initializes Oh My Zsh
