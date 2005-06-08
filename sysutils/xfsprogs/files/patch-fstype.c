--- libdisk/fstype.c.orig	Tue Aug 19 15:29:58 2003
+++ libdisk/fstype.c	Tue Aug 19 15:31:13 2003
@@ -63,6 +63,28 @@
      return (a>>8) | (a<<8);
 }
 
+#define blksize	512
+static int
+read_dev(int fd, void *buf, size_t len)
+{
+	char 	block[blksize];
+	size_t  ret;
+	size_t readlen = len - len % blksize;
+	
+	ret = read(fd, buf, readlen);
+	if (ret != readlen)
+		return ret;
+
+	if (readlen == len)
+		return ret;
+
+	ret = read(fd, block, blksize);
+	if (ret != blksize)
+		return ret;
+
+	memcpy((char*)buf + readlen, block, len - readlen);
+	return len;
+}
 /*
     Probes the device and attempts to determine the type of filesystem
     contained within.
@@ -120,7 +142,7 @@
 	   (block sizes larger than 2K will be null padded) */
 	for (bs = 1; bs < 16; bs++) {
 		lseek(fd, bs*2048+32768, SEEK_SET);
-		if (read(fd, (char *)&isosb, sizeof(isosb)) != sizeof(isosb))
+		if (read_dev(fd, (char *)&isosb, sizeof(isosb)) != sizeof(isosb))
 			return 0;
 		if (isosb.id[0])
 			break;
@@ -130,7 +152,7 @@
 	for (j = 1; j < 64; j++) {
 		if (j > 1) {
 			lseek(fd, j*bs*2048+32768, SEEK_SET);
-			if (read(fd, (char *)&isosb, sizeof(isosb))
+			if (read_dev(fd, (char *)&isosb, sizeof(isosb))
 			    != sizeof(isosb))
 				return 0;
 		}
@@ -212,7 +234,9 @@
        undesired side effects - first check that `device' refers
        to a block device or ordinary file */
     if (stat (device, &statbuf) ||
-	!(S_ISBLK(statbuf.st_mode) || S_ISREG(statbuf.st_mode)))
+	!(S_ISBLK(statbuf.st_mode) ||
+	  S_ISREG(statbuf.st_mode) ||
+	  S_ISCHR(statbuf.st_mode)))
       return 0;
 
     fd = open(device, O_RDONLY);
@@ -225,7 +249,7 @@
     if (!type) {
 	 /* block 0 */
 	 if (lseek(fd, 0, SEEK_SET) != 0
-	     || read(fd, (char *) &xsb, sizeof(xsb)) != sizeof(xsb))
+	     || read_dev(fd, (char *) &xsb, sizeof(xsb)) != sizeof(xsb))
 	      goto try_iso9660;
 	 /* Gyorgy Kovesdi: none of my photocds has a readable block 0 */
 
@@ -262,7 +286,7 @@
     if (!type) {
 	    /* sector 1 */
 	    if (lseek(fd, 512 , SEEK_SET) != 512
-		|| read(fd, (char *) &svsb, sizeof(svsb)) != sizeof(svsb))
+		|| read_dev(fd, (char *) &svsb, sizeof(svsb)) != sizeof(svsb))
 		    goto io_error;
 	    if (sysvmagic(svsb) == SYSV_SUPER_MAGIC )
 		    type = "sysv";
@@ -271,7 +295,7 @@
     if (!type) {
 	/* block 1 */
 	if (lseek(fd, 1024, SEEK_SET) != 1024 ||
-	    read(fd, (char *) &sb, sizeof(sb)) != sizeof(sb))
+	    read_dev(fd, (char *) &sb, sizeof(sb)) != sizeof(sb))
 		goto io_error;
 
 	/* ext2 has magic in little-endian on disk, so "swapped" is
@@ -311,7 +335,7 @@
     if (!type) {
 	/* block 3 */
         if (lseek(fd, 0xc00, SEEK_SET) != 0xc00
-            || read(fd, (char *) &adfssb, sizeof(adfssb)) != sizeof(adfssb))
+            || read_dev(fd, (char *) &adfssb, sizeof(adfssb)) != sizeof(adfssb))
              goto io_error;
 
 	/* only a weak test */
@@ -326,7 +350,7 @@
 
 	 /* block 8 */
 	 if (lseek(fd, 8192, SEEK_SET) != 8192
-	     || read(fd, (char *) &ufssb, sizeof(ufssb)) != sizeof(ufssb))
+	     || read_dev(fd, (char *) &ufssb, sizeof(ufssb)) != sizeof(ufssb))
 	      goto io_error;
 
 	 mag = ufsmagic(ufssb);
@@ -338,7 +362,7 @@
 	/* block 8 */
 	if (lseek(fd, REISERFS_OLD_DISK_OFFSET_IN_BYTES, SEEK_SET) !=
 				REISERFS_OLD_DISK_OFFSET_IN_BYTES
-	    || read(fd, (char *) &reiserfssb, sizeof(reiserfssb)) !=
+	    || read_dev(fd, (char *) &reiserfssb, sizeof(reiserfssb)) !=
 		sizeof(reiserfssb))
 	    goto io_error;
 	if (is_reiserfs_magic_string(&reiserfssb))
@@ -348,7 +372,7 @@
     if (!type) {
 	/* block 8 */
         if (lseek(fd, 0x2000, SEEK_SET) != 0x2000
-            || read(fd, (char *) &hpfssb, sizeof(hpfssb)) != sizeof(hpfssb))
+            || read_dev(fd, (char *) &hpfssb, sizeof(hpfssb)) != sizeof(hpfssb))
              goto io_error;
 
         if (hpfsmagic(hpfssb) == HPFS_SUPER_MAGIC)
@@ -358,7 +382,7 @@
     if (!type) {
 	 /* block 32 */
 	 if (lseek(fd, JFS_SUPER1_OFF, SEEK_SET) != JFS_SUPER1_OFF
-	     || read(fd, (char *) &jfssb, sizeof(jfssb)) != sizeof(jfssb))
+	     || read_dev(fd, (char *) &jfssb, sizeof(jfssb)) != sizeof(jfssb))
 	      goto io_error;
 	 if (!strncmp(jfssb.s_magic, JFS_MAGIC, 4))
 	      type = "jfs";
@@ -368,7 +392,7 @@
 	 /* block 32 */
     try_iso9660:
 	 if (lseek(fd, 0x8000, SEEK_SET) != 0x8000
-	     || read(fd, (char *) &isosb, sizeof(isosb)) != sizeof(isosb))
+	     || read_dev(fd, (char *) &isosb, sizeof(isosb)) != sizeof(isosb))
 	      goto io_error;
 
 	 if (strncmp(isosb.hs.id, HS_STANDARD_ID, sizeof(isosb.hs.id)) == 0) {
@@ -388,7 +412,7 @@
 	/* block 64 */
 	if (lseek(fd, REISERFS_DISK_OFFSET_IN_BYTES, SEEK_SET) !=
 		REISERFS_DISK_OFFSET_IN_BYTES
-	    || read(fd, (char *) &reiserfssb, sizeof(reiserfssb)) !=
+	    || read_dev(fd, (char *) &reiserfssb, sizeof(reiserfssb)) !=
 		sizeof(reiserfssb))
 	    goto io_error;
 	if (is_reiserfs_magic_string(&reiserfssb))
@@ -396,6 +420,19 @@
     }
 
     if (!type) {
+	 int mag;
+
+	 /* block 64 */
+	 if (lseek(fd, 65536, SEEK_SET) != 65536
+	     || read_dev(fd, (char *) &ufssb, sizeof(ufssb)) != sizeof(ufssb))
+	      goto io_error;
+
+	 mag = ufsmagic(ufssb);
+	 if (mag == UFS2_SUPER_MAGIC_LE || mag == UFS2_SUPER_MAGIC_BE)
+	     type = "ufs2";
+    }
+
+    if (!type) {
 	    /* perhaps the user tries to mount the swap space
 	       on a new disk; warn her before she does mke2fs on it */
 	    int pagesize = getpagesize();
@@ -408,7 +445,7 @@
 	    if (rd > sizeof(buf))
 		    rd = sizeof(buf);
 	    if (lseek(fd, 0, SEEK_SET) != 0
-		|| read(fd, buf, rd) != rd)
+		|| read_dev(fd, buf, rd) != rd)
 		    goto io_error;
 	    if (may_be_swap(buf+pagesize) ||
 		may_be_swap(buf+4096) || may_be_swap(buf+8192))
