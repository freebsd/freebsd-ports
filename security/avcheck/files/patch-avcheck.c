--- avcheck.c.orig	Sun Jul 28 00:22:05 2002
+++ avcheck.c	Thu Mar 25 10:32:17 2004
@@ -530,23 +530,27 @@
 #define DRWEBD_SCAN_FLAGS (DRWEBD_RETURN_VIRUSES/*|DRWEBD_HEURISTIC_ON*/)
 
 /* DrWeb result codes */
-#define DERR_READ_ERR		0x00001
-#define DERR_WRITE_ERR		0x00002
-#define DERR_NOMEMORY		0x00004
-#define DERR_CRC_ERROR		0x00008
-#define DERR_READSOCKET		0x00010
-#define DERR_KNOWN_VIRUS	0x00020
-#define DERR_UNKNOWN_VIRUS	0x00040
-#define DERR_VIRUS_MODIFICATION	0x00080
-#define DERR_TIMEOUT		0x00200
-#define DERR_SYMLINK		0x00400
-#define DERR_NO_REGFILE		0x00800
-#define DERR_SKIPPED		0x01000
-#define DERR_TOO_BIG		0x02000
-#define DERR_TOO_COMPRESSED	0x04000
-#define DERR_BAD_CALL		0x08000
-#define DERR_EVAL_VERSION	0x10000
-#define DERR_SPAM_MESSAGE	0x20000
+#define DERR_READ_ERR		0x00000001
+#define DERR_WRITE_ERR		0x00000002
+#define DERR_NOMEMORY		0x00000004
+#define DERR_CRC_ERROR		0x00000008
+#define DERR_READSOCKET		0x00000010
+#define DERR_KNOWN_VIRUS	0x00000020
+#define DERR_UNKNOWN_VIRUS	0x00000040
+#define DERR_VIRUS_MODIFICATION	0x00000080
+#define DERR_HAVE_CURED		0x00000100
+#define DERR_TIMEOUT		0x00000200
+#define DERR_SYMLINK		0x00000400
+#define DERR_NO_REGFILE		0x00000800
+#define DERR_SKIPPED		0x00001000
+#define DERR_TOO_BIG		0x00002000
+#define DERR_TOO_COMPRESSED	0x00004000
+#define DERR_BAD_CALL		0x00008000
+#define DERR_EVAL_VERSION	0x00010000
+#define DERR_SPAM_MESSAGE	0x00020000
+#define DERR_ARCHIVE_LEVEL      0x00040000
+#define DERR_HAVE_DELETED	0x00080000
+#define DERR_IS_CLEAN		0x00100000
 
 #define DERR_VIRUS \
   (DERR_KNOWN_VIRUS|DERR_UNKNOWN_VIRUS|DERR_VIRUS_MODIFICATION)
@@ -570,7 +574,7 @@
   if (read(fd, &c, sizeof(c)) != sizeof(c) || /* code */
       read(fd, &n, sizeof(n)) != sizeof(n))   /* number of viruses */
     err(errno, "error reading %s daemon response", avname);
-  if ((c = ntohl(c)) == 0)
+  if (((c = ntohl(c)) == 0) || (c & DERR_IS_CLEAN))
     return 0; /* all ok, no viruses found (n should be 0) */
 
   if (!(c & DERR_VIRUS)) {
