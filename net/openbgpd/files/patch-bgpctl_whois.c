Index: bgpctl/whois.c
===================================================================
RCS file: /home/cvs/private/hrs/openbgpd/bgpctl/whois.c,v
retrieving revision 1.1.1.5
retrieving revision 1.1.1.7
diff -u -p -r1.1.1.5 -r1.1.1.7
--- bgpctl/whois.c	14 Feb 2010 20:20:14 -0000	1.1.1.5
+++ bgpctl/whois.c	13 Oct 2012 18:22:54 -0000	1.1.1.7
@@ -68,7 +68,8 @@ char *qtype_opts[] = {
 	"",
 	"-T aut-num",
 	"-K -T as-set",
-	"-K -T route -i origin"
+	"-K -T route -i origin",
+	"-K -T route6 -i origin"
 };
 
 char	*server = "whois.radb.net";
