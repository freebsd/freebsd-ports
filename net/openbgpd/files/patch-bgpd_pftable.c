Index: bgpd/pftable.c
===================================================================
RCS file: /home/cvs/private/hrs/openbgpd/bgpd/pftable.c,v
retrieving revision 1.1.1.5
retrieving revision 1.1.1.7
diff -u -p -r1.1.1.5 -r1.1.1.7
--- bgpd/pftable.c	14 Feb 2010 20:19:57 -0000	1.1.1.5
+++ bgpd/pftable.c	13 Oct 2012 18:22:44 -0000	1.1.1.7
@@ -214,7 +214,7 @@ pftable_add_work(const char *table, stru
 
 	bzero(pfa, sizeof(*pfa));
 	memcpy(&pfa->pfra_u, &addr->ba, (len + 7U) / 8);
-	pfa->pfra_af = addr->af;
+	pfa->pfra_af = aid2af(addr->aid);
 	pfa->pfra_net = len;
 
 	pft->naddrs++;
