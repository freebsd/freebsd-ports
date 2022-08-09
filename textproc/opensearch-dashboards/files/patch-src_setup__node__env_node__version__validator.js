--- src/setup_node_env/node_version_validator.js.orig	2022-06-30 21:38:00 UTC
+++ src/setup_node_env/node_version_validator.js
@@ -36,13 +36,13 @@ var pkg = require('../../package.json'); // Note: This
 var currentVersion = process && process.version || null;
 var rawRequiredVersion = pkg && pkg.engines && pkg.engines.node || null;
 var requiredVersion = rawRequiredVersion ? 'v' + rawRequiredVersion : rawRequiredVersion;
-var currentVersionMajorMinorPatch = currentVersion.match(/^v(\d+)\.(\d+)\.(\d+)/);
-var requiredVersionMajorMinorPatch = requiredVersion.match(/^v(\d+)\.(\d+)\.(\d+)/);
-var isVersionValid = currentVersionMajorMinorPatch[1] === requiredVersionMajorMinorPatch[1] && currentVersionMajorMinorPatch[2] === requiredVersionMajorMinorPatch[2] && parseInt(currentVersionMajorMinorPatch[3], 10) >= parseInt(requiredVersionMajorMinorPatch[3], 10); // Validates current the NodeJS version compatibility when OpenSearch Dashboards starts.
+var currentVersionMajorMinorPatch = currentVersion.match(/^v(\d+)\.(\d+)\.(\d+)/).map(x => parseInt(x, 10));
+var requiredVersionMajorMinorPatch = requiredVersion.match(/^v(\d+)\.(\d+)\.(\d+)/).map(x => parseInt(x, 10));
+var isVersionValid = currentVersionMajorMinorPatch[1] === requiredVersionMajorMinorPatch[1] && currentVersionMajorMinorPatch[2] > requiredVersionMajorMinorPatch[2] || currentVersionMajorMinorPatch[1] === requiredVersionMajorMinorPatch[1] && currentVersionMajorMinorPatch[2] === requiredVersionMajorMinorPatch[2] && currentVersionMajorMinorPatch[3] >= requiredVersionMajorMinorPatch[3]; // Validates current the NodeJS version compatibility when OpenSearch Dashboards starts.
 
 if (!isVersionValid) {
   var errorMessage = `OpenSearch Dashboards was built with ${requiredVersion} and does not support the current Node.js version ${currentVersion}. ` + `Please use Node.js ${requiredVersion} or a higher patch version.`; // Actions to apply when validation fails: error report + exit.
 
   console.error(errorMessage);
   process.exit(1);
-}
\ No newline at end of file
+}
