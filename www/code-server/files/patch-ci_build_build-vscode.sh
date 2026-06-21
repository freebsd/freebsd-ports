--- ci/build/build-vscode.sh.orig
+++ ci/build/build-vscode.sh
@@ -7,7 +7,7 @@
 MINIFY=${MINIFY-true}
 
 fix-bin-script() {
-  local script="lib/vscode-reh-web-$VSCODE_TARGET/bin/$1"
+  local script="lib/vscode-reh-web-$GULP_VSCODE_TARGET/bin/$1"
   sed -i.bak "s/@@VERSION@@/$(vscode_version)/g" "$script"
   sed -i.bak "s/@@COMMIT@@/$BUILD_SOURCEVERSION/g" "$script"
   sed -i.bak "s/@@APPNAME@@/code-server/g" "$script"
@@ -30,7 +30,7 @@
 }
 
 copy-bin-script() {
-  cp "lib/vscode/resources/server/bin/$1" "lib/vscode-reh-web-$VSCODE_TARGET/bin/$1"
+  cp "lib/vscode/resources/server/bin/$1" "lib/vscode-reh-web-$GULP_VSCODE_TARGET/bin/$1"
   fix-bin-script "$1"
 }
 
@@ -47,7 +47,7 @@
   # not update when only our patch files change, and that will cause caching
   # issues where the browser keeps using outdated code.
   export BUILD_SOURCEVERSION
-  BUILD_SOURCEVERSION=$(git rev-parse HEAD)
+  BUILD_SOURCEVERSION="${BUILD_SOURCEVERSION:-4.123.0}"
 
   pushd lib/vscode
 
@@ -64,13 +64,13 @@
   #
   # This needs to be done before building as Code will read this file and embed
   # it into the client-side code.
-  git checkout product.json             # Reset in case the script exited early.
   cp product.json product.original.json # Since jq has no inline edit.
   jq --slurp '.[0] * .[1]' product.original.json <(
     cat << EOF
   {
     "enableTelemetry": true,
     "quality": "stable",
+    "commit": "$BUILD_SOURCEVERSION",
     "codeServerVersion": "$VERSION",
     "nameShort": "code-server",
     "nameLong": "code-server",
@@ -111,16 +111,24 @@
   VSCODE_QUALITY=stable npm run gulp compile-copilot-extension-full-build
 
   npm run gulp core-ci
-  npm run gulp "vscode-reh-web-$VSCODE_TARGET${MINIFY:+-min}-ci"
+  GULP_VSCODE_TARGET="$VSCODE_TARGET"
+  if [[ "$GULP_VSCODE_TARGET" == freebsd-* ]]; then
+    GULP_VSCODE_TARGET="linux-${GULP_VSCODE_TARGET#freebsd-}"
+  fi
+  npm run gulp "vscode-reh-web-$GULP_VSCODE_TARGET${MINIFY:+-min}-ci"
 
+  pushd "../vscode-reh-web-$GULP_VSCODE_TARGET"
+  cp product.json product.original.json
+  jq --arg commit "$BUILD_SOURCEVERSION" '.commit = $commit' product.original.json > product.json
+  popd
+
   # Reset so if you develop after building you will not be stuck with the wrong
   # commit (the dev client will use `oss-dev` but the dev server will still use
   # product.json which will have `stable-$commit`).
-  git checkout product.json
 
   popd
 
-  pushd "lib/vscode-reh-web-$VSCODE_TARGET"
+  pushd "lib/vscode-reh-web-$GULP_VSCODE_TARGET"
   # Make sure Code took the version we set in the environment variable.  Not
   # having a version will break display languages.
   if ! jq -e .commit product.json; then
