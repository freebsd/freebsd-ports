- workaround for https://github.com/quarto-dev/quarto-cli/issues/10916

--- bin/quarto.js.orig	2024-08-29 14:15:21 UTC
+++ bin/quarto.js
@@ -82618,7 +82618,7 @@ async function initYamlIntelligenceResourcesFromFilesy
 }
 async function initYamlIntelligenceResourcesFromFilesystem() {
     const resourceModule = (await import(toFileUrl2(resourcePath("editor/tools/yaml/yaml-intelligence-resources.json")).href, {
-        assert: {
+        with: {
             type: "json"
         }
     })).default;
