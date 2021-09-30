--- build-aux/cargo.sh.orig	2021-09-30 06:45:11 UTC
+++ build-aux/cargo.sh
@@ -10,11 +10,11 @@ then
     echo "DEBUG MODE"
     cargo build --manifest-path \
         "$MESON_SOURCE_ROOT"/Cargo.toml && \
-        cp "$CARGO_TARGET_DIR"/debug/$5 $3
+        cp "$CARGO_TARGET_DIR"/$CARGO_BUILD_TARGET/debug/$5 $3
 else
     echo "RELEASE MODE"
     cargo build --manifest-path \
         "$MESON_SOURCE_ROOT"/Cargo.toml --release && \
-        cp "$CARGO_TARGET_DIR"/release/$5 $3
+        cp "$CARGO_TARGET_DIR"/$CARGO_BUILD_TARGET/release/$5 $3
 fi
 
