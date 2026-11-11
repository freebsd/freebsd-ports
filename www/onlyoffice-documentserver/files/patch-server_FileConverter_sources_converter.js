--- server/FileConverter/sources/converter.js.orig      2026-10-08 12:21:41 UTC
+++ server/FileConverter/sources/converter.js
@@ -532,7 +532,14 @@
   const tenDownloadAttemptDelay = ctx.getCfg('FileConverter.converter.downloadAttemptDelay', cfgDownloadAttemptDelay);
   let res = constants.CONVERT_DOWNLOAD;
   let downloadAttemptCount = 0;
-  const urlParsed = url.parse(uri);
+  let urlParsed;
+  try {
+    urlParsed = new url.URL(uri);
+  } catch (err) {
+    ctx.logger.error('error downloadFile: invalid URL %s: %s', uri, err.message);
+    return constants.CONVERT_DOWNLOAD;
+  }
+
   // a wopi destination is judged by the wopi egress boundary, everything else keeps the plain host filter
   const filterStatus = opt_wopi ? 0 : yield* utils.checkHostFilter(ctx, urlParsed.hostname);
   if (0 == filterStatus) {
