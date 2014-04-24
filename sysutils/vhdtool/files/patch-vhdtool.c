diff --git a/vhdtool.c b/vhdtool.c
index af4d0eb..04c54c1 100644
--- vhdtool.c
+++ vhdtool.c
@@ -23,7 +23,7 @@
 
 #include <errno.h>
 #include <stdio.h>
-#include <endian.h>
+#include <sys/endian.h>
 #include <inttypes.h>
 #include <string.h>
 #include <getopt.h>
@@ -34,6 +34,8 @@
 #include <sys/stat.h>
 #include <fcntl.h>
 
+#define off64_t __int64_t
+
 #define COOKIE(x)           (*(uint64_t *) x)
 #define COOKIE32(x)         (*(uint32_t *) x)
 #define FOOTER_FEAT_RSVD    (2)
@@ -152,7 +154,7 @@ int vhd_read(struct vhd *vhd,
 	     void *buf,
 	     size_t size)
 {
-	if (lseek64(vhd->fd, vhd->offset, SEEK_SET) != vhd->offset) {
+	if (lseek(vhd->fd, vhd->offset, SEEK_SET) != vhd->offset) {
 		fprintf(stderr, "Error: couldn't seek '%s': %s\n",
 			vhd->name, strerror(errno));
 		return -1;
@@ -172,7 +174,7 @@ int vhd_write(struct vhd *vhd,
 	      void *buf,
 	      size_t size)
 {
-	if (lseek64(vhd->fd, vhd->offset, SEEK_SET) != vhd->offset) {
+	if (lseek(vhd->fd, vhd->offset, SEEK_SET) != vhd->offset) {
 		fprintf(stderr, "Error: couldn't seek '%s': %s\n",
 			vhd->name, strerror(errno));
 		return -1;
