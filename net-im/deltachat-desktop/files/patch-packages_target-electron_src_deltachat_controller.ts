--- packages/target-electron/src/deltachat/controller.ts.orig	2026-09-29 18:06:34 UTC
+++ packages/target-electron/src/deltachat/controller.ts
@@ -6,7 +6,6 @@ import {
   // eslint-disable-next-line @typescript-eslint/no-unused-vars
   type RawClient,
 } from '@deltachat/jsonrpc-client'
-import { getRPCServerPath } from '@deltachat/stdio-rpc-server'
 
 import { getLogger } from '@deltachat-desktop/shared/logger.js'
 import * as mainWindow from '../windows/main.js'
@@ -71,11 +70,7 @@ export default class DeltaChatController {
   async init() {
     log.debug('Initiating DeltaChatNode')
     const allowCustomServerPath = rc_config['allow-custom-rpc-server-path']
-    let serverPath = await getRPCServerPath({
-      // desktop should only use prebuilds normally
-      disableEnvPath: !allowCustomServerPath,
-      takeVersionFromPATH: allowCustomServerPath,
-    })
+    let serverPath = "%%PREFIX%%/bin/deltachat-rpc-server"
     if (serverPath.includes('app.asar')) {
       // probably inside of electron build
       serverPath = serverPath.replace('app.asar', 'app.asar.unpacked')
