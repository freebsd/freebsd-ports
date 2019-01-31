--- tests/test_hostkey.c.orig	2016-08-20 15:37:25 UTC
+++ tests/test_hostkey.c
@@ -4,7 +4,7 @@
 
 #include <stdio.h>
 
-const char *EXPECTED_HOSTKEY =
+const char *EXPECTED_RSA_HOSTKEY =
     "AAAAB3NzaC1yc2EAAAABIwAAAQEArrr/JuJmaZligyfS8vcNur+mWR2ddDQtVdhHzdKU"
     "UoR6/Om6cvxpe61H1YZO1xCpLUBXmkki4HoNtYOpPB2W4V+8U4BDeVBD5crypEOE1+7B"
     "Am99fnEDxYIOZq2/jTP0yQmzCpWYS3COyFmkOL7sfX1wQMeW5zQT2WKcxC6FSWbhDqrB"
@@ -12,6 +12,10 @@ const char *EXPECTED_HOSTKEY =
     "i6ELfP3r+q6wdu0P4jWaoo3De1aYxnToV/ldXykpipON4NPamsb6Ph2qlJQKypq7J4iQ"
     "gkIIbCU1A31+4ExvcIVoxLQw/aTSbw==";
 
+const char *EXPECTED_ECDSA_HOSTKEY =
+    "AAAAE2VjZHNhLXNoYTItbmlzdHAyNTYAAAAIbmlzdHAyNTYAAABBBC+/syyeKJD9dC2ZH"
+    "9Q7iJGReR4YM3rUCMsSynkyXojdfSClGCMY7JvWlt30ESjYvxoTfSRGx6WvaqYK/vPoYQ4=";
+
 int test(LIBSSH2_SESSION *session)
 {
     int rc;
@@ -26,14 +30,19 @@ int test(LIBSSH2_SESSION *session)
         return 1;
     }
 
-    if (type != LIBSSH2_HOSTKEY_TYPE_RSA) {
-        /* Hostkey configured in docker container is RSA */
-        fprintf(stderr, "Wrong type of hostkey\n");
+    if(type == LIBSSH2_HOSTKEY_TYPE_ECDSA_256) {
+        rc = libssh2_base64_decode(session, &expected_hostkey, &expected_len,
+                                   EXPECTED_ECDSA_HOSTKEY, strlen(EXPECTED_ECDSA_HOSTKEY));
+    }
+    else if (type == LIBSSH2_HOSTKEY_TYPE_RSA) {
+        rc = libssh2_base64_decode(session, &expected_hostkey, &expected_len,
+                                   EXPECTED_RSA_HOSTKEY, strlen(EXPECTED_RSA_HOSTKEY));
+    }
+    else {
+        fprintf(stderr, "Unexpected type of hostkey: %i\n", type);
         return 1;
     }
 
-    rc = libssh2_base64_decode(session, &expected_hostkey, &expected_len,
-                               EXPECTED_HOSTKEY, strlen(EXPECTED_HOSTKEY));
     if (rc != 0) {
         print_last_session_error("libssh2_base64_decode");
         return 1;
