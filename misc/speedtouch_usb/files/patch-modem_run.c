--- modem_run.c.orig	Tue Aug  7 22:57:21 2001
+++ modem_run.c	Tue Aug  7 23:08:42 2001
@@ -216,6 +216,7 @@
   printf("usage: modem_run [-v] [-f microcode] [-m]\n");
   printf("  -v : verbose mode\n");
   printf("  -f microcode : upload this microcode file first\n");
+  printf("  -d device : use this USB device\n");
   printf("  -m : monitor the line\n");
   printf("  --help : this message\n");
   exit (-1);
@@ -611,6 +612,7 @@
 	int verbose = 0, monitoring = 0;
 	unsigned char buf[TOTAL+1000], prevbuf[TOTAL];
 	const char * file = NULL;
+	const char * device = NULL;
 	
 	for (i=1;i<argc;i++)
 		if (strcmp(argv[i],"-v")==0)
@@ -619,6 +621,8 @@
 			monitoring = 1;
 		else if (strcmp(argv[i],"-f")==0 && i+1<argc)
 			file = argv[++i];
+		else if (strcmp(argv[i],"-d")==0 && i+1<argc)
+			device = argv[++i];
 		else if (strcmp(argv[i],"--help")==0)
 			usage();
 		else
@@ -627,16 +631,29 @@
 	if (file == NULL)
 		usage();
 
-	/* we search the modem on the USB bus */
-	fdusb = pusb_search_open(ST_VENDOR,ST_PRODUCT);
-	if (fdusb == NULL)
-    {
-		printf("I'm sorry, I didn't find your ADSL modem!\n");
-		printf("Tips: check that you are running this program as root"
-			   " and your device is seen by Linux"
-			   " by checking /proc/bus/usb/devices\n");
-		return -1;
-    }
+	if (device == NULL)
+	{
+		/* we search the modem on the USB bus */
+		fdusb = pusb_search_open(ST_VENDOR,ST_PRODUCT);
+		if (fdusb == NULL)
+	    {
+			printf("I'm sorry, I didn't find your ADSL modem!\n");
+			printf("Tips: check that you are running this program as root"
+				   " and your device is seen by Linux"
+				   " by checking /proc/bus/usb/devices\n");
+			return -1;
+	    }
+	}
+	else
+	{
+		fdusb = pusb_open(device);
+		if (fdusb == NULL)
+		{
+			printf("I'm sorry, I could not open your ADSL modem at %s\n",
+			       device);
+			return -1;
+		}
+	}
 	
 	printf("Gotcha, I found your ADSL ALCATEL SpeedTouch USB modem!\n");
 
