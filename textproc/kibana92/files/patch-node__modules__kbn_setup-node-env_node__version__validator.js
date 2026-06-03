--- node_modules/@kbn/setup-node-env/node_version_validator.js.orig	2026-02-24 03:31:48 UTC
+++ node_modules/@kbn/setup-node-env/node_version_validator.js
@@ -21,11 +21,11 @@ if (!process.env.UNSAFE_DISABLE_NODE_VERSION_VALIDATIO
   var currentVersion = process && process.version || null;
   var rawRequiredVersion = pkg && pkg.engines && pkg.engines.node || null;
   var requiredVersion = rawRequiredVersion ? 'v' + rawRequiredVersion : rawRequiredVersion;
-  var isVersionValid = !!currentVersion && !!requiredVersion && currentVersion === requiredVersion;
+  var isVersionValid = !!currentVersion && !!requiredVersion && currentVersion >= requiredVersion;
 
   // Validates current the NodeJS version compatibility when Kibana starts.
   if (!isVersionValid) {
-    var errorMessage = 'Kibana does not support the current Node.js version ' + currentVersion + '. Please use Node.js ' + requiredVersion + '.';
+    var errorMessage = 'Kibana does not support the current Node.js version ' + currentVersion + '. Please use Node.js >= ' + requiredVersion + '.';
 
     // Actions to apply when validation fails: error report + exit.
     console.error(errorMessage);
