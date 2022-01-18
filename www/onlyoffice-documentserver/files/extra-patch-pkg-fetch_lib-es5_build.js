--- server/node_modules/pkg-fetch/lib-es5/build.js.orig	2021-12-31 17:50:57.174508000 +0100
+++ server/node_modules/pkg-fetch/lib-es5/build.js	2021-12-31 17:50:42.893063000 +0100
@@ -98,18 +98,14 @@ function getConfigureArgs(major, targetPlatform) {
     if (targetPlatform === 'linuxstatic') {
         args.push('--fully-static');
     }
-    // Link Time Optimization
-    if (major >= 12) {
-        if (system_1.hostPlatform !== 'win') {
-            args.push('--enable-lto');
-        }
-    }
     // DTrace
     args.push('--without-dtrace');
     // bundled npm package manager
     args.push('--without-npm');
     // Small ICU
-    args.push('--with-intl=small-icu');
+    args.push('--with-intl=system-icu');
+    args.push('--shared-openssl');
+    args.push('--openssl-use-def-ca-store');
     // Workaround for nodejs/node#39313
     // All supported macOS versions have zlib as a system library
     if (targetPlatform === 'macos') {
