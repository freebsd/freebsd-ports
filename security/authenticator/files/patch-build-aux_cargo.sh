--- build-aux/cargo.sh.orig	2021-09-08 15:33:49 UTC
+++ build-aux/cargo.sh
@@ -12,10 +12,10 @@ if [ "$BUILDTYPE" = "release" ]; then
     echo "RELEASE MODE"
     cargo build --manifest-path \
         "$MESON_SOURCE_ROOT"/Cargo.toml --release &&
-        cp "$CARGO_TARGET_DIR"/release/"$APP_BIN" "$OUTPUT"
+        cp "$CARGO_TARGET_DIR"/$CARGO_BUILD_TARGET/release/"$APP_BIN" "$OUTPUT"
 else
     echo "DEBUG MODE"
     cargo build --manifest-path \
         "$MESON_SOURCE_ROOT"/Cargo.toml &&
-        cp "$CARGO_TARGET_DIR"/debug/"$APP_BIN" "$OUTPUT"
+        cp "$CARGO_TARGET_DIR"/$CARGO_BUILD_TARGET/debug/"$APP_BIN" "$OUTPUT"
 fi
