--- ./grub-core/net/bootp.c.orig	2012-06-22 05:15:48.000000000 +0900
+++ ./grub-core/net/bootp.c	2012-12-25 16:38:12.000000000 +0900
@@ -122,7 +122,7 @@
 		ptr += 4;
 	      }
 	  }
-	  break;
+	  continue;
 	case GRUB_NET_BOOTP_HOSTNAME:
 	  set_env_limn_ro (name, "hostname", (char *) ptr, taglength);
 	  break;
