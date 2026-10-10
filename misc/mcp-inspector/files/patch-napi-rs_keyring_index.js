--- node_modules/@modelcontextprotocol/inspector/node_modules/@napi-rs/keyring/index.js.orig	2026-10-09 14:24:07 UTC
+++ node_modules/@modelcontextprotocol/inspector/node_modules/@napi-rs/keyring/index.js
@@ -243,7 +243,11 @@ function requireNative() {
         loadErrors.push(e)
       }
     } else {
-      loadErrors.push(new Error(`Unsupported architecture on FreeBSD: ${process.arch}`))
+      try {
+        return require(`@napi-rs/keyring-freebsd-${process.arch}`)
+      } catch (e) {
+        loadErrors.push(e)
+      }
     }
   } else if (process.platform === 'linux') {
     if (process.arch === 'x64') {
