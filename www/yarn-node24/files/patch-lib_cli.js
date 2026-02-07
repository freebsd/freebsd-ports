--- lib/cli.js.orig	2020-03-09 15:51:47 UTC
+++ lib/cli.js
@@ -56939,10 +56939,10 @@ function getRcConfigForFolder(cwd) {
 }
 
 function loadRcFile(fileText, filePath) {
-  var _parse = (0, (_lockfile || _load_lockfile()).parse)(fileText, filePath),
+  var _parse = (0, (_lockfile || _load_lockfile()).parse)(fileText, 'yarnrc'),
       values = _parse.object;
 
-  if (filePath.match(/\.yml$/) && typeof values.yarnPath === 'string') {
+  if (filePath.match(/\.yml$/)) {
     values = { 'yarn-path': values.yarnPath };
   }
 
@@ -64532,27 +64532,16 @@ function parse(str, fileLoc) {
   var parser = new Parser(str, fileLoc);
   parser.next();
 
-  if (!fileLoc.endsWith(`.yml`)) {
+  try {
+    return parser.parse();
+  } catch (error1) {
     try {
-      return parser.parse();
-    } catch (error1) {
-      try {
-        return safeLoad(str, {
-          schema: FAILSAFE_SCHEMA
-        });
-      } catch (error2) {
-        throw error1;
-      }
+      return safeLoad(str, {
+        schema: FAILSAFE_SCHEMA
+      });
+    } catch (error2) {
+      throw error1;
     }
-  } else {
-    var result = safeLoad(str, {
-      schema: FAILSAFE_SCHEMA
-    });
-    if (typeof result === 'object') {
-      return result;
-    } else {
-      return {};
-    }
   }
 }
 
@@ -90319,7 +90308,7 @@ var _buildSubCommands = (0, (_buildSubCommands2 || _lo
         var rcPath = `${config.lockfileFolder}/.yarnrc.yml`;
         reporter.log(`Updating ${chalk.magenta(rcPath)}...`);
 
-        yield (_fs || _load_fs()).writeFilePreservingEol(rcPath, `yarnPath: ${(0, (_stringify || _load_stringify()).default)(targetPath)}\n`);
+        yield (_fs || _load_fs()).writeFilePreservingEol(rcPath, `yarnPath: ${(0, (_stringify || _load_stringify()).default)(yarnPath)}\n`);
       } else {
         var _rcPath = `${config.lockfileFolder}/.yarnrc`;
         reporter.log(`Updating ${chalk.magenta(_rcPath)}...`);
@@ -101330,11 +101319,7 @@ function parseRcPaths(paths, parser) {
     try {
       return parser((0, (_fs || _load_fs()).readFileSync)(path).toString(), path);
     } catch (error) {
-      if (error.code === 'ENOENT' || error.code === 'EISDIR') {
-        return {};
-      } else {
-        throw error;
-      }
+      return {};
     }
   })));
 }
@@ -153406,4 +153391,4 @@ module.exports = require("dns");
 module.exports = require("domain");
 
 /***/ })
-/******/ ]);
\ No newline at end of file
+/******/ ]);
