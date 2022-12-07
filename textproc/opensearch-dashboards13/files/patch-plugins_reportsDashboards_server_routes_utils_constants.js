--- plugins/reportsDashboards/server/routes/utils/constants.js.orig	2022-06-30 21:47:37 UTC
+++ plugins/reportsDashboards/server/routes/utils/constants.js
@@ -138,7 +138,7 @@ const replaceBlockedKeywords = htmlString => {
 };
 
 exports.replaceBlockedKeywords = replaceBlockedKeywords;
-const CHROMIUM_PATH = `${__dirname}/../../../.chromium/headless_shell`;
+const CHROMIUM_PATH = `%%LOCALBASE%%/bin/chrome`;
 /**
  * Metric constants
  */
