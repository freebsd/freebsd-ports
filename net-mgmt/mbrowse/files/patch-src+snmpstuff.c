--- src/snmpstuff.c.orig	Fri Oct  8 14:07:16 2004
+++ src/snmpstuff.c	Fri Oct  8 14:08:08 2004
@@ -359,7 +359,7 @@
       case TYPE_NSAPADDRESS:
       case TYPE_NETADDR:
       case TYPE_OTHER:
-      default:
+      default: ;
     }
   }
   if (type == 0) {
