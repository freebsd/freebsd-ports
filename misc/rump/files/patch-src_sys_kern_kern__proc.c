--- src/sys/kern/kern_proc.c.orig	2020-08-29 04:55:58 UTC
+++ src/sys/kern/kern_proc.c
@@ -252,7 +252,7 @@ proc_listener_cb(kauth_cred_t cred, kauth_action_t act
 	case KAUTH_PROCESS_CANSEE: {
 		enum kauth_process_req req;
 
-		req = (enum kauth_process_req)arg1;
+		req = (enum kauth_process_req)(uintptr_t)arg1;
 
 		switch (req) {
 		case KAUTH_REQ_PROCESS_CANSEE_ARGS:
