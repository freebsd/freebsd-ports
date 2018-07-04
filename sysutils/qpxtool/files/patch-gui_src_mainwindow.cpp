--- gui/src/mainwindow.cpp.orig	2012-12-03 07:13:07 UTC
+++ gui/src/mainwindow.cpp
@@ -426,7 +426,7 @@ void QPxToolMW::selectTab()
 	int idx;
 	QAction *act = (QAction*) sender();
 	idx = act_sblist.indexOf(act);
-	if (act<0) return;
+	if (idx<0) return;
 	mwidget->selectTab(idx);
 }
 
@@ -1477,7 +1477,7 @@ QString QPxToolMW::generate_html(device *dev, QString 
 		r+= "<br>\n";
 		
 		r+= "<table border=0 cellspacing=0 align=\"center\">\n\t<tr><td align=\"center\">";
-		r+= "<img src=\""+idir+"/rt.png\" alt=\"Read Transfer\" width="HTML_GRAPH_WQ" height="HTML_GRAPH_HQ">";
+		r+= "<img src=\""+idir+"/rt.png\" alt=\"Read Transfer\" width=" HTML_GRAPH_WQ " height=" HTML_GRAPH_HQ ">";
 //		r+= "<br>Read Transfer";
 		r+= "</td></tr>\n</table><br>\n";
 	}
@@ -1508,7 +1508,7 @@ QString QPxToolMW::generate_html(device *dev, QString 
 		r+= "<br>\n";
 
 		r+= "<table border=0 cellspacing=0 align=\"center\">\n\t<tr><td align=\"center\">";
-		r+= "<img src=\""+idir+"/wt.png\" alt=\"Write Transfer\" width="HTML_GRAPH_WQ" height="HTML_GRAPH_HQ">";
+		r+= "<img src=\""+idir+"/wt.png\" alt=\"Write Transfer\" width=" HTML_GRAPH_WQ " height=" HTML_GRAPH_HQ ">";
 //		r+= "<br>Write Transfer";
 		r+= "</td></tr>\n</table><br>\n";
 	}
@@ -1571,7 +1571,7 @@ QString QPxToolMW::generate_html(device *dev, QString 
 		r+= "<br>\n";
 
 		r+= "<table border=0 cellspacing=0 align=\"center\">\n\t<tr><td align=\"center\">";
-		r+= "<img src=\""+idir+"/errc.png\" alt=\"Error correction\" width="HTML_GRAPH_WQ" height="HTML_GRAPH_HQ">\n";
+		r+= "<img src=\""+idir+"/errc.png\" alt=\"Error correction\" width=" HTML_GRAPH_WQ " height=" HTML_GRAPH_HQ ">\n";
 		r+= "<br>Overall ERRC Graph";
 		r+= "</td></tr></table><br>\n";
 
@@ -1580,7 +1580,7 @@ QString QPxToolMW::generate_html(device *dev, QString 
 			for (int i=0; i<8; i++) {
 				if (!dev->media.tdata_errc || (dev->media.tdata_errc & (1<<i))) {
 					r+= "<table border=0 cellspacing=0 align=\"center\">\n\t<tr><td align=\"center\">";
-					r+= "\t<img src=\""+idir+"/"+errcNameCD[i]+".png\" width="HTML_GRAPH_WQ" height="HTML_GRAPH_HQ">";
+					r+= "\t<img src=\""+idir+"/"+errcNameCD[i]+".png\" width=" HTML_GRAPH_WQ " height=" HTML_GRAPH_HQ ">";
 					r+= "<br>"+errcNameCD[i];
 					r+= "</td></tr>\n</table><br>\n";
 				}
@@ -1589,7 +1589,7 @@ QString QPxToolMW::generate_html(device *dev, QString 
 			for (int i=1; i<8; i++) {
 				if (!dev->media.tdata_errc || (dev->media.tdata_errc & (1<<i))) {
 					r+= "<table border=0 cellspacing=0 align=\"center\">\n\t<tr><td align=\"center\">";
-					r+= "\t<img src=\""+idir+"/"+errcNameDVD[i]+".png\" width="HTML_GRAPH_WQ" height="HTML_GRAPH_HQ">";
+					r+= "\t<img src=\""+idir+"/"+errcNameDVD[i]+".png\" width=" HTML_GRAPH_WQ " height=" HTML_GRAPH_HQ ">";
 					r+= "<br>"+errcNameDVD[i];
 					r+= "</td></tr>\n</table><br>\n";
 				}
@@ -1599,7 +1599,7 @@ QString QPxToolMW::generate_html(device *dev, QString 
 			for (int i=0; i<3; i++) {
 				if (!dev->media.tdata_errc || (dev->media.tdata_errc & (1<<residx[i]))) {
 					r+= "<table border=0 cellspacing=0 align=\"center\">\n\t<tr><td align=\"center\">";
-					r+= "\t<img src=\""+idir+"/"+errcNameBD[residx[i]]+".png\" width="HTML_GRAPH_WQ" height="HTML_GRAPH_HQ">";
+					r+= "\t<img src=\""+idir+"/"+errcNameBD[residx[i]]+".png\" width=" HTML_GRAPH_WQ " height=" HTML_GRAPH_HQ ">";
 					r+= "<br>"+errcNameBD[residx[i]];
 					r+= "</td></tr>\n</table><br>\n";
 				}
@@ -1626,7 +1626,7 @@ QString QPxToolMW::generate_html(device *dev, QString 
 		r+= "\t</table>\n";
 		r+= "<br>\n";
 		r+= "<table border=0 cellspacing=0 align=center>\n\t<tr><td align=center>\n";
-		r+= "<img src=\""+idir+"/jb.png\" width="HTML_GRAPH_WQ" height="HTML_GRAPH_HQ">";
+		r+= "<img src=\""+idir+"/jb.png\" width=" HTML_GRAPH_WQ " height=" HTML_GRAPH_HQ ">";
 		r+= "</td></tr>\n</table><br>\n";
 	}
 
@@ -1643,7 +1643,7 @@ QString QPxToolMW::generate_html(device *dev, QString 
 		r+= "\t</table>\n";
 		r+= "<br>\n";
 		r+= "<table border=0 cellspacing=0 align=center>\n\t<tr><td align=center>\n";
-		r+= "<img src=\""+idir+"/ft.png\" width="HTML_GRAPH_WQ" height="HTML_GRAPH_HQ">";
+		r+= "<img src=\""+idir+"/ft.png\" width=" HTML_GRAPH_WQ " height=" HTML_GRAPH_HQ ">";
 		r+= "</td></tr></table><br>\n";
 	}
 
@@ -1663,9 +1663,9 @@ QString QPxToolMW::generate_html(device *dev, QString 
 			for (int z=0; z<3; z++) 
 			{
 				r+= "<table border=0 cellspacing=0 align=center>\n\t<tr><td align=center>";
-				r+= "<img src=\""+idir+"/ta"+QString::number(l)+"_"+QString::number(z)+"_p.png\" width="HTML_GRAPH_WQ" height="HTML_GRAPH_HQ2">";
+				r+= "<img src=\""+idir+"/ta"+QString::number(l)+"_"+QString::number(z)+"_p.png\" width=" HTML_GRAPH_WQ " height=" HTML_GRAPH_HQ2 ">";
 				r+= "</td></tr>\n\t<tr><td align=\"center\">";
-				r+= "<img src=\""+idir+"/ta"+QString::number(l)+"_"+QString::number(z)+"_l.png\" width="HTML_GRAPH_WQ" height="HTML_GRAPH_HQ2">";
+				r+= "<img src=\""+idir+"/ta"+QString::number(l)+"_"+QString::number(z)+"_l.png\" width=" HTML_GRAPH_WQ " height=" HTML_GRAPH_HQ2 ">";
 				r+= "</td></tr>\n</table><br>\n";
 			}
 		}
@@ -1674,7 +1674,7 @@ QString QPxToolMW::generate_html(device *dev, QString 
 	r+= "\t<br><br>\n";
 	r+= "\t\n";
 	r+=	"<p align=\"center\">\n";
-	r+= "\tGenerated by QPxTool v"VERSION" (c) Gennady \"ShultZ\" Kozlov\n";
+	r+= "\tGenerated by QPxTool v" VERSION " (c) Gennady \"ShultZ\" Kozlov\n";
 	r+= "\t<a href=\"http://qpxtool.sourceforge.net\">http://qpxtool.sourceforge.net</a><br>\n";
 	r+= "</p>\n";
 	r+= "</body>\n</html>\n";
