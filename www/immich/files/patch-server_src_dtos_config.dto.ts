--- server/src/dtos/config.dto.ts.orig	2026-09-19 10:49:13 UTC
+++ server/src/dtos/config.dto.ts
@@ -570,7 +570,7 @@ export const defaults = Object.freeze<SystemConfig>({
     twoPass: false,
     preferredHwDevice: 'auto',
     transcode: TranscodePolicy.Required,
-    tonemap: ToneMapping.Hable,
+    tonemap: ToneMapping.Disabled,
     accel: TranscodeHardwareAcceleration.Disabled,
     accelDecode: true,
     realtime: {
