--- node_build/builder.js.orig	2021-10-26 18:19:15 UTC
+++ node_build/builder.js
@@ -779,7 +779,7 @@ module.exports.configure = function (
     // if it returns undefined let's just assume 1
     // workaround, nodejs seems to be broken on openbsd (undefined result after second call)
     const cpus = Os.cpus();
-    const jobs = Math.floor((typeof cpus === 'undefined' ? 1 : cpus.length) * 1.25);
+    const jobs = Math.floor((cpus == 0 ? 1 : cpus.length) * 1.25);
 
     const pctx /*:Builder_PreCtx_t*/ = {
         buildStage: (_x,_y)=>{},
