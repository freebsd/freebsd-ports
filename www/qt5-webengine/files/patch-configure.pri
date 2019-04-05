--- configure.pri.orig	2018-11-27 04:10:38 UTC
+++ configure.pri
@@ -85,9 +85,9 @@ defineTest(qtConfTest_detectFlex) {
 }
 
 defineTest(qtConfTest_detectGlibc) {
-    ldd = $$qtConfFindInPath("ldd")
+    ldd = $$qtConfFindInPath("ld.bfd")
     !isEmpty(ldd) {
-        qtLog("Found ldd from path: $$ldd")
+        qtLog("Found ld.bfd from path: $$ldd")
         qtRunLoggedCommand("$$ldd --version", version)|return(true)
         version ~= 's/^.*[^0-9]\([0-9]*\.[0-9]*\).*$/\1/'
         version = $$first(version)
