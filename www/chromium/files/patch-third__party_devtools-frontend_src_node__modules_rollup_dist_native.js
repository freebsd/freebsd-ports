--- third_party/devtools-frontend/src/node_modules/rollup/dist/native.js.orig	2026-07-01 06:24:19 UTC
+++ third_party/devtools-frontend/src/node_modules/rollup/dist/native.js
@@ -57,9 +57,13 @@ const bindingsByPlatformAndArch = {
 		x64: { base: 'darwin-x64' }
 	},
 	freebsd: {
-		arm64: { base: 'freebsd-arm64' },
-		x64: { base: 'freebsd-x64' }
+		arm64: { base: 'freebsd' },
+		x64: { base: 'freebsd' }
 	},
+	openbsd: {
+		arm64: { base: 'openbsd' },
+		x64: { base: 'openbsd' }
+	},
 	linux: {
 		arm: { base: 'linux-arm-gnueabihf', musl: 'linux-arm-musleabihf' },
 		arm64: { base: 'linux-arm64-gnu', musl: 'linux-arm64-musl' },
@@ -68,9 +72,6 @@ const bindingsByPlatformAndArch = {
 		riscv64: { base: 'linux-riscv64-gnu', musl: 'linux-riscv64-musl' },
 		s390x: { base: 'linux-s390x-gnu', musl: null },
 		x64: { base: 'linux-x64-gnu', musl: 'linux-x64-musl' }
-	},
-	openbsd: {
-		x64: { base: 'openbsd-x64' }
 	},
 	openharmony: {
 		arm64: { base: 'openharmony-arm64' }
