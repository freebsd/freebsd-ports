--- usr/lib/common/shared_memory.c.orig	2022-04-25 11:04:51 UTC
+++ usr/lib/common/shared_memory.c
@@ -172,10 +172,10 @@ int sm_open(const char *sm_name, int mode, void **p_ad
         goto done;
     }
 
-    grp = getgrnam("pkcs11");
+    grp = getgrnam(PKCS11GROUP);
     if (!grp) {
         rc = -errno;
-        SYS_ERROR(errno, "getgrname(\"pkcs11\"): %s\n",
+        SYS_ERROR(errno, "getgrname(\"" PKCS11GROUP "\"): %s\n",
                 strerror(errno));
         goto done;
     }
