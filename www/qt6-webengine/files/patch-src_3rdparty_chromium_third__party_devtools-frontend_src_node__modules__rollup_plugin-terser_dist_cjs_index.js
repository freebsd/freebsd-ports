--- src/3rdparty/chromium/third_party/devtools-frontend/src/node_modules/@rollup/plugin-terser/dist/cjs/index.js.orig	2026-05-08 07:54:08 UTC
+++ src/3rdparty/chromium/third_party/devtools-frontend/src/node_modules/@rollup/plugin-terser/dist/cjs/index.js
@@ -70,7 +70,7 @@ class WorkerPool extends events.EventEmitter {
         this.tasks = [];
         this.workers = [];
         this.freeWorkers = [];
-        this.maxInstances = options.maxWorkers || os.cpus().length;
+        this.maxInstances = options.maxWorkers || os.cpus().length || 4;
         this.filePath = options.filePath;
         this.on(freeWorker, () => {
             if (this.tasks.length > 0) {
