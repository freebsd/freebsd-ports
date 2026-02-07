--- src/sys/secmodel/suser/secmodel_suser.c.orig	2020-08-29 04:57:51 UTC
+++ src/sys/secmodel/suser/secmodel_suser.c
@@ -236,7 +236,7 @@ secmodel_suser_system_cb(kauth_cred_t cred, kauth_acti
 
 	isroot = suser_isroot(cred);
 	result = KAUTH_RESULT_DEFER;
-	req = (enum kauth_system_req)arg0;
+	req = (enum kauth_system_req)(uintptr_t)arg0;
 
 	switch (action) {
 	case KAUTH_SYSTEM_CPU:
@@ -575,7 +575,7 @@ secmodel_suser_network_cb(kauth_cred_t cred, kauth_act
 
 	isroot = suser_isroot(cred);
 	result = KAUTH_RESULT_DEFER;
-	req = (enum kauth_network_req)arg0;
+	req = (enum kauth_network_req)(uintptr_t)arg0;
 
 	switch (action) {
 	case KAUTH_NETWORK_ALTQ:
@@ -903,7 +903,7 @@ secmodel_suser_device_cb(kauth_cred_t cred, kauth_acti
 	case KAUTH_DEVICE_BLUETOOTH_BTUART: {
 		enum kauth_device_req req;
 
-		req = (enum kauth_device_req)arg0;
+		req = (enum kauth_device_req)(uintptr_t)arg0;
 		switch (req) {
 		case KAUTH_REQ_DEVICE_BLUETOOTH_BCSP_ADD:
 		case KAUTH_REQ_DEVICE_BLUETOOTH_BTUART_ADD:
