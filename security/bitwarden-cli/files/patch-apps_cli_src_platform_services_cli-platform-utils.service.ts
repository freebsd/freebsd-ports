--- apps/cli/src/platform/services/cli-platform-utils.service.ts.orig	2025-07-01 17:12:33 UTC
+++ apps/cli/src/platform/services/cli-platform-utils.service.ts
@@ -28,7 +28,7 @@ export class CliPlatformUtilsService implements Platfo
         case "darwin":
           this.deviceCache = DeviceType.MacOsCLI;
           break;
-        case "linux":
+        case "linux": case "freebsd":
         default:
           this.deviceCache = DeviceType.LinuxCLI;
           break;
@@ -80,7 +80,7 @@ export class CliPlatformUtilsService implements Platfo
   }
 
   launchUri(uri: string, options?: any): void {
-    if (process.platform === "linux") {
+    if (process.platform === "linux" || process.platform === "freebsd") {
       child_process.spawnSync("xdg-open", [uri]);
     } else {
       // eslint-disable-next-line no-console
