Reduce Brotli compression on i386 to have more memory available. Otherwise,
node.js stops with either SIGSEGV or SIGABRT after ~530 processed files.

--- src/3rdparty/chromium/third_party/devtools-frontend/src/scripts/build/compress_files.js.orig	2025-10-02 00:36:39 UTC
+++ src/3rdparty/chromium/third_party/devtools-frontend/src/scripts/build/compress_files.js
@@ -4,6 +4,7 @@ const fs = require('fs');
 
 const crypto = require('crypto');
 const fs = require('fs');
+const os = require('os')
 const {pipeline, Readable} = require('stream');
 const zlib = require('zlib');
 
@@ -52,9 +53,16 @@ async function brotli(sourceData, compressedFilename) 
   output.write(Buffer.from(brotliConst));
   output.write(Buffer.from(sizeHeader));
   return new Promise((resolve, reject) => {
-    pipeline(Readable.from(sourceData), zlib.createBrotliCompress(), output, err => {
-      return err ? reject(err) : resolve();
-    });
+    if (os.arch() === 'arm' || os.arch() === 'ia32') {
+       pipeline(Readable.from(sourceData), zlib.createBrotliCompress({ params: { [zlib.constants.BROTLI_PARAM_QUALITY]: 4 } }), output, err => {
+         return err ? reject(err) : resolve();
+       });
+    }
+    else {
+       pipeline(Readable.from(sourceData), zlib.createBrotliCompress(), output, err => {
+         return err ? reject(err) : resolve();
+       });
+    }
   });
 }
 
