--- src/zuuid.c.orig	2017-12-31 14:43:10 UTC
+++ src/zuuid.c
@@ -47,7 +47,7 @@ zuuid_new (void)
     assert (sizeof (uuid) == ZUUID_LEN);
     UuidCreate (&uuid);
     zuuid_set (self, (byte *) &uuid);
-#elif defined (HAVE_UUID)
+#elif defined (HAVE_UUID) && !defined (__UTYPE_FREEBSD)
     uuid_t uuid;
     assert (sizeof (uuid) == ZUUID_LEN);
     uuid_generate (uuid);
