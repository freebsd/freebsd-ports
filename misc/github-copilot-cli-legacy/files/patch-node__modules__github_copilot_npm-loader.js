--- node_modules/@github/copilot/npm-loader.js.orig	2026-03-01 19:16:08 UTC
+++ node_modules/@github/copilot/npm-loader.js
@@ -4,4 +4,7 @@
  *  Copyright (c) Microsoft Corporation. All rights reserved.
  *--------------------------------------------------------------------------------------------*/
 
+// Disable the built-in ripgrep (which is non-existent) to ensure that the CLI uses the externally installed ripgrep
+process.env.USE_BUILTIN_RIPGREP = 'false';
+
 import{spawnSync as e}from"node:child_process";import{fileURLToPath as s}from"node:url";async function t(){try{const o=s(import.meta.resolve(`@github/copilot-${process.platform}-${process.arch}`)),r=e(o,process.argv.slice(2),{stdio:"inherit"});process.exit(r.status??1)}catch{}parseInt(process.versions.node.split(".")[0],10)<22&&(console.error(`GitHub Copilot CLI requires Node.js v22 or higher. Currently using v${process.versions.node}.`),process.exit(1));try{await import("./index.js")}catch(o){console.error("Failed to load GitHub Copilot CLI:",o),process.exit(1)}}t();
