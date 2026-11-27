-- No FreeBSD build of the native compiler exists, so use the wasm one
-- that is now a dependency instead of fetching it mid-build.
--
-- Linting and type checking only inspect the sources, and the type
-- checker exhausts the memory limit of the package builders.

--- next.config.mjs.orig	2026-11-18 00:15:12 UTC
+++ next.config.mjs
@@ -3,6 +3,15 @@ const nextConfig = {
 const nextConfig = {
   reactStrictMode: false,
   output: 'standalone',
+  eslint: {
+    ignoreDuringBuilds: true,
+  },
+  typescript: {
+    ignoreBuildErrors: true,
+  },
+  experimental: {
+    useWasmBinary: true,
+  },
   images: {
     unoptimized: true,
   },
