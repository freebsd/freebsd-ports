--- kopete/protocols/icq_new/libicq/service.cpp.orig	Thu Nov 21 21:52:08 2002
+++ kopete/protocols/icq_new/libicq/service.cpp	Thu Nov 21 21:53:46 2002
@@ -301,14 +301,14 @@
     time(&now);
     Buffer b;
     b << (char)3;
-    b.pack(now);
+    b.pack((unsigned long)now);
     b.pack((unsigned short)0);
     b.pack((unsigned short)1);
     b.pack((unsigned short)1);
     b.pack((char*)SHARED_FILES_SIGN, 16);
     b << (char)4 << (unsigned short)1;
     b.pack((unsigned long)(bState ? 1 : 0));
-    b.pack(now);
+    b.pack((unsigned long)now);
     b.pack((unsigned long)0);
     b.pack((unsigned short)1);
     sendUpdate(b);
