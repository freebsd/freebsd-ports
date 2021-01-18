--- src/zuuid.c.orig	2021-01-18 10:17:46 UTC
+++ src/zuuid.c
@@ -67,7 +67,7 @@ zuuid_new (void)
     uuid_t uuid;
     assert (sizeof (uuid) == ZUUID_LEN);
     uuid_generate (uuid);
-    zuuid_set (self, (byte *) uuid);
+    zuuid_set (self, (byte *) &uuid);
 #elif defined (__UTYPE_OPENBSD) || defined (__UTYPE_FREEBSD) || defined (__UTYPE_NETBSD)
     uuid_t uuid;
     uint32_t status = 0;
