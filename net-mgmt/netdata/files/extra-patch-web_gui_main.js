--- web/gui/main.js.orig	2020-05-13 18:08:21 UTC
+++ web/gui/main.js
@@ -745,11 +745,7 @@ function renderMyNetdataMenu(machinesArray) {
     if (!isSignedIn()) {
         if (!NETDATA.registry.isRegistryEnabled()) {
             html += (
-                `<div class="info-item" style="white-space: nowrap">
-                    <span>Please <a href="#" onclick="signInDidClick(event); return false">sign in to netdata.cloud</a> to view your nodes!</span>
-                    <div></div>
-                </div>
-                <hr />`
+                ``
             );
         }
     }
