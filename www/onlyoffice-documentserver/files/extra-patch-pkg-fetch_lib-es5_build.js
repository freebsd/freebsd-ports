--- yao-pkg/node_modules/@yao-pkg/pkg-fetch/lib-es5/build.js.orig	2025-10-18 21:16:20 UTC
+++ yao-pkg/node_modules/@yao-pkg/pkg-fetch/lib-es5/build.js
@@ -100,12 +100,6 @@ function getConfigureArgs(major, targetPlatform, targetArch) {
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
@@ -117,7 +111,14 @@ function getConfigureArgs(major, targetPlatform, targetArch) {
     args.push('--without-npm');
     // Small ICU
     if (system_1.hostPlatform !== 'win' || major < 24) {
-        args.push('--with-intl=small-icu');
+        args.push('--with-intl=system-icu');
+        args.push('--shared-openssl');
+        args.push('--openssl-use-def-ca-store');
+        args.push('--shared-brotli');
+        args.push('--shared-cares');
+        args.push('--shared-libuv');
+        args.push('--shared-nghttp2');
+        args.push('--shared-zlib');
     }
     // Workaround for nodejs/node#39313
     // All supported macOS versions have zlib as a system library
