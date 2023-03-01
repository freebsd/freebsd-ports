--- vbetool.c.orig	2008-05-16 12:56:30 UTC
+++ vbetool.c
@@ -16,8 +16,12 @@ version 2
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
@@ -37,6 +41,9 @@ static struct pci_access *pacc;
 #define DPMS_STATE_LOW 0x0800
 
 static struct pci_access *pacc;
+#ifdef __FreeBSD__
+#define	DEV_IO_PATH	"/dev/io"
+#endif
 
 int vbetool_init (void) {
 	if (!LRMI_init()) {
@@ -44,7 +51,14 @@ int vbetool_init (void) {
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
@@ -117,8 +131,8 @@ int main(int argc, char *argv[])
 			void *rc;
 			int romfd = open (argv[2], O_RDWR);
 
-			munmap(0xc0000, 64*1024);
-			rc = mmap(0xc0000, 64*1024,
+			munmap((void *)(uintptr_t)0xc0000, 64*1024);
+			rc = mmap((void *)(uintptr_t)0xc0000, 64*1024,
 				  PROT_READ|PROT_WRITE|PROT_EXEC,
 				  MAP_FIXED|MAP_PRIVATE, romfd, 0);
 		}
@@ -267,7 +281,9 @@ void restore_state_from(char *data)
 
 	LRMI_free_real(data);
 
+#ifndef __FreeBSD__
 	ioctl(0, KDSETMODE, KD_TEXT);
+#endif
 
 }
 
@@ -489,7 +505,9 @@ int check_console()
 		return 11;
 	}
 
+#ifndef __FreeBSD__
 	ioctl(0, KDSETMODE, KD_GRAPHICS);
+#endif
 	return 0;
 }
 
