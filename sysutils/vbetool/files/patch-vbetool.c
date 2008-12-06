--- vbetool.c	2008-05-16 08:56:30.000000000 -0400
+++ vbetool.c	2008-12-03 19:50:36.000000000 -0500
@@ -16,8 +16,12 @@
 #include <unistd.h>
 #include <sys/ioctl.h>
 #include <sys/types.h>
+#ifdef __FreeBSD__
+#include <machine/cpufunc.h>
+#else
 #include <sys/io.h>
 #include <sys/kd.h>
+#endif
 #include <sys/stat.h>
 #include <errno.h>
 #include <fcntl.h>
@@ -37,6 +41,9 @@
 #define DPMS_STATE_LOW 0x0800
 
 static struct pci_access *pacc;
+#ifdef __FreeBSD__
+#define	DEV_IO_PATH	"/dev/io"
+#endif
 
 int vbetool_init (void) {
 	if (!LRMI_init()) {
@@ -44,7 +51,14 @@
 		exit(1);
 	}
 	
+#ifdef __FreeBSD__
+	if (open(DEV_IO_PATH, O_RDONLY) < 0) {
+		fprintf(stderr, "Failed to open %s.\n", DEV_IO_PATH);
+		exit(1);
+	}
+#else
 	iopl(3);
+#endif
 	
 	pacc = pci_alloc();
 	pacc->numeric_ids = 1;
@@ -267,7 +281,9 @@
 
 	LRMI_free_real(data);
 
+#ifndef __FreeBSD__
 	ioctl(0, KDSETMODE, KD_TEXT);
+#endif
 
 }
 
@@ -489,7 +505,9 @@
 		return 11;
 	}
 
+#ifndef __FreeBSD__
 	ioctl(0, KDSETMODE, KD_GRAPHICS);
+#endif
 	return 0;
 }
 
