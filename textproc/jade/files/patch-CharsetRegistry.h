--- include/CharsetRegistry.h.orig	Sat Jul 31 17:02:57 2004
+++ include/CharsetRegistry.h	Sat Jul 31 17:05:32 2004
@@ -45,6 +45,7 @@
     GB2312 = 58,
     ISO10646_UCS2 = 176,
     ISO10646_UCS4 = 177,
+    KOI8_R = 65534, // not registered
     BIG5 = 65535 // not registered
   };
   static ISORegistrationNumber getRegistrationNumber(const StringC &desig,
