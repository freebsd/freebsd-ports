#
# OpenLDAP ITS#2930
#
--- servers/slapd/repl.c	2004/01/24 01:21:41
+++ servers/slapd/repl.c	2004/01/24 01:46:37
@@ -383,6 +383,7 @@
 		break;
 
 	case LDAP_REQ_ADD:
+		e = change;
 		for ( a = e->e_attrs; a != NULL; a=a->a_next ) {
 			if ( ri && ri->ri_attrs ) {
 				int is_in = ad_inlist( a->a_desc, ri->ri_attrs );
