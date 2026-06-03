--- packages/target-electron/src/deltachat/controller.ts.orig	2025-10-09 18:18:51 UTC
+++ packages/target-electron/src/deltachat/controller.ts
@@ -75,10 +75,7 @@ export default class DeltaChatController {
     }
 
     log.debug('Initiating DeltaChatNode')
-    let serverPath = await getRPCServerPath({
-      // desktop should only use prebuilds normally
-      disableEnvPath: !rc_config['allow-unsafe-core-replacement'],
-    })
+    let serverPath = "%%PREFIX%%/bin/deltachat-rpc-server"
     if (serverPath.includes('app.asar')) {
       // probably inside of electron build
       serverPath = serverPath.replace('app.asar', 'app.asar.unpacked')
