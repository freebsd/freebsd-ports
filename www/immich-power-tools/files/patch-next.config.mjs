-- No FreeBSD build of the native compiler exists, so use the wasm one
-- that is now a dependency instead of fetching it mid-build.

--- next.config.mjs.orig	2026-11-06 21:20:43 UTC
+++ next.config.mjs
@@ -3,6 +3,9 @@ const nextConfig = {
 const nextConfig = {
   reactStrictMode: false,
   output: 'standalone',
+  experimental: {
+    useWasmBinary: true,
+  },
   images: {
     unoptimized: true,
   },
