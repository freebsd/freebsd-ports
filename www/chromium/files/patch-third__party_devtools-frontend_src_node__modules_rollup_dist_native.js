--- third_party/devtools-frontend/src/node_modules/rollup/dist/native.js.orig	2026-02-12 08:43:57 UTC
+++ third_party/devtools-frontend/src/node_modules/rollup/dist/native.js
@@ -13,6 +13,14 @@ const bindingsByPlatformAndArch = {
 		arm64: { base: 'darwin-arm64' },
 		x64: { base: 'darwin-x64' }
 	},
+	freebsd: {
+		arm64: { base: 'freebsd' },
+		x64: { base: 'freebsd' }
+	},
+	openbsd: {
+		arm64: { base: 'openbsd' },
+		x64: { base: 'openbsd' }
+	},
 	linux: {
 		arm: { base: 'linux-arm-gnueabihf', musl: 'linux-arm-musleabihf' },
 		arm64: { base: 'linux-arm64-gnu', musl: 'linux-arm64-musl' },
