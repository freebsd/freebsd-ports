--- src/logerr.h.orig	2025-06-01 18:40:28 UTC
+++ src/logerr.h
@@ -76,7 +76,7 @@ __printflike(2, 3) void logerrmessage(int pri, const c
 #define logerr(...)	log_err(__VA_ARGS__)
 #define logerrx(...)	log_errx(__VA_ARGS__)
 
-/* For logging in a chroot */
+/* For logging in a chroot using SOCK_SEQPACKET */
 int loggetfd(void);
 void logsetfd(int);
 int logreadfd(int);
