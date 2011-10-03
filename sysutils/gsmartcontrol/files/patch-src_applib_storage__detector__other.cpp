
$FreeBSD$

--- src/applib/storage_detector_other.cpp.orig
+++ src/applib/storage_detector_other.cpp
@@ -75,6 +75,7 @@
 
 	whitelist.push_back("/^ad[0-9]+$/");  // adN without suffix - fbsd ide
 	whitelist.push_back("/^da[0-9]+$/");  // daN without suffix - fbsd scsi, usb
+	whitelist.push_back("/^ada[0-9]+$/");  // adaN without suffix - fbsd ata cam
 // 	whitelist.push_back("/	^sa[0-9]+$/");  // saN without suffix - fbsd scsi tape
 // 	whitelist.push_back("/^ast[0-9]+$/");  // astN without suffix - fbsd ide tape
 	whitelist.push_back("/^aacd[0-9]+$/");  // fbsd adaptec raid
