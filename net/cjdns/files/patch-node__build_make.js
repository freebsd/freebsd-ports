--- node_build/make.js.orig	2020-10-05 21:46:19 UTC
+++ node_build/make.js
@@ -27,7 +27,7 @@ const GetVersion = require('./GetVersion');
 
 var CFLAGS = process.env['CFLAGS'];
 var LDFLAGS = process.env['LDFLAGS'];
-var NO_MARCH_FLAG = ['arm', 'ppc', 'ppc64'];
+var NO_MARCH_FLAG = ['arm', 'arm64', 'ppc', 'ppc64'];
 
 Builder.configure({
     systemName:     process.env['SYSTEM'] || process.platform,
@@ -471,4 +471,4 @@ Builder.configure({
     console.log('\x1b[1;31mFailed to build cjdns.\x1b[0m');
     process.exit(1);
 
-});
\ No newline at end of file
+});
