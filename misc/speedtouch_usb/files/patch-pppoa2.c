--- pppoa2.c.orig	Tue Aug  7 23:02:15 2001
+++ pppoa2.c	Tue Aug  7 23:06:41 2001
@@ -890,6 +890,7 @@
 {
 	char *logfile;
 	int   fdin, fdout, log;
+	const char * device = NULL;
 	int   i;
 
 	pusb_device_t fdusb;
@@ -908,6 +909,8 @@
 			my_vci = atoi(argv[++i]);
 		else if(strcmp(argv[i], "--help") == 0)
 			usage();
+		else if(strcmp(argv[i], "-d") == 0 && i + 1 < argc)
+			device = argv[++i];
 		else if(strcmp(argv[i], "-f") == 0 && i + 1 < argc) {
 			logfile   = argv[++i];
 			if(!verbose) verbose = 1;
@@ -1049,17 +1052,26 @@
 #endif
 	}
 
-	/*
-	*  We search for the first USB device matching ST_VENDOR & ST_PRODUCT.
-	*  usbdevfs must be mount on /proc/bus/usb (or you may change the path
-	*  here, according to your config
-	*/
+	if (device == NULL) {
+		/*
+		*  We search for the first USB device matching ST_VENDOR & ST_PRODUCT.
+		*  usbdevfs must be mount on /proc/bus/usb (or you may change the path
+		*  here, according to your config
+		*/
 
-	fdusb = pusb_search_open(ST_VENDOR, ST_PRODUCT);
+		fdusb = pusb_search_open(ST_VENDOR, ST_PRODUCT);
 
-	if(fdusb == NULL && verbose) {
-		printf("< pid=%d > Where is this crappy modem ?!\n", this_process);
-		return(-1);
+		if(fdusb == NULL && verbose) {
+			printf("< pid=%d > Where is this crappy modem ?!\n", this_process);
+			return(-1);
+		}
+	} else {
+		fdusb = pusb_open(device);
+
+		if(fdusb == NULL && verbose) {
+			printf("< pid=%d > The modem is not at %s\n", this_process, device);
+			return(-1);
+		}
 	}
 
 	/*Debug message*/
