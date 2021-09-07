--- plugins/reportsDashboards/server/routes/utils/constants.js.orig	2021-09-16 00:07:34 UTC
+++ plugins/reportsDashboards/server/routes/utils/constants.js
@@ -130,7 +130,7 @@ const SECURITY_CONSTANTS = {
   PROXY_AUTH_IP_HEADER: 'x-forwarded-for'
 };
 exports.SECURITY_CONSTANTS = SECURITY_CONSTANTS;
-const CHROMIUM_PATH = `${__dirname}/../../../.chromium/headless_shell`;
+const CHROMIUM_PATH = '%%LOCALBASE%%/bin/chrome';
 /**
  * Metric constants
  */
