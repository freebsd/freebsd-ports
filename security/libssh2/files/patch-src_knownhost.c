--- src/knownhost.c.orig	2015-03-19 13:01:33 UTC
+++ src/knownhost.c
@@ -777,6 +777,12 @@ static int hostline(LIBSSH2_KNOWNHOSTS *
             key_type = LIBSSH2_KNOWNHOST_KEY_SSHDSS;
         else if (!strncmp(key_type_name, "ssh-rsa", key_type_len))
             key_type = LIBSSH2_KNOWNHOST_KEY_SSHRSA;
+        else if (!strncmp(key_type_name, "ecdsa-sha2-nistp256", key_type_len))
+            key_type = LIBSSH2_KNOWNHOST_KEY_ECDSA_256;
+        else if (!strncmp(key_type_name, "ecdsa-sha2-nistp384", key_type_len))
+            key_type = LIBSSH2_KNOWNHOST_KEY_ECDSA_384;
+        else if (!strncmp(key_type_name, "ecdsa-sha2-nistp521", key_type_len))
+            key_type = LIBSSH2_KNOWNHOST_KEY_ECDSA_521;
         else
             key_type = LIBSSH2_KNOWNHOST_KEY_UNKNOWN;
 
@@ -1016,6 +1022,18 @@ knownhost_writeline(LIBSSH2_KNOWNHOSTS *
         key_type_name = "ssh-dss";
         key_type_len = 7;
         break;
+    case LIBSSH2_KNOWNHOST_KEY_ECDSA_256:
+        key_type_name = "ecdsa-sha2-nistp256";
+        key_type_len = 19;
+        break;
+    case LIBSSH2_KNOWNHOST_KEY_ECDSA_384:
+        key_type_name = "ecdsa-sha2-nistp384";
+        key_type_len = 19;
+        break;
+    case LIBSSH2_KNOWNHOST_KEY_ECDSA_521:
+        key_type_name = "ecdsa-sha2-nistp521";
+        key_type_len = 19;
+        break;
     case LIBSSH2_KNOWNHOST_KEY_UNKNOWN:
         key_type_name = node->key_type_name;
         if (key_type_name) {
