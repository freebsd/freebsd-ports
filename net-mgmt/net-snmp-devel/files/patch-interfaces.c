--- agent/mibgroup/mibII/interfaces.c.orig	Sat Jun  8 00:18:03 2002
+++ agent/mibgroup/mibII/interfaces.c	Mon Jul 29 12:35:08 2002
@@ -555,11 +555,9 @@
                         ifp->ifm_type));
         }
     }
-    if (have_ifinfo && have_addr) {
+    if (have_ifinfo) {
         return 0;
-    } else if (have_ifinfo && !(if_msg->ifm_flags & IFF_UP))
-        return 0;
-    else {
+    } else {
         return -1;
     }
 }
