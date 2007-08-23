Index: src/view.cpp
===================================================================
--- src/view.cpp	(revision 1003)
+++ src/view.cpp	(revision 1004)
@@ -231,6 +231,10 @@
 	std::string date(_("Date: "));
 	date.append(item.pubDate());
 	lines.push_back(date);
+
+	std::string link(_("Link: "));
+	link.append(item.link());
+	lines.push_back(link);
 	
 	lines.push_back(std::string(""));
 	
