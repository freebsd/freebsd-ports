--- repo/tests/run-tests.sh.orig	2024-08-29 14:14:01 UTC
+++ repo/tests/run-tests.sh
@@ -1,20 +1,14 @@
 #!/usr/bin/env bash
 
-# Determine the path to this script (we'll use this to figure out relative positions of other files)
-SOURCE="${BASH_SOURCE[0]}"
-while [ -h "$SOURCE" ]; do # resolve $SOURCE until the file is no longer a symlink
-  SCRIPT_PATH="$( cd -P "$( dirname "$SOURCE" )" >/dev/null 2>&1 && pwd )"
-  SOURCE="$(readlink "$SOURCE")"
-  [[ $SOURCE != /* ]] && SOURCE="$DIR/$SOURCE" # if $SOURCE was a relative symlink, we need to resolve it relative to the path where the symlink file was located
-done
-export SCRIPT_PATH="$( cd -P "$( dirname "$SOURCE" )" >/dev/null 2>&1 && pwd )"
+SCRIPT_PATH="%%SCRIPT_PATH%%"
+ARCH_DIR=%%ARCH_DIR%%
 
-source $SCRIPT_PATH/../package/scripts/common/utils.sh
+#source  %%REPO%%/package/scripts/common/utils.sh
 
-export QUARTO_ROOT="`cd "$SCRIPT_PATH/.." > /dev/null 2>&1 && pwd`"
-QUARTO_SRC_DIR="$QUARTO_ROOT/src"
+export QUARTO_ROOT=$SCRIPT_PATH/..
+QUARTO_SRC_DIR="%%REPO%%/src"
 DENO_ARCH_DIR=$DENO_DIR
-DENO_DIR="$QUARTO_ROOT/package/dist/bin/"
+DENO_DIR="$QUARTO_ROOT/bin/tools/$ARCH_DIR/bin/"
 
 # Local import map
 QUARTO_IMPORT_MAP_ARG=--importmap=$QUARTO_SRC_DIR/dev_import_map.json
