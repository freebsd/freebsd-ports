--- wmbsdbatt.c.orig	Sat Jul  2 15:23:41 2005
+++ wmbsdbatt.c	Sat Jul  2 15:35:19 2005
@@ -33,6 +33,7 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
+#include <unistd.h>
 
 #include <sys/types.h>
 #include <sys/stat.h>
@@ -112,14 +113,26 @@
 void	draw_all(void);
 int	init_stats(void);
 int	acpi_exists(void);
+void	usage(void);
 #if 0
 void	draw_rate(void);
 #endif
 
+void
+usage(void)
+{
+	fprintf(stderr, "%s\n%s\n%s\n",
+	    "usage: wmbsdbatt [-h | -b]",
+	    "   -h	help",
+	    "   -b	start with backlight on");
+
+	exit(0);
+}
+
 int
 main(int argc, char **argv)
 {
-	int charging, ncolor, show;
+	int charging, ncolor, show, ch;
 	long timeout;
 	long animation_timeout, update_timeout;
 	struct sigaction sa;
@@ -132,6 +145,19 @@
 
 	sa.sa_handler = SIG_IGN;
 	sa.sa_flags = SA_NOCLDWAIT;
+	while ((ch = getopt(argc, argv, "bh")) != -1) {
+		switch (ch) {
+		case 'b':
+			backlight = LIGHTON;
+			break;
+		case 'h':
+			usage();
+			break;
+		default:
+			usage();
+			break;
+		}
+	}
 
 	sigemptyset(&sa.sa_mask);
 	sigaction(SIGCHLD, &sa, NULL);
