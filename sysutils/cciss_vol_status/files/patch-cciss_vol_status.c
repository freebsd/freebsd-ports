--- cciss_vol_status.c.orig	2017-10-18 07:49:43.578445000 +0200
+++ cciss_vol_status.c	2017-10-18 07:51:20.372056000 +0200
@@ -1098,7 +1098,7 @@
 			break;
 		case 1: sprintf(raid_level, "RAID 4");
 			break;
-		case 2: sprintf(raid_level, "RAID 1");
+		case 2: sprintf(raid_level, "RAID 1(1+0)");
 			break;
 		case 3: sprintf(raid_level, "RAID 5");
 			break;
