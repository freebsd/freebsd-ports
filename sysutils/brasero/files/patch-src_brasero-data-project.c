--- src/brasero-data-project.c.orig	2008-12-14 07:53:07.000000000 -0500
+++ src/brasero-data-project.c	2009-02-27 01:26:42.000000000 -0500
@@ -545,7 +545,7 @@ brasero_data_project_uri_to_nodes (Brase
 		if (graft)
 			break;
 
-		dirname (parent);
+		parent = dirname (parent);
 	}
 
 	if (!graft) {
@@ -721,7 +721,7 @@ brasero_data_project_uri_has_parent (Bra
 			return TRUE;
 		}
 
-		dirname (parent);
+		parent = dirname (parent);
 	}
 
 	g_free (parent);
@@ -795,7 +795,7 @@ brasero_data_project_uri_is_graft_needed
 	 * node is missing. */
 	graft_parent = g_hash_table_lookup (priv->grafts, parent);
 	while (parent && !graft_parent) {
-		dirname (parent);
+		parent = dirname (parent);
 		graft_parent = g_hash_table_lookup (priv->grafts, parent);
 	}
 	g_free (parent);
@@ -2787,7 +2787,7 @@ brasero_data_project_add_excluded_uri (B
 			break;
 
 		graft = NULL;
-		dirname (parent_uri);
+		parent_uri = dirname (parent_uri);
 	}
 	g_free (parent_uri);
 
