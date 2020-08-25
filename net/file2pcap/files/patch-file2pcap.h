--- file2pcap.h.orig	2019-11-21 15:44:46 UTC
+++ file2pcap.h
@@ -81,7 +81,7 @@ struct pcap_packet_header
                 int usec;
                 int length1;
                 int length2;
-        } ph;
+        };
 
 struct v6_pseudo_header 
 	{
@@ -90,10 +90,10 @@ struct v6_pseudo_header 
 		int length;
 		char zeroes[3];
 		char next_header;
-	} v6ph;
+	};
 
 
-unsigned short 	srcport, dstport;
+extern unsigned short 	srcport, dstport;
 
 
 int craftTcp(char *payload, int payloadSize, char direction, unsigned char flags, struct handover *ho);
