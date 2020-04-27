--- web/gui/main.js.orig	2020-04-06 01:28:55 UTC
+++ web/gui/main.js
@@ -4923,9 +4923,7 @@ function renderAccountUI() {
         container.setAttribute("data-original-title", "sign in");
         container.setAttribute("data-placement", "bottom");
         container.innerHTML = (
-            `<a href="#" class="btn sign-in-btn theme-${netdataTheme}" onclick="signInDidClick(event); return false">
-                <i class="fas fa-sign-in-alt"></i>&nbsp;<span class="hidden-sm hidden-md">Sign In</span>
-            </a>`
+            ``
         )
     }
 }
