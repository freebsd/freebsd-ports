--- bin/vendor/deno-land/x/puppeteer@9-0-2/src/deno/BrowserFetcher.ts.orig	2024-09-07 16:50:53 UTC
+++ bin/vendor/deno-land/x/puppeteer@9-0-2/src/deno/BrowserFetcher.ts
@@ -197,6 +197,7 @@ export class BrowserFetcher {
     const platform = Deno.build.os;
     if (platform === "darwin") this._platform = "mac";
     else if (platform === "linux") this._platform = "linux";
+    else if (platform === "freebsd") this._platform = "linux"; // use _platform=linux for now
     else if (platform === "windows") {
       this._platform = Deno.build.arch === "x86_64" ? "win64" : "win32";
     } else assert(this._platform, "Unsupported platform: " + Deno.build.os);
@@ -370,6 +371,8 @@ export class BrowserFetcher {
           "firefox"
         );
       } else if (this._platform === "linux") {
+        executablePath = pathJoin(folderPath, "firefox", "firefox");
+      } else if (this._platform === "freebsd") {
         executablePath = pathJoin(folderPath, "firefox", "firefox");
       } else if (this._platform === "win32" || this._platform === "win64") {
         executablePath = pathJoin(folderPath, "firefox", "firefox.exe");
