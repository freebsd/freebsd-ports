--- src/daemon/driver/driverMain.ml.orig	Tue Nov 21 10:55:31 2006
+++ src/daemon/driver/driverMain.ml	Tue Nov 21 10:55:54 2006
@@ -342,7 +342,7 @@
     end;
 
   (
-    let hostname = "www.mldonkey.net" in
+    let hostname = "savannah.nongnu.org" in
     try
       ignore(Ip.from_name hostname);
       DriverInteractive.dns_works := true
