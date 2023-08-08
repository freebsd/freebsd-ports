--- src/setup_node_env/node_version_validator.js.orig	2023-01-04 12:19:12 UTC
+++ src/setup_node_env/node_version_validator.js
@@ -15,13 +15,13 @@ var pkg = require('../../package.json');
 var currentVersion = process && process.version || null;
 var rawRequiredVersion = pkg && pkg.engines && pkg.engines.node || null;
 var requiredVersion = rawRequiredVersion ? 'v' + rawRequiredVersion : rawRequiredVersion;
-var isVersionValid = !!currentVersion && !!requiredVersion && currentVersion === requiredVersion;
+var isVersionValid = !!currentVersion && !!requiredVersion && currentVersion >= requiredVersion;
 
 // Validates current the NodeJS version compatibility when Kibana starts.
 if (!isVersionValid) {
-  var errorMessage = 'Kibana does not support the current Node.js version ' + currentVersion + '. Please use Node.js ' + requiredVersion + '.';
+  var errorMessage = 'Kibana does not support the current Node.js version ' + currentVersion + '. Please use Node.js >= ' + requiredVersion + '.';
 
   // Actions to apply when validation fails: error report + exit.
   console.error(errorMessage);
   process.exit(1);
-}
\ No newline at end of file
+}
