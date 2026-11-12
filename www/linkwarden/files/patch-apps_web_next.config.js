--- apps/web/next.config.js.orig	2026-11-10 18:23:37 UTC
+++ apps/web/next.config.js
@@ -5,6 +5,7 @@ const nextConfig = {
 
 const nextConfig = {
   i18n,
+  generateBuildId: () => "linkwarden-" + version,
   reactStrictMode: true,
   devIndicators: false,
   staticPageGenerationTimeout: 1000,
