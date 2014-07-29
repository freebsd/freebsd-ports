--- cdpr.c.orig	Wed Nov 19 17:53:13 2003
+++ cdpr.c	Wed Nov 19 17:54:06 2003
@@ -639,7 +639,7 @@
 	pcap_lookupnet(dev, &net, &mask, errbuf);
 
 	/* Open the pcap device */
-	if((handle = pcap_open_live(dev, BUFSIZ, 1, 0, errbuf)) == NULL)
+	if((handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf)) == NULL)
 	{
 		printf("Error opening device (%s)\n", errbuf);
 		exit(1);
@@ -656,11 +656,6 @@
 	pcap_setfilter(handle, &filter);
 	pcap_freecode(&filter);
 
-	/* Set non-blocking mode */
-	if(pcap_setnonblock(handle, 1, errbuf))
-	{
-		pcap_perror(handle, NULL);
-	}
 
 	/* Get the next packet that comes in, we only need one */
 	printf("Waiting for CDP advertisement:\n");
@@ -671,11 +666,7 @@
 	do
 	{
 		packet = pcap_next(handle, &header);
-#ifdef WIN32
-		Sleep(10000);
-#else
-		usleep(10000);
-#endif
+
 	} while ((!packet) && ( timeout=((start_time+seconds) > (unsigned int)time(NULL))) );
 
 	/*
