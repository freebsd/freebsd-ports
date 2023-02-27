--- simplerw.c.orig	2023-02-26 14:01:13 UTC
+++ simplerw.c
@@ -134,7 +134,7 @@ int read_graph(const char *format, const char * filena
 		igraph_destroy(&igraph);
 		return(-1);
 	}
-	igraph_get_adjacency(&igraph, &imatrix, IGRAPH_GET_ADJACENCY_BOTH, 0);
+	igraph_get_adjacency(&igraph, &imatrix, IGRAPH_GET_ADJACENCY_BOTH, NULL, IGRAPH_LOOPS_ONCE);
 	igraph_destroy(&igraph);
 	if(igraph_matrix_nrow(&imatrix) > MAX_VERTICES)
 	{
