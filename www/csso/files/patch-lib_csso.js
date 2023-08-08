--- lib/csso.js.orig	2013-10-15 12:47:12 UTC
+++ lib/csso.js
@@ -1,7 +1,8 @@
 var fs = require('fs'),
-    print = require('util').print,
     csso = require('./cssoapi.js'),
     src, x;
+
+var print = console.log;
 
 var args = process.argv.slice(2),
     opts = args.length ? getOpts(args, [
