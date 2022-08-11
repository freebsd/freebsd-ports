--- board/sunxi/board.c.orig	2022-05-03 09:13:36.019124000 +0200
+++ board/sunxi/board.c	2022-05-03 09:13:47.210925000 +0200
@@ -601,7 +601,7 @@
 	case BOOT_DEVICE_MMC2:
 		return 1;
 	default:
-		return CONFIG_SYS_MMC_ENV_DEV;
+		return 0;
 	}
 }
 #endif
