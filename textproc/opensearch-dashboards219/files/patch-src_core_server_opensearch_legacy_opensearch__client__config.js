--- src/core/server/opensearch/legacy/opensearch_client_config.js.orig	2026-06-04 21:37:54 UTC
+++ src/core/server/opensearch/legacy/opensearch_client_config.js
@@ -5,7 +5,6 @@ var _lodash = require("lodash");
 });
 exports.parseOpenSearchClientConfig = parseOpenSearchClientConfig;
 var _lodash = require("lodash");
-var _url = _interopRequireDefault(require("url"));
 var _std = require("@osd/std");
 var _default_headers = require("../default_headers");
 function _interopRequireDefault(e) { return e && e.__esModule ? e : { default: e }; }
@@ -77,7 +76,7 @@ function parseOpenSearchClientConfig(config, log, {
   if (Array.isArray(config.hosts)) {
     const needsAuth = auth !== false && config.username && config.password;
     opensearchClientConfig.hosts = config.hosts.map(nodeUrl => {
-      const uri = _url.default.parse(nodeUrl);
+      const uri = new URL('', nodeUrl);
       const httpsURI = uri.protocol === 'https:';
       const httpURI = uri.protocol === 'http:';
       const host = {
@@ -164,4 +163,4 @@ function getLoggerClass(log, logQueries = false) {
       // noop
     }
   };
-}
\ No newline at end of file
+}
