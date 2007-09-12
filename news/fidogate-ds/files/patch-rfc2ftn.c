Index: src/gate/rfc2ftn.c
===================================================================
RCS file: /cvsroot/rusfidogate/fidogate-sta/src/gate/rfc2ftn.c,v
retrieving revision 5.2
retrieving revision 5.3
diff -u -r5.2 -r5.3
--- src/gate/rfc2ftn.c	30 Jan 2007 20:22:19 -0000	5.2
+++ src/gate/rfc2ftn.c	11 Sep 2007 20:05:16 -0000	5.3
@@ -1072,7 +1072,7 @@
 		}
 		else
 		{
-		    if(s_rfcaddr_to_asc(&rfc_from, FALSE) !=NULL)
+		    if(pna_notify(s_rfcaddr_to_asc(&rfc_from, FALSE)))
 		    {
 			fglog("BOUNCE: Postings from address `%s' to group `%s' not allowed - skipped, sent notify",
 			      s_rfcaddr_to_asc(&rfc_from, FALSE), pa->group);
@@ -1134,7 +1134,7 @@
 	}
 	else
 	{
-	    if(s_rfcaddr_to_asc(&rfc_from, FALSE) !=NULL)
+	    if(pna_notify(s_rfcaddr_to_asc(&rfc_from, FALSE)))
 	    {
 		fglog("BOUNCE: Gateway netmail from address `%s' to `%s' not allowed - skipped, sent notify",
 		      s_rfcaddr_to_asc(&rfc_from, FALSE), asc_node_to);
