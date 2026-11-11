--- server/DocService/sources/DocsCoServer.js.orig      2026-10-08 12:21:41 UTC
+++ server/DocService/sources/DocsCoServer.js
@@ -934,7 +934,7 @@
     //no need to do decodeURIComponent http://expressjs.com/en/4x/api.html#app.settings.table
     //by default express uses 'query parser' = 'extended', but even in 'simple' version decode is done
     //percent-encoded characters within the query string will be assumed to use UTF-8 encoding
-    const parseObject = url.parse(callbackUrl);
+    const parseObject = new url.URL(callbackUrl);
     const isHttps = 'https:' === parseObject.protocol;
     let port = parseObject.port;
     if (!port) {
@@ -944,7 +944,7 @@
       https: isHttps,
       host: parseObject.hostname,
       port,
-      path: parseObject.path,
+      path: parseObject.pathname + parseObject.search,
       href: parseObject.href
     };
   } catch (e) {
@@ -3053,7 +3053,7 @@
         curIndexUser = user.indexUser;
       } else {
         if (data.documentCallbackUrl && !wopiParams) {
-          documentCallback = url.parse(data.documentCallbackUrl);
+          documentCallback = new url.URL(data.documentCallbackUrl);
           const filterStatus = yield* utils.checkHostFilter(ctx, documentCallback.hostname);
           if (0 !== filterStatus) {
             ctx.logger.warn('checkIpFilter error: url = %s', data.documentCallbackUrl);
