--- src/icqface.cc.orig	Wed Aug  9 10:43:40 2006
+++ src/icqface.cc	Wed Aug  9 10:44:14 2006
@@ -2003,7 +2003,7 @@
 	    mvaddchnstr(i-1, sizeWArea.x1+1, logline, sizeWArea.x2-sizeWArea.x1);
 	}
 
-	delete logline;
+	delete[] logline;
 
 	if(text.size() > sizeWArea.x2-sizeWArea.x1-2) text.resize(sizeWArea.x2-sizeWArea.x1-2);
 	mvhline(LINES-3, sizeWArea.x1+2, ' ', sizeWArea.x2-sizeWArea.x1-2);
