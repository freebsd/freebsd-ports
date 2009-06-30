Index: bgpd/rde_filter.c
===================================================================
RCS file: /home/cvs/private/hrs/openbgpd/bgpd/rde_filter.c,v
retrieving revision 1.1.1.1
retrieving revision 1.2
diff -u -p -r1.1.1.1 -r1.2
--- bgpd/rde_filter.c	30 Jun 2009 05:46:15 -0000	1.1.1.1
+++ bgpd/rde_filter.c	30 Jun 2009 06:51:37 -0000	1.2
@@ -614,4 +614,5 @@ filterset_name(enum action_types type)
 	}
 
 	fatalx("filterset_name: got lost");
+	return (NULL); /* NOT REACHED */
 }
