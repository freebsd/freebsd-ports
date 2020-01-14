--- camcontrol.c.orig	2020-01-13 12:56:28 UTC
+++ camcontrol.c
@@ -279,10 +279,12 @@ get_device_type(struct cam_device *dev, camcontrol_dev
 		*devtype = CC_DT_NVME;
 		goto bailout;
 		break; /*NOTREACHED*/
+#if __FreeBSD_version >= 1200000
 	case PROTO_MMCSD:
 		*devtype = CC_DT_MMCSD;
 		goto bailout;
 		break; /*NOTREACHED*/
+#endif
 	default:
 		*devtype = CC_DT_UNKNOWN;
 		goto bailout;
