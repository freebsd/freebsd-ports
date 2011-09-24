--- CONFIG/src/backend/archinfo_x86.c.orig	2011-05-14 13:33:24.000000000 -0400
+++ CONFIG/src/backend/archinfo_x86.c	2011-09-06 05:59:18.000000000 -0400
@@ -309,9 +309,10 @@
       case 0x1A:
       case 0x1E:
       case 0x1F:
+      case 0x25:
+      case 0x2C:
          iret = IntCorei1;
          break;
-      case 0x25:
       case 0x2A:
          iret = IntCorei2;
 	 break;
