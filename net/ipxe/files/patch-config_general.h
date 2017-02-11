--- config/general.h.orig	2016-12-08 09:35:52 UTC
+++ config/general.h
@@ -35,7 +35,7 @@ FILE_LICENCE ( GPL2_OR_LATER_OR_UBDL );
  */
 
 #define	NET_PROTO_IPV4		/* IPv4 protocol */
-#undef	NET_PROTO_IPV6		/* IPv6 protocol */
+#define	NET_PROTO_IPV6		/* IPv6 protocol */
 #undef	NET_PROTO_FCOE		/* Fibre Channel over Ethernet protocol */
 #define	NET_PROTO_STP		/* Spanning Tree protocol */
 #define	NET_PROTO_LACP		/* Link Aggregation control protocol */
@@ -54,10 +54,10 @@ FILE_LICENCE ( GPL2_OR_LATER_OR_UBDL );
 
 #define	DOWNLOAD_PROTO_TFTP	/* Trivial File Transfer Protocol */
 #define	DOWNLOAD_PROTO_HTTP	/* Hypertext Transfer Protocol */
-#undef	DOWNLOAD_PROTO_HTTPS	/* Secure Hypertext Transfer Protocol */
+#define	DOWNLOAD_PROTO_HTTPS	/* Secure Hypertext Transfer Protocol */
 #undef	DOWNLOAD_PROTO_FTP	/* File Transfer Protocol */
 #undef	DOWNLOAD_PROTO_SLAM	/* Scalable Local Area Multicast */
-#undef	DOWNLOAD_PROTO_NFS	/* Network File System Protocol */
+#define	DOWNLOAD_PROTO_NFS	/* Network File System Protocol */
 //#undef DOWNLOAD_PROTO_FILE	/* Local filesystem access */
 
 /*
@@ -141,7 +141,7 @@ FILE_LICENCE ( GPL2_OR_LATER_OR_UBDL );
 //#define PXE_CMD		/* PXE commands */
 //#define REBOOT_CMD		/* Reboot command */
 //#define POWEROFF_CMD		/* Power off command */
-//#define IMAGE_TRUST_CMD	/* Image trust management commands */
+#define IMAGE_TRUST_CMD	/* Image trust management commands */
 //#define PCI_CMD		/* PCI commands */
 //#define PARAM_CMD		/* Form parameter commands */
 //#define NEIGHBOUR_CMD		/* Neighbour management commands */
