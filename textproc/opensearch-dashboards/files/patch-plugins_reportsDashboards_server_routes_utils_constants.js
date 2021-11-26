--- plugins/reportsDashboards/server/routes/utils/constants.js.orig	2021-11-22 18:22:17 UTC
+++ plugins/reportsDashboards/server/routes/utils/constants.js
@@ -107,7 +107,7 @@ const SECURITY_CONSTANTS = {
 exports.SECURITY_CONSTANTS = SECURITY_CONSTANTS;
 const EXTRA_HEADERS = ['cookie', 'x-proxy-user', 'x-proxy-roles', 'x-forwarded-for'];
 exports.EXTRA_HEADERS = EXTRA_HEADERS;
-const CHROMIUM_PATH = `${__dirname}/../../../.chromium/headless_shell`;
+const CHROMIUM_PATH = `%%LOCALBASE%%/bin/chrome`;
 /**
  * Metric constants
  */
