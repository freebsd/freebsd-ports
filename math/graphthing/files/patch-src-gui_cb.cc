--- src/gui_cb.cc.orig	Fri Oct 25 15:50:57 2002
+++ src/gui_cb.cc	Fri Oct 25 15:52:46 2002
@@ -253,8 +253,8 @@
 
 void GUI::cb_Graph_Statistics_DegreeSequence ()
 {
-	vector<int> seq;
-	vector<int>::iterator it1, it2;
+	std::vector<int> seq;
+	std::vector<int>::iterator it1, it2;
 	Graph::v_const_iterator vit;
 
 	if (graph->order () < 1) {
