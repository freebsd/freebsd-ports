--- next.config.mjs.orig
+++ next.config.mjs
@@ -6,6 +6,10 @@

 /** @type {import('next').NextConfig} */
 const nextConfig = {
+  // Pin the build ID to the package version so that repeated `next build`
+  // invocations of the same release produce identical chunk filenames.
+  // npm_package_version is injected by yarn/npm when running package scripts.
+  generateBuildId: async () => process.env.npm_package_version ?? "stable",
   output: "standalone",
   serverExternalPackages: ["ws", "libsodium-wrappers-sumo"],
   serverActions: {
