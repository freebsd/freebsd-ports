--- repo/tests/run-tests.sh.orig	2024-09-27 21:54:30 UTC
+++ repo/tests/run-tests.sh
@@ -1,26 +1,20 @@
 #!/usr/bin/env bash
 
-# Determine the path to this script (we'll use this to figure out relative positions of other files)
-SOURCE="${BASH_SOURCE[0]}"
-while [ -h "$SOURCE" ]; do # resolve $SOURCE until the file is no longer a symlink
-  SCRIPT_PATH="$( cd -P "$( dirname "$SOURCE" )" >/dev/null 2>&1 && pwd )"
-  SOURCE="$(readlink "$SOURCE")"
-  [[ $SOURCE != /* ]] && SOURCE="$DIR/$SOURCE" # if $SOURCE was a relative symlink, we need to resolve it relative to the path where the symlink file was located
-done
-export SCRIPT_PATH="$( cd -P "$( dirname "$SOURCE" )" >/dev/null 2>&1 && pwd )"
+SCRIPT_PATH="/usr/ports/textproc/quarto/work/stage/usr/local/share/quarto/bin"
+ARCH_DIR=amd64
 
-source $SCRIPT_PATH/../package/scripts/common/utils.sh
+#source  /usr/ports/textproc/quarto/work/quarto-1.6.15/repo/package/scripts/common/utils.sh
 
-export QUARTO_ROOT="`cd "$SCRIPT_PATH/.." > /dev/null 2>&1 && pwd`"
-QUARTO_SRC_DIR="$QUARTO_ROOT/src"
-DENO_ARCH_DIR=$DENO_DIR
-DENO_DIR="$QUARTO_ROOT/package/dist/bin/"
+export QUARTO_ROOT=$SCRIPT_PATH/..
+QUARTO_SRC_DIR="/usr/ports/textproc/quarto/work/quarto-1.6.15/repo/src"
+DENO_ARCH_DIR=/usr/local/bin
+DENO_DIR="$QUARTO_ROOT/bin/tools/$ARCH_DIR/bin/"
 
 # Local import map
 QUARTO_IMPORT_MAP_ARG=--importmap=$QUARTO_SRC_DIR/dev_import_map.json
 
-export QUARTO_BIN_PATH=$DENO_DIR
-export QUARTO_SHARE_PATH="`cd "$QUARTO_ROOT/src/resources/";pwd`"
+export QUARTO_BIN_PATH=/usr/local/bin
+export QUARTO_SHARE_PATH=/usr/ports/textproc/quarto/work/quarto-cli-1.6.15/src/resources
 export QUARTO_DEBUG=true
 
 QUARTO_DENO_OPTIONS="--config test-conf.json --v8-flags=--enable-experimental-regexp-engine,--max-old-space-size=8192,--max-heap-size=8192 --unstable-kv --unstable-ffi --allow-read --allow-write --allow-run --allow-env --allow-net"
