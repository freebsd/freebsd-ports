--- src/brave/build/commands/lib/util.js.orig	2026-10-18 18:43:23 UTC
+++ src/brave/build/commands/lib/util.js
@@ -140,7 +140,7 @@ const getAdditionalGenLocation = () => {
       return 'android_clang_x86'
     }
   } else if (
-    (process.platform === 'darwin' || process.platform === 'linux')
+    ['darwin', 'freebsd', 'linux'].includes(process.platform)
     && config.targetArch === 'arm64'
   ) {
     return 'clang_x64_v8_arm64'
@@ -713,7 +713,10 @@ const util = {
         }, 10 * 1000)
       }
 
-      await util.runAsync('autoninja', ninjaOpts, autoninjaOptions)
+      // autoninja is a depot_tools wrapper that also pulls in siso/reclient.
+      // depot_tools is not used on FreeBSD, so run ninja from ports directly.
+      const ninjaCmd = process.platform === 'freebsd' ? 'ninja' : 'autoninja'
+      await util.runAsync(ninjaCmd, ninjaOpts, autoninjaOptions)
       clearBuildIdleWatchdog()
       buildGuard.markFinished()
     } catch (e) {
