--- server/Common/sources/utils.js.orig 2026-10-08 12:21:41 UTC
+++ server/Common/sources/utils.js
@@ -46,6 +46,7 @@
 const path = require('path');
 const crypto = require('crypto');
 const url = require('url');
+const querystring = require('querystring');
 const axios = require('../node_modules/axios/dist/node/axios.cjs');
 const co = require('co');
 const URI = require('uri-js-replace');
@@ -399,7 +400,7 @@
       });
     }
     if (proxyUrl) {
-      const parsedProxyUrl = url.parse(proxyUrl);
+      const parsedProxyUrl = new url.URL(proxyUrl);

       // axios tunnels https targets with CONNECT and forward-proxies plain http itself
       options.proxy = {
@@ -1138,7 +1139,9 @@

   // Initialize Express-like properties
   rawReq.originalUrl = rawReq.originalUrl || rawReq.url || '/';
-  rawReq.query = rawReq.query || (rawReq.url ? url.parse(rawReq.url, true).query : {});
+  rawReq.query = rawReq.query || (rawReq.url
+    ? querystring.parse(new url.URL(rawReq.url, 'http://localhost').search.slice(1))
+    : {});
 };

 function stream2Buffer(stream) {
