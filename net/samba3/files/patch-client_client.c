--- client/client.c.orig	Tue Jun  5 02:42:29 2007
+++ client/client.c	Tue Jun  5 02:54:19 2007
@@ -2443,7 +2443,7 @@
 				break;
 			case SMB_POSIX_ACL_GROUP:
 				uorg = IVAL(retbuf,SMB_POSIX_ACL_HEADER_SIZE+(i*SMB_POSIX_ACL_ENTRY_SIZE)+2);
-				d_printf("group:%u", uorg);
+				d_printf("group:%u:", uorg);
 				break;
 			case SMB_POSIX_ACL_MASK:
 				d_printf("mask::");
@@ -2480,7 +2480,7 @@
 				break;
 			case SMB_POSIX_ACL_GROUP:
 				uorg = IVAL(retbuf,SMB_POSIX_ACL_HEADER_SIZE+((i+num_file_acls)*SMB_POSIX_ACL_ENTRY_SIZE)+2);
-				d_printf("default:group:%u", uorg);
+				d_printf("default:group:%u:", uorg);
 				break;
 			case SMB_POSIX_ACL_MASK:
 				d_printf("default:mask::");
