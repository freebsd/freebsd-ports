--- yao-pkg/node_modules/@yao-pkg/pkg-fetch/lib-es5/build.js.orig	2024-01-25 21:40:25.773587000 +0100
+++ yao-pkg/node_modules/@yao-pkg/pkg-fetch/lib-es5/build.js	2024-01-25 21:41:12.907517000 +0100
@@ -99,12 +99,6 @@ function getConfigureArgs(major, targetPlatform) {
     if (targetPlatform === 'linuxstatic') {
         args.push('--fully-static');
     }
-    // Link Time Optimization
-    if (major >= 12) {
-        if (system_1.hostPlatform !== 'win') {
-            args.push('--enable-lto');
-        }
-    }
     // production binaries do NOT take NODE_OPTIONS from end-users
     args.push('--without-node-options');
     // The dtrace and etw support was removed in https://github.com/nodejs/node/commit/aa3a572e6bee116cde69508dc29478b40f40551a
@@ -115,7 +109,14 @@ function getConfigureArgs(major, targetPlatform) {
     // bundled npm package manager
     args.push('--without-npm');
     // Small ICU
-    args.push('--with-intl=small-icu');
+    args.push('--with-intl=system-icu');
+    args.push('--shared-openssl');
+    args.push('--openssl-use-def-ca-store');
+    args.push('--shared-brotli');
+    args.push('--shared-cares');
+    args.push('--shared-libuv');
+    args.push('--shared-nghttp2');
+    args.push('--shared-zlib');
     // Workaround for nodejs/node#39313
     // All supported macOS versions have zlib as a system library
     if (targetPlatform === 'macos') {
@@ -433,4 +434,4 @@ exports.default = build;
     });
 }
 exports.default = build;
-//# sourceMappingURL=build.js.map
\ No newline at end of file
+//# sourceMappingURL=build.js.map
