Reduce Brotli compression on i386 to have more memory available. Otherwise,
node.js stops with either SIGSEGV or SIGABRT after ~530 processed files.

--- src/3rdparty/chromium/third_party/devtools-frontend/src/scripts/build/compress_files.js.orig	2025-03-29 00:50:57 UTC
+++ src/3rdparty/chromium/third_party/devtools-frontend/src/scripts/build/compress_files.js
@@ -2,6 +2,7 @@
 // Use of this source code is governed by a BSD-style license that can be
 // found in the LICENSE file.
 
+const os = require('os');
 const fs = require('fs');
 const crypto = require('crypto');
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
 
