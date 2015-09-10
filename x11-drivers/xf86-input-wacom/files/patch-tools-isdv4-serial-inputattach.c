--- tools/isdv4-serial-inputattach.c~
+++ tools/isdv4-serial-inputattach.c
@@ -23,8 +23,10 @@
 #include "config.h"
 #endif
 
+#ifdef __linux__
 #include <linux/serio.h>
 #include <libudev.h>
+#endif
 
 #include <getopt.h>
 #include <stdio.h>
@@ -49,7 +52,11 @@ static void usage(void)
 		"--verbose             - verbose output\n"
 		"--version             - version info\n"
 		"--baudrate <19200|38400>  - set baudrate\n",
+#ifdef __GLIBC__
 		program_invocation_short_name
+#else
+		getprogname()
+#endif
 	      );
 }
 
@@ -64,6 +71,7 @@ static int set_line_discipline(int fd, i
 	return rc;
 }
 
+#ifdef __linux
 static int bind_kernel_driver(int fd)
 {
 	unsigned long devt;
@@ -77,9 +84,11 @@ static int bind_kernel_driver(int fd)
 
 	return 0;
 }
+#endif
 
 static unsigned int get_baud_rate(int fd)
 {
+#ifdef __linux__
 	struct stat st;
 	unsigned int baudrate = 19200;
 	int id;
@@ -112,6 +122,9 @@ int get_baud_rate(int fd)
 	udev_unref(udev);
 
 	return baudrate;
+#else
+	return 19200;
+#endif
 }
 
 void sighandler(int signum)
@@ -194,6 +207,7 @@ int main(int argc, char **argv)
 		return 1;
 	}
 
+#ifdef __linux__
 	/* some of the 19200 tablets can't set the line discipline */
 	set_line_discipline(fd, N_MOUSE);
 
@@ -201,6 +215,7 @@ int main(int argc, char **argv)
 		fprintf(stderr, "Failed to bind the kernel driver.\n");
 		goto out;
 	}
+#endif
 
 	signal(SIGINT, sighandler);
 	signal(SIGHUP, sighandler);
