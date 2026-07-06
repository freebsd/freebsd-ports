--- server/uptime-kuma-server.js.orig
+++ server/uptime-kuma-server.js
@@ -342,12 +342,13 @@ class UptimeKumaServer {
      * @returns {void}
      */
     static errorLog(error, outputToConsole = true) {
-        const errorLogStream = fs.createWriteStream(path.join(Database.dataDir, "/error.log"), {
+        const errorLogPath = process.env.UPTIME_KUMA_ERROR_LOG || path.join(Database.dataDir, "error.log");
+        const errorLogStream = fs.createWriteStream(errorLogPath, {
             flags: "a",
         });
 
         errorLogStream.on("error", () => {
-            log.info("", "Cannot write to error.log");
+            log.info("", `Cannot write to error log: ${errorLogPath}`);
         });
 
         if (errorLogStream) {
