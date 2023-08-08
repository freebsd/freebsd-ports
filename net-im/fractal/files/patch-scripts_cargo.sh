--- scripts/cargo.sh.orig	2020-08-07 12:02:09 UTC
+++ scripts/cargo.sh
@@ -1,15 +1,13 @@ export OUTPUT="$2"
 #!/bin/sh
 
 export OUTPUT="$2"
-export CARGO_TARGET_DIR="$3"/target
-export CARGO_HOME="$CARGO_TARGET_DIR"/cargo-home
 export FRACTAL_PROFILE="$4"
 
 if [ "$FRACTAL_PROFILE" = "Devel" ]
 then
     echo "DEBUG MODE"
-    cargo build --manifest-path $1/Cargo.toml -p fractal-gtk && cp "$CARGO_TARGET_DIR"/debug/fractal-gtk "$OUTPUT"
+    cargo build --manifest-path $1/Cargo.toml -p fractal-gtk && cp "$CARGO_TARGET_DIR"/"$CARGO_BUILD_TARGET"/debug/fractal-gtk "$OUTPUT"
 else
     echo "RELEASE MODE"
-    cargo build --manifest-path $1/Cargo.toml --release -p fractal-gtk && cp "$CARGO_TARGET_DIR"/release/fractal-gtk "$OUTPUT"
+    cargo build --manifest-path $1/Cargo.toml --release -p fractal-gtk && cp "$CARGO_TARGET_DIR"/"$CARGO_BUILD_TARGET"/release/fractal-gtk "$OUTPUT"
 fi
