--- lib/node_modules/npm/node_modules/node-gyp/lib/configure.js.orig	2019-05-29 07:53:16 UTC
+++ lib/node_modules/npm/node_modules/node-gyp/lib/configure.js
@@ -29,7 +29,7 @@ exports.usage = 'Generates ' + (win ? 'MSVC project fi
 
 function configure (gyp, argv, callback) {
 
-  var python = gyp.opts.python || process.env.PYTHON || 'python2'
+  var python = gyp.opts.python || process.env.PYTHON || 'python2.7'
     , buildDir = path.resolve('build')
     , configNames = [ 'config.gypi', 'common.gypi' ]
     , configs = []
