--- comm/mail/modules/DNS.jsm.orig	2021-12-12 21:21:31.875731000 +0100
+++ comm/mail/modules/DNS.jsm	2021-12-12 22:31:04.895700000 +0100
@@ -38,11 +38,17 @@
   _open() {
     function findLibrary() {
       let lastException = null;
-      let candidates = [
-        { name: "resolv.9", suffix: "" },
-        { name: "resolv", suffix: ".2" },
-        { name: "resolv", suffix: "" },
-      ];
+      if(Services.appinfo.OS.toLowerCase() == "freebsd") {
+        let candidates = [
+          { name: "c", suffix: ".7" },
+        ]
+      } else {
+        let candidates = [
+          { name: "resolv.9", suffix: "" },
+          { name: "resolv", suffix: ".2" },
+          { name: "resolv", suffix: "" },
+        ];
+      }
       let tried = [];
       for (let candidate of candidates) {
         try {
