
$FreeBSD$

--- radauth.c.orig
+++ radauth.c
@@ -137,13 +137,14 @@
 	int c;
 	
 	fnInitialize(&radhead);			/* initialize the header and global variables	*/
+	global.verbose=0;			/*clear it however should be zero since it is global variable */
 
 	while ((c = getopt(argc, argv, "hvu:p:s:r:c:t:")) != EOF)
 	{
 		switch (c)
 		{
 			case 'v':		/* enable verbose output			*/
-				global.verbose = 1;
+				global.verbose++ ;
 				break;
 			case 'u':		/* set username					*/
 				strncpy(global.username,optarg,LEGAL_SIZE(global.username));
@@ -254,11 +255,13 @@
 		{
 			fprintf(stdout,"no radius server defined, aborting.\n");
 
-			exit(0);
+			exit(3);
 		}
 	}
 	
+/*
 	fprintf(stdout,"\n");
+*/
 
 	return;
 }
@@ -303,7 +306,7 @@
 	fprintf(stdout,"\t-t [auth timeout]\tinterval to wait until auth timeout in seconds\n");
 	fprintf(stdout,"\t-h\t\t\tthis menu\n");
 
-	exit(0);
+	exit(3);
 }
 
 /*
@@ -331,13 +334,12 @@
 	/* Calculate the radius header length			*/
 	fnCalculateHeaderLength(radhead);
 
-#ifdef DEBUG	/* Print debug information if debugging		*/
-	fprintf(stdout,"rad_code = %i\n",radhead->rad_code);
-	fprintf(stdout,"rad_id   = %i\n",radhead->rad_id);
-	fprintf(stdout,"hashpwlen= %i\n",hashpwlen);
-	fnPrintHash(global.password.pw_hash,hashpwlen);
-	fprintf(stdout,"rad_length = %i\n",radhead->rad_length);
-#endif
+	if (global.verbose>1) {	/* Print debug information if debugging	*/
+		fprintf(stdout,"rad_code = %i\n",radhead->rad_code);
+		fprintf(stdout,"rad_id   = %i\n",radhead->rad_id);
+		fprintf(stdout,"hashpwlen= %i\n",hashpwlen);
+		fnPrintHash(global.password.pw_hash,hashpwlen);
+		fprintf(stdout,"rad_length = %i\n",ntohs(radhead->rad_length));	}
 }
 
 /*
@@ -357,9 +359,9 @@
 	for (x = 0; x < REQ_AUTH_LENGTH;x++)	/* until then end of auth field has been reached 	*/
 	{
 		randnumb = rand()%128+127;
-#ifdef DEBUG
-		fprintf(stdout,"randnumb is = %i\n",randnumb);
-#endif
+		if (global.verbose>1){
+			fprintf(stdout,"randnumb is = %i\n",randnumb);
+		}
 		auth[x] = randnumb;
 	}
 
@@ -478,7 +480,7 @@
 	{
 		fprintf(stderr,"malloc failure, abort.\n");
 
-		exit(0);
+		exit(3);
 	}
 
 	curr->next = NULL;
@@ -523,14 +525,14 @@
 	{
 		headlength += curr->attr_length;
 
-#ifdef DEBUG
-		fprintf(stdout,"attr length = %i\n",curr->attr_length);
-#endif
+		if (global.verbose >1 ){
+			fprintf(stdout,"attr length = %i\n",curr->attr_length);
+		}
 
 		curr = curr->next;
 	}
 
-	radhead->rad_length = headlength;	/* set the final length					*/
+	radhead->rad_length = htons(headlength);	/* set the final length					*/
 
 	return;
 }
@@ -543,7 +545,6 @@
  *
  */
 
-#ifdef DEBUG
 void fnPrintHash(unsigned char *hash, int len)
 {
 	int x = 0;
@@ -557,7 +558,6 @@
 
 	return;
 }
-#endif
 
 /*
  * fnSendAndReceivePacket
@@ -569,7 +569,7 @@
 void fnSendAndReceivePacket(RADIUS_HEADER *radhead)
 {
 	RADIUS_ATTR *curr = radhead->rad_attr;
-	unsigned char packet[radhead->rad_length], firstlet;
+	unsigned char packet[ntohs(radhead->rad_length)], firstlet;
 	int pktpos = 0, sock, slen;
 	struct sockaddr_in s;
 	struct hostent *h;
@@ -577,7 +577,7 @@
 	fd_set fdread;
 
 	/* clear the packet to be sent */
-	memset(packet,0,radhead->rad_length);
+	memset(packet,0,ntohs(radhead->rad_length));
 
 	/* copy the first 20 bytes of the radius header.  this size is static
 	 * per RFC.
@@ -628,7 +628,7 @@
 	{
 		fprintf(stdout,"unable to allocate udp socket, abort.\n");
 
-		exit(0);
+		exit(3);
 	}
 
 	s.sin_family = AF_INET;
@@ -641,7 +641,7 @@
 		{
 			fprintf(stdout,"unable to resolve radius server: %s. abort.\n",global.radiusserver);
 
-			exit(0);
+			exit(3);
 		}
 
 		memcpy(&s.sin_addr.s_addr,h->h_addr,h->h_length);
@@ -649,14 +649,15 @@
 
 	/* send the packet to the radius server */
 
-	if (sendto(sock,(char *)packet,radhead->rad_length,0,(struct sockaddr *)&s,sizeof(s)) < 0)
+	if (sendto(sock,(char *)packet,ntohs(radhead->rad_length),0,(struct sockaddr *)&s,sizeof(s)) < 0)
 	{
 		fprintf(stdout,"error sending UDP packet to radius server. abort.\n");
 
-		exit(0);
+		exit(3);
 	}
 
-	fprintf(stdout,"Authentication request sent to %s:%i ... (timeout = %i)\n",global.radiusserver,global.radiusport,global.authtimeout);
+/*	fprintf(stdout,"Authentication request sent to %s:%i ... (timeout = %i)\n",global.radiusserver,global.radiusport,global.authtimeout);
+*/
 
 	slen = sizeof(s);
 
@@ -670,6 +671,7 @@
 	if (!select(sock + 1, &fdread, NULL, NULL, &tv))
 	{
 		fprintf(stdout,"failed to receive a reply from the server, authentication FAILED.\n");
+		exit(2);
 
 		return;
 	}
@@ -681,15 +683,19 @@
 	{
 		case 2:		/* Access-Accept	*/
 			fprintf(stdout,"Access GRANTED. (code = 2)\n");
+			exit(0);
 			break;
 		case 3:		/* Access-Reject	*/
 			fprintf(stdout,"Access DENIED. (code = 3)\n");
+			exit(2);
 			break;
 		case 11:
 			fprintf(stdout,"challenge issued, ignored. (code = 11)\n");
+			exit(2);
 			break;
 		default:
 			fprintf(stdout,"unknown code.  (code = %i)\n",firstlet);
+			exit(2);
 			break;
 	}
 
