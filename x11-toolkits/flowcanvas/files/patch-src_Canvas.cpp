--- src/Canvas.cpp.orig	2011-01-10 00:19:58.000000000 +0100
+++ src/Canvas.cpp	2013-03-16 13:45:17.797462753 +0100
@@ -1253,21 +1253,21 @@
 	 */
 
 	GVC_t* gvc = gvContext();
-	Agraph_t* G = agopen((char*)"g", AGDIGRAPH);
+	Agraph_t* G = agopen((char*)"g", Agdirected, NULL);
 
 	nodes.gvc = gvc;
 	nodes.G = G;
 
 	if (_direction == HORIZONTAL)
-		agraphattr(G, (char*)"rankdir", (char*)"LR");
+		agattr(G, AGRAPH, (char*)"rankdir", (char*)"LR");
 	else
-		agraphattr(G, (char*)"rankdir", (char*)"TD");
+		agattr(G, AGRAPH, (char*)"rankdir", (char*)"TD");
 
 	unsigned id = 0;
 	for (ItemList::const_iterator i = _items.begin(); i != _items.end(); ++i) {
 		std::ostringstream ss;
 		ss << "n" << id++;
-		Agnode_t* node = agnode(G, strdup(ss.str().c_str()));
+		Agnode_t* node = agnode(G, strdup(ss.str().c_str()), true);
 		if (boost::dynamic_pointer_cast<Module>(*i)) {
 			ss.str("");
 			ss << (*i)->width() / 96.0;
@@ -1310,7 +1310,7 @@
 
 		assert(src_node && dst_node);
 
-		Agedge_t* edge = agedge(G, src_node, dst_node);
+		Agedge_t* edge = agedge(G, src_node, dst_node, NULL, true);
 
 		if (use_length_hints && c->length_hint() != 0) {
 			std::ostringstream len_ss;
@@ -1325,7 +1325,7 @@
 		if (partner) {
 			GVNodes::iterator p = nodes.find(partner);
 			if (p != nodes.end())
-				agedge(G, i->second, p->second);
+				agedge(G, i->second, p->second, NULL, true);
 		}
 	}
 
