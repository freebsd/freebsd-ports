--- tools/tools-shared.c~
+++ tools/tools-shared.c
@@ -23,7 +23,9 @@
 
 #include <errno.h>
 #include <fcntl.h>
+#ifdef __linux__
 #include <linux/serial.h>
+#endif
 #include <getopt.h>
 #include <poll.h>
 #include <stdio.h>
@@ -51,7 +53,6 @@ void version(void)
 int open_device(const char *path)
 {
 	int fd;
-	struct serial_struct ser;
 
 	TRACE("Opening device '%s'.\n", path);
 	fd = open(path, O_RDWR | O_NOCTTY);
@@ -59,7 +60,13 @@ int open_device(const char *path)
 	if (fd < 1)
 		perror("Failed to open device file");
 
+#ifdef __linux__
+	struct serial_struct ser;
 	if (ioctl(fd, TIOCGSERIAL, &ser) == -1)
+#else
+	struct termios termAttr;
+	if (tcgetattr(fd, &termAttr) == -1)
+#endif
 	{
 		perror("Not a serial device?");
 		close(fd);
