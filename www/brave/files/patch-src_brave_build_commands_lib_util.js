--- src/brave/build/commands/lib/util.js.orig	2026-06-01 00:00:00 UTC
+++ src/brave/build/commands/lib/util.js
@@ -186,7 +186,7 @@
       return 'android_clang_x86'
     }
   } else if (
-    (process.platform === 'darwin' || process.platform === 'linux')
+    ['darwin', 'freebsd', 'linux'].includes(process.platform)
     && config.targetArch === 'arm64'
   ) {
     return 'clang_x64_v8_arm64'
@@ -809,7 +809,10 @@
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
