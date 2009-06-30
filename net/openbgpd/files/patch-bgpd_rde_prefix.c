Index: bgpd/rde_prefix.c
===================================================================
RCS file: /home/cvs/private/hrs/openbgpd/bgpd/rde_prefix.c,v
retrieving revision 1.1.1.1
retrieving revision 1.2
diff -u -p -r1.1.1.1 -r1.2
--- bgpd/rde_prefix.c	30 Jun 2009 05:46:15 -0000	1.1.1.1
+++ bgpd/rde_prefix.c	30 Jun 2009 06:42:23 -0000	1.2
@@ -365,7 +365,7 @@ pt_free(struct pt_entry *pte)
 static struct pt_entry *
 pt_restart(struct pt_context *ctx)
 {
-	struct pt_entry *tmp, *prev = NULL;
+	struct pt_entry *tmp = NULL, *prev = NULL;
 	int comp;
 
 	/* first select correct tree */
