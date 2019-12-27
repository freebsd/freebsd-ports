--- tcpshow.c.orig	2019-12-27 02:43:00 UTC
+++ tcpshow.c
@@ -189,6 +189,7 @@
 /****==========------------------------------------------------==========****/
 #endif
 
+/* tm020221: modification of Tomo.M on 2002/02/21 */ 
 
 #include <sys/types.h>                 // mr971021 Next four includes
 #include <sys/socket.h>
@@ -204,6 +205,7 @@
 #include <unistd.h>
 #include <stdlib.h>
 #include <stdio.h>
+#include <locale.h>
 
 
 /* Some general defines.                                                    */
@@ -362,18 +364,21 @@ typedef unsigned char uchar;
 #if !defined(NOETHERNAMES)
 // mr980118 ether_ntohost() and related functions aren't prototyped in the
 // standard include directory.
+#ifndef __FreeBSD__
 extern struct ether_addr *ether_aton(char *);
 extern int ether_ntohost(char *, struct ether_addr *);
 #endif
+#endif
 
 
-void main(int, char **);
+int main(int, char **);
 
 
 static boolean noBflag = FALSE;
 static char *cookArgs[MAXCOOKARGS+1];
 static boolean cookedFlag = FALSE;
-static uint2 dataLen = 0;
+static int2 dataLen = 0;               // tm020221 must be 'signed'.
+static unsigned captLen = 0;
 static char *dfltCookArgs[] = {
    COOKER, "-enx", "-s10240", "-r-", (char *)NULL
 };
@@ -512,7 +517,9 @@ static char *deltaTime (double *prevTime
       return "";
    }
 
-   delta = currTime - *prevTime;
+   // tm020221 delta should be positive value, but ...
+   delta = currTime >= *prevTime ? currTime - *prevTime
+              : multiplier * 86400 + currTime - *prevTime;
    *prevTime = currTime;
 
    // Convert the delta time to daytime representation.
@@ -790,25 +797,38 @@ static char *getPkt () {
    static boolean beenHereAlready = FALSE;
    static char pktBuf[MAXPKT+1];
 
-
+ nextline:
    if (fgets(pktBuf, MAXPKT+1, stdin) == (char *)NULL) {
       if (nPktsShown > 0) prSep();
       exit(0);
    }
 
-   /* Line without leading <tab> means start of new packet.                 */
-   if (*pktBuf == '\t')
-      return pkt = rmWSpace(pktBuf);
-   elif (!beenHereAlready) {           /* setjmp() won't have been called   */
-      beenHereAlready = TRUE;          /*  before reading 1st packet        */
-      return pkt = pktBuf;
+   // tm020221
+   // In these days, tcpdump produces much of irregular outputs.
+   // I had a work around by making logical change to original.
+   //  + check lines in its pattern.
+   //  + HEADER pattern triggers next showPkt();
+
+#define PTN_HEAD(buf)  (buf[2] == ':' && buf[5] == ':' && buf[8] == '.')
+#define PTN_DATA(buf)  (buf[0] == '\t')
+
+   if (PTN_HEAD(pktBuf)) {
+     if (beenHereAlready == FALSE) {
+       beenHereAlready = TRUE;
+       return pkt = pktBuf;
+     } else {
+       putchar('\n');
+       if (dataLen > 0)
+	 printf("\n\t<*** Rest of data missing from packet dump ***>\n");
+       pkt = pktBuf;
+       longjmp(jmpBuf, 1);
+     }
    }
-   else {
-      if (dataLen > 0)
-         printf("\n\t<*** Rest of data missing from packet dump ***>\n");
-      pkt = pktBuf;
-      longjmp(jmpBuf, 1);
+   elif (PTN_DATA(pktBuf)) {
+     if (nPktsShown > 0)
+       return pkt = rmWSpace(pktBuf);
    }
+   goto nextline;
 
 }
 
@@ -1125,7 +1145,9 @@ static char *icmpExtras (
 static char *icmpType (uint1 type) {
 
    char *descr;
+   static char unknowntype[80];
 
+   snprintf(unknowntype, 80, "%s (%d)", unknown, type);
 
    switch (type) {
     case ECHO_REPLY:  descr = "echo-reply";              break;
@@ -1143,7 +1165,7 @@ static char *icmpType (uint1 type) {
     case INFO_REPLY:  descr = "information-reply";       break;
     case MASK_REQ:    descr = "address-mask-request";    break;
     case MASK_REPLY:  descr = "address-mask-reply";      break;
-    default:          descr = unknown;                   break;
+    default:          descr = unknowntype;               break;
    }
 
    return descr;
@@ -1241,6 +1263,15 @@ static char *ipProto (uint1 code) {
 
 }
 
+void checklocale(void) {
+
+  char *lc;
+  
+  if ((lc = getenv("LC_CTYPE")) != NULL) setlocale(LC_CTYPE,lc);
+  else if ((lc = getenv("LC_ALL")) != NULL) setlocale(LC_ALL,lc);
+  
+  return;
+}
 
 /****==========------------------------------------------------==========****/
 /*                                                                          */
@@ -1248,7 +1279,7 @@ static char *ipProto (uint1 code) {
 /*                                                                          */
 /****==========------------------------------------------------==========****/
 
-void main (int argc, char **argv) {
+int main (int argc, char **argv) {
 
    /* Command line options.                                                 */
    while (--argc > 0 && **++argv == '-')
@@ -1281,15 +1312,23 @@ void main (int argc, char **argv) {
       }
       else error("Unknown command line flag");
 
+   checklocale();
+   
    if (!cookedFlag)
       forkTcpdump(argc, argv);
    elif (argc != 0)
       fprintf(stderr, "input is cooked -- ignoring tcpdump expressions\n");
 
-   pkt = getPkt();
-   for ( ; ; ) if (!setjmp(jmpBuf)) showPkt(pkt);
+   // tm020221
+   // changed setjmp/longjmp logic to trigger the showPkt()
+   for ( ; ; ) {
+     pkt = getPkt();
+     if (setjmp(jmpBuf) || nPktsShown <= 0)
+       showPkt(pkt);
+   }
 
    exit(0);
+   return 0;
 
 }
 
@@ -1336,7 +1375,7 @@ static char *portName (uint2 port, char 
 	 name = number;
       }
    /* The crappy manpage doesn't say the port must be in net byte order.    */
-   elif (service = getservbyport((int)htons(port), proto))
+   elif ( (service = getservbyport((int)htons(port), proto)) )
       name = service->s_name;
    elif (!wantNumber)
       name = unknown;
@@ -1371,6 +1410,9 @@ static char *rmWSpace (reg char *pktBuf)
    }
    *cleanBuf = '\0';
 
+   if ((*cleanPkt == '0') && (*(cleanPkt+1) == 'x'))
+      return cleanPkt+7;
+
    return cleanPkt;
 
 }
@@ -1572,7 +1614,7 @@ static char *showHdr (char *p) {
    char eFromName[MAX_HOSTNAMELEN+1];  // Sender Ethernet name
    char eTo[ETHER_ADDRLEN+1];          /* Destination Ethernet address      */
    char eToName[MAX_HOSTNAMELEN+1];    // Target Ethernet name
-   char eType[20];                     /* Ethernet type (decoded to ASCII)  */
+   char eType[40];                     /* Ethernet type (decoded to ASCII)  */
    static double prevTime;             // Timestamp of previous packet
    char time[16];                      /* Packet timestamp                  */
 
@@ -1580,25 +1622,55 @@ static char *showHdr (char *p) {
    if (ppFlag) {
       (void)sscanf(p, "%s", time);
       etherType = ETHER_PROTO_IP;      /* tcpdump doesn't supply link type  */
-      if (!noLinkFlag)
+      if (!noLinkFlag) {
          if (terseFlag)
 	    printf("TIME:\t%s%s\n", time, deltaTime(&prevTime, time));
          else
 	    printf(
 	       "\tTimestamp:\t\t\t%s%s\n", time, deltaTime(&prevTime, time)
 	    );
+	}
       return getPkt();
    }
 
    (void)sscanf(p, "%s %s %s %s", time, eFrom, eTo, eType);
-   (void)etherProto(eType, &etherType);
+   captLen = 0;
+
+   /* decode output from tcpdump-3.8.x and later */
+   /* format: TIME MACSRC > MACDST, ethertype TYPE (0xCODE), ... */
+   if (*eTo == '>') {
+     char *s;
+     
+     if ((s = strstr(p, "length ")) != NULL)
+       (void)sscanf(s + 7, "%u", &captLen);
+     
+     (void)sscanf(p, "%s %s > %17s", time, eFrom, eTo);
+     if ((s = strstr(p, "ethertype ")) != NULL) {
+       strlcpy(eType, s+10, sizeof(eType));
+       if ((s = strchr(eType, ' ')) != NULL) {
+         *s = '\0';
+	 *(s+8)='\0';
+	 (void)etherProto(s+4, &etherType);
+       }
+       else {
+	 etherType = 0;
+       }
+     }
+     else {
+        strlcpy(eType, unknown, sizeof(eType));
+        etherType = 0;
+     }
+   }
+   /* decode output from tcpdump-3.7.4 and earlier */
+   else
+     (void)etherProto(eType, &etherType);
 
    (void)strcpy(eFrom, etherAddr(eFrom, 0));
    (void)strcpy(eFromName, etherName(eFrom, TRUE));
    (void)strcpy(eTo, etherAddr(eTo, 0));
    (void)strcpy(eToName, etherName(eTo, TRUE));
 
-   if (!noLinkFlag)
+   if (!noLinkFlag) {
       if (terseFlag) {
          printf("TIME:\t%s%s\n", time, deltaTime(&prevTime, time));
          printf(
@@ -1614,6 +1686,7 @@ static char *showHdr (char *p) {
          if (!noEtherNames) printf(" (%s)", etherName(eTo, FALSE));
          printf("\n\tEncapsulated Protocol:\t\t%s\n", etherProto(eType, 0));
       }
+   }
 
    return getPkt();
 
@@ -1718,6 +1791,8 @@ static char *showIp (char *p) {
    (void)strcpy(sIp, ipAddr(&p)); nSkipped += 4;
    (void)strcpy(dIp, ipAddr(&p)); nSkipped += 4;
    hLen     = (ver & 0x0F) * 4;
+   if (dgramLen == 0 && captLen >= 14)
+     dgramLen = captLen - 14;
    dataLen  = dgramLen - hLen;
 
    (void)strcpy(sHostName, hostName(sIp, TRUE));
@@ -1778,7 +1853,7 @@ static char *showIp (char *p) {
 static void showPkt (reg char *p) {
 
    char *warnMsg = "<*** No decode support for encapsulated protocol ***>";
-
+   char *warnMsg2 = "<*** No decode support for encap protocol in IPIP packet ***>";
 
    prSep();
    printf("Packet %d\n", ++nPktsShown);
@@ -1807,6 +1882,31 @@ static void showPkt (reg char *p) {
 	 p = showIcmp(p);
 	 p = showData(p);
 	 break;
+	 
+	 // IPIP decode support by M. Nowlin (mike@argos.org) 20000321
+       case IPIP:
+	  p = showIp(p);
+	  switch(proto) {
+	   case TCP:
+	     p = showTcp(p);
+	     p = showData(p);
+	     break;
+	   case UDP:
+	     p = showUdp(p);
+	     p = showData(p);
+	     break;
+	   case ICMP:
+	     p = showIcmp(p);
+	     p = showData(p);
+	     break;
+	   default:
+	     printf("\t%s\n", warnMsg2);
+	     nextPkt();
+	     break;
+	 }
+	 
+	 break;
+	  
        default:
 	 printf("\t%s\n", warnMsg);
 	 nextPkt();                    /* Doesn't return                    */
@@ -1826,7 +1926,7 @@ static void showPkt (reg char *p) {
    }
    /* Note that if getPkt() returns here, then the line read isn't the      */
    /* start of a new packet, i.e. there's spurious data.                    */
-   if (p = getPkt()) {
+   if ( (p = getPkt()) ) {
       if (sFlag) printf("\t<*** Spurious data at end: \"%s\" ***>\n", p);
       nextPkt();
    }
@@ -1996,10 +2096,10 @@ static char *showTcp (char *p) {
 
    if (terseFlag) {
       printf(
-	 " TCP:\tport %s -> %s seq=%010lu", sPortName, dPortName, seq
+	 " TCP:\tport %s -> %s seq=%010lu", sPortName, dPortName, (u_long)seq
       );
-      if (trackFlag) printf(" (expect=%010lu)", expect);
-      printf(" ack=%010lu\n", ack);
+      if (trackFlag) printf(" (expect=%010lu)", (u_long)expect);
+      printf(" ack=%010lu\n", (u_long)ack);
       printf(
          "\thlen=%d (data=%u) UAPRSF=%s%s%s%s%s%s",
          hLen, dataLen,
@@ -2016,9 +2116,9 @@ static char *showTcp (char *p) {
       if (!noPortNames) printf(" (%s)", portName(sPort, "tcp", FALSE));
       printf("\n\tDestination Port:\t\t%d", dPort);
       if (!noPortNames) printf(" (%s)", portName(dPort, "tcp", FALSE));
-      printf("\n\tSequence Number:\t\t%010lu\n", seq);
-      if (trackFlag) printf("\tExpect peer ACK:\t\t%010lu\n", expect);
-      printf("\tAcknowledgement Number:\t\t%010lu\n", ack);
+      printf("\n\tSequence Number:\t\t%010lu\n", (u_long)seq);
+      if (trackFlag) printf("\tExpect peer ACK:\t\t%010lu\n", (u_long)expect);
+      printf("\tAcknowledgement Number:\t\t%010lu\n", (u_long)ack);
       printf("\tHeader Length:\t\t\t%d bytes (data=%u)\n", hLen, dataLen);
       printf(
          "\tFlags:%s%s%s%s%s%s\n%s%s%s%s%s%s\n",
