--- rate.c.orig	2003-08-20 15:22:28 UTC
+++ rate.c
@@ -74,6 +74,7 @@ int opt_separator = 0;
 int opt_cls = 0;
 int opt_dns = 1;
 int opt_cols = 80;
+int opt_promisc = 0;
 
 #ifdef HAVE_REGEX
 char * opt_regex = NULL;
@@ -214,6 +215,7 @@ void help(unsigned char * name)
 	printf("  -p <pref> Datalink layer header size (gets substracted from each packet size, default: 14)\n");
 	printf("  -s <b>    Capture l bytes (default: 40)\n");
 	printf("  -i <int>  Bind to interface <int> - default eth0\n");
+	printf("  -P	    Bring the interface into promiscuous mode\n");
 	printf("  -n        Numeric IPs. Don't do reverse DNS lookups.\n");
 	printf("  -c        Use colors (ANSI-compatible) whenever possible.\n");
 	printf("  -v        Print exact values, do not use SI prefixes.\n");
@@ -264,7 +266,7 @@ int main(int argc, char ** argv)
 		}
 	}
 	
-	while((c = getopt(argc, argv, "?hr:q:f:p:s:i:S:x:0:glkcvwenRATE")) != EOF)
+	while((c = getopt(argc, argv, "?hr:q:f:p:s:i:P:S:x:0:glkcvwenRATE")) != EOF)
 	{
 		if(c == 'R' || c == 'A' || c == 'T' || c == 'E')
 			break;
@@ -284,6 +286,7 @@ int main(int argc, char ** argv)
 			case 'k': opt_onkeyboard = 1; break;
 			case 'c': opt_color = 1; break;
 			case 'v': opt_human = 0; break;
+			case 'P': opt_promisc = 1; break;
 			case 'e': opt_separator = 1; break;
 			case 'w': opt_cls = 1; break;
 			case 'n': opt_dns = 0; break;
@@ -311,7 +314,7 @@ int main(int argc, char ** argv)
 		}
 	}
 
-	if((handle = pcap_open_live(interface, 2048, -1, 50, ebuff))==NULL)
+	if((handle = pcap_open_live(interface, 2048, opt_promisc, 50, ebuff))==NULL)
 	{
 		fprintf(stderr, "pcap_open_live(): %s\n", ebuff);
 		return(0);
