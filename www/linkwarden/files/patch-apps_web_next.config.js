--- apps/web/next.config.js.orig	2026-09-22 11:09:01 UTC
+++ apps/web/next.config.js
@@ -4,6 +4,7 @@ const nextConfig = {
 
 const nextConfig = {
   i18n,
+  generateBuildId: () => "linkwarden-" + version,
   reactStrictMode: true,
   devIndicators: false,
   staticPageGenerationTimeout: 1000,
