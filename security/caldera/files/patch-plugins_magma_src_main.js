--- plugins/magma/src/main.js.orig	2024-02-16 18:19:33.493026000 -0500
+++ plugins/magma/src/main.js	2024-02-16 18:19:57.472456000 -0500
@@ -53,10 +53,10 @@
   faCircle, faCircleQuestion, faCopy, farFlag
 );
 import { 
-  faApple, faLinux, faWindows 
+  faApple, faLinux, faWindows, faFreebsd 
 } from '@fortawesome/free-brands-svg-icons';
 library.add(
-  faApple, faLinux, faWindows
+  faApple, faLinux, faWindows, faFreebsd 
 );
 
 app.component('font-awesome-icon', FontAwesomeIcon);
