--- cdpr.c.orig	2016-06-20 14:44:21 UTC
+++ cdpr.c
@@ -641,7 +641,7 @@ main(int argc, char *argv[])
 	pcap_lookupnet(dev, &net, &mask, errbuf);
 
 	/* Open the pcap device */
-	if((handle = pcap_open_live(dev, BUFSIZ, 1, 0, errbuf)) == NULL)
+	if((handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf)) == NULL)
 	{
 		printf("Error opening device (%s)\n", errbuf);
 		exit(1);
@@ -658,11 +658,6 @@ main(int argc, char *argv[])
 	pcap_setfilter(handle, &filter);
 	pcap_freecode(&filter);
 
-	/* Set non-blocking mode */
-	if(pcap_setnonblock(handle, 1, errbuf))
-	{
-		pcap_perror(handle, NULL);
-	}
 
 	/* Get the next packet that comes in, we only need one */
 	printf("Waiting for CDP advertisement:\n");
@@ -673,11 +668,7 @@ main(int argc, char *argv[])
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
