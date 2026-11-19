--- packages/target-electron/src/deltachat/controller.ts.orig	2026-11-16 05:54:59 UTC
+++ packages/target-electron/src/deltachat/controller.ts
@@ -6,7 +6,6 @@ import {
   // eslint-disable-next-line @typescript-eslint/no-unused-vars
   type RawClient,
 } from '@deltachat/jsonrpc-client'
-import { getRPCServerPath } from '@deltachat/stdio-rpc-server'
 
 import { getLogger } from '@deltachat-desktop/shared/logger.js'
 import * as mainWindow from '../windows/main.js'
@@ -128,16 +127,7 @@ export function getRPCServerPath2(): string {
 }
 
 export function getRPCServerPath2(): string {
-  const allowCustomServerPath = rc_config['allow-custom-rpc-server-path']
-  let serverPath = getRPCServerPath({
-    // desktop should only use prebuilds normally
-    disableEnvPath: !allowCustomServerPath,
-    takeVersionFromPATH: allowCustomServerPath,
-  })
-  if (serverPath.includes('app.asar')) {
-    // probably inside of electron build
-    serverPath = serverPath.replace('app.asar', 'app.asar.unpacked')
-  }
+  let serverPath = "%%PREFIX%%/bin/deltachat-rpc-server"
 
   return serverPath
 }
