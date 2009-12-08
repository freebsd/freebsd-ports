--- mtools/syslinux.c.orig	2009-10-06 02:06:06.000000000 +0400
+++ mtools/syslinux.c	2009-12-04 11:18:37.000000000 +0300
@@ -38,6 +38,8 @@
 #include "syslinux.h"
 #include "libfat.h"
 
+int verbose=0;
+
 char *program;			/* Name of program */
 char *device;			/* Device to install to */
 pid_t mypid;
@@ -123,6 +125,53 @@
     return xpread(pp, buf, secsize, offset);
 }
 
+/*
+ * load a file to be used as boot image
+ */
+static int load_boot_image(const char *name)
+{
+    int l, fd;
+    struct stat sb;
+    unsigned char *buf;
+
+    memset(&sb, 0, sizeof(sb));
+    fd = open(name, O_RDONLY);
+    if (fd < 0) {
+	fprintf(stderr, "cannot open boot image %s\n", name);
+	return 1;
+    }
+    if (fstat(fd, &sb)) {
+	fprintf(stderr, "cannot stat boot image %s\n", name);
+	return 1;
+    }
+    if ( (sb.st_mode & S_IFREG) == 0) {
+	fprintf(stderr, "boot image %s is not a file 0x%x\n", name, sb.st_mode);
+	return 1;
+    }
+    if (sb.st_size < 1024 || sb.st_size > 0x8000) {
+	fprintf(stderr, "boot image %s bad size %lld\n", name, sb.st_size);
+	return 1;
+    }
+    buf = calloc(1, sb.st_size);
+    if (buf == NULL) {
+	fprintf(stderr, "malloc failed for boot image %s\n", name);
+	return 1;
+    }
+    l = read(fd, buf, sb.st_size);
+    if (l != sb.st_size) {
+	fprintf(stderr, "read failed for boot image %s got %d\n", name, l);
+	return 1;
+    }
+    if (buf[0] != 0xeb || buf[0x200] != 0x0d) {
+	fprintf(stderr, "bad content for boot image %s\n", name);
+	return 1;
+    }
+    syslinux_bootsect = buf;
+    syslinux_ldlinux = buf + 512;
+    syslinux_ldlinux_len = sb.st_size - 512;
+    return 0;
+}
+
 int main(int argc, char *argv[])
 {
     static unsigned char sectbuf[512];
@@ -160,6 +209,10 @@
 	    while (*opt) {
 		if (*opt == 's') {
 		    stupid = 1;
+		} else if ( *opt == 'v' ) {
+		    verbose++;
+		} else if ( *opt == 'b' && argp[1] ) {
+		    load_boot_image(*++argp);
 		} else if (*opt == 'r') {
 		    raid_mode = 1;
 		} else if (*opt == 'f') {
@@ -220,11 +273,10 @@
     fprintf(mtc,
 	    /* "MTOOLS_NO_VFAT=1\n" */
 	    "MTOOLS_SKIP_CHECK=1\n"	/* Needed for some flash memories */
-	    "drive s:\n"
-	    "  file=\"/proc/%lu/fd/%d\"\n"
+	    "drive s: file=\"%s\"\n"
 	    "  offset=%llu\n",
 	    (unsigned long)mypid,
-	    dev_fd, (unsigned long long)filesystem_offset);
+	    device, (unsigned long long)filesystem_offset);
     fclose(mtc);
 
     /*
@@ -236,8 +288,10 @@
     }
 
     /* This command may fail legitimately */
+    if (verbose) fprintf(stderr, "doing mattrib\n");
     system("mattrib -h -r -s s:/ldlinux.sys 2>/dev/null");
 
+    if (verbose) fprintf(stderr, "doing mcopy\n");
     mtp = popen("mcopy -D o -D O -o - s:/ldlinux.sys", "w");
     if (!mtp || (fwrite(syslinux_ldlinux, 1, syslinux_ldlinux_len, mtp)
 		 != syslinux_ldlinux_len) ||
@@ -249,7 +303,9 @@
      * Now, use libfat to create a block map
      */
     fs = libfat_open(libfat_xpread, dev_fd);
+    if (verbose) fprintf(stderr, "libfat_open returns %p\n", fs);
     ldlinux_cluster = libfat_searchdir(fs, 0, "LDLINUX SYS", NULL);
+    if (verbose) fprintf(stderr, "libfat_searchdir returns %d\n", ldlinux_cluster);
     secp = sectors;
     nsectors = 0;
     s = libfat_clustertosector(fs, ldlinux_cluster);
@@ -257,6 +313,7 @@
 	*secp++ = s;
 	nsectors++;
 	s = libfat_nextsector(fs, s);
+	if (verbose) fprintf(stderr, "libfat_nextsector returns %d\n", s);
     }
     libfat_close(fs);
 
