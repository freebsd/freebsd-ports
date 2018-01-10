--- include/CharsetRegistry.h.orig	1998-10-07 05:15:50 UTC
+++ include/CharsetRegistry.h
@@ -45,6 +45,7 @@ class SP_API CharsetRegistry { (public)
     GB2312 = 58,
     ISO10646_UCS2 = 176,
     ISO10646_UCS4 = 177,
+    KOI8_R = 65534, // not registered
     BIG5 = 65535 // not registered
   };
   static ISORegistrationNumber getRegistrationNumber(const StringC &desig,
