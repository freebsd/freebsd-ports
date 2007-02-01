--- ./doc/developer/gen-config.sh.orig	Thu Jan  4 16:22:49 2007
+++ ./doc/developer/gen-config.sh	Thu Jan  4 16:22:56 2007
@@ -91,7 +91,7 @@
     user="${userNum}@${host}"
 
     ################# Credential ################
-    token=`echo -n "${userNum}:${host}:1234" | md5sum | cut -d " " -f 1`
+    token=`echo -n "${userNum}:${host}:1234" | md5 -r | cut -d " " -f 1`
     cat <<EOF >> ${CfgDir}/credential.xml
   <item>
     <uri>sip:${user}</uri>
