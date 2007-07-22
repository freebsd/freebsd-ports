--- src/fwbuilder/IPAddress.h~	2006-08-18 05:59:32.000000000 +0200
+++ src/fwbuilder/IPAddress.h	2007-07-14 17:09:06.406044356 +0200
@@ -47,6 +47,7 @@
 {
 
     class Netmask;
+    Netmask operator~(const Netmask &nm);
 
 class IPAddress
 {
