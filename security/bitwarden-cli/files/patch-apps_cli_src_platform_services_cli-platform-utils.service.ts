--- apps/cli/src/platform/services/cli-platform-utils.service.ts.orig	2026-03-27 19:20:46 UTC
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
@@ -88,7 +88,7 @@ export class CliPlatformUtilsService implements Platfo
   }
 
   launchUri(uri: string, options?: any): void {
-    if (process.platform === "linux") {
+    if (process.platform === "linux" || process.platform === "freebsd") {
       child_process.spawnSync("xdg-open", [uri]);
     } else {
       // eslint-disable-next-line no-console
