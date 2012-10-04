--- dep/net.c.orig
+++ dep/net.c
@@ -322,10 +322,14 @@
 		return FALSE;
 	}
 	/* check that the interface TYPE is OK */
-	if (((struct sockaddr_dl *)ifh->ifa_addr)->sdl_type != IFT_ETHER) {
-		ERROR("\"%s\" is not an ethernet interface!\n", ifh->ifa_name);
-		return FALSE;
-	}
+        switch (((struct sockaddr_dl *)ifh->ifa_addr)->sdl_type) {
+            case IFT_ETHER:
+            case IFT_L2VLAN:
+                break;
+            default: 
+                ERROR("\"%s\" is not an ethernet interface!\n", ifh->ifa_name);
+                return FALSE;
+        }
 	DBG("==> %s %s %s\n", ifv4->ifa_name,
 	    inet_ntoa(((struct sockaddr_in *)ifv4->ifa_addr)->sin_addr),
 	    ether_ntoa((struct ether_addr *)
