--- src-netbsd/sys/lib/libunwind/AddressSpace.hpp.orig	2018-01-14 23:12:55 UTC
+++ src-netbsd/sys/lib/libunwind/AddressSpace.hpp
@@ -140,7 +140,7 @@ public:
     } while (byte >= 0x80);
     // sign extend negative numbers
     if ((byte & 0x40) != 0)
-      result |= (-1LL) << bit;
+      result |= (~0ULL) << bit;
     return result;
   }
 
