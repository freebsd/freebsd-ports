--- src/graph2.cc.orig	Fri Oct 25 15:30:29 2002
+++ src/graph2.cc	Fri Oct 25 15:39:39 2002
@@ -248,7 +248,7 @@
 {
 	Graph::e_const_iterator eit;
 	Graph::v_iterator vit;
-	queue<Vertex *> vq;
+	std::queue<Vertex *> vq;
 	int cnt = 1;
 
 	/* Set all marks to 0 */
@@ -379,7 +379,7 @@
 	}
 
 	/* Remove degree 0 vertices */
-	queue<Vertex *> vq;
+	std::queue<Vertex *> vq;
 	int cnt = 0;
 	for (vit = v_begin (); vit != v_end (); ++vit)
 		if ((*vit)->degree () == 0)
@@ -395,7 +395,7 @@
 	/* Remove degree 1 vertices */
 	int tot = 0;
 	do {
-		queue<Vertex *> vq;
+		std::queue<Vertex *> vq;
 		cnt = 0;
 		for (vit = v_begin (); vit != v_end (); ++vit)
 			if ((*vit)->degree () == 1)
