
$FreeBSD$

--- src/icqface.cc.orig
+++ src/icqface.cc
@@ -401,7 +401,7 @@
 
     m.scale();
     m.idle = &menuidle;
-    i = (int) m.getref(m.open()-1);
+    i = (intptr_t) m.getref(m.open()-1);
     m.close();
 
     if(i) lastr = i;
@@ -450,7 +450,7 @@
 
     if(i) {
 	lastitem = i-1;
-	r = (int) m.getref(lastitem);
+	r = (intptr_t) m.getref(lastitem);
     }
 
     return r;
@@ -513,7 +513,7 @@
 	    g = 0;
 	}
 	
-	if((unsigned int) c < 100) c = 0;
+	if((intptr_t) c < 100) c = 0;
 
 	if(i) {
 	    switch(action = extk) {
@@ -1484,7 +1484,7 @@
 	m.scale();
 
 	i = m.open();
-	choice = (int) m.getref(i-1);
+	choice = (intptr_t) m.getref(i-1);
 
 	m.close();
     }
@@ -1539,7 +1539,7 @@
 	m.close();
 
 	if(r = i) {
-	    st = (imstatus) ((int) m.getref(i-1));
+	    st = (imstatus) ((intptr_t) m.getref(i-1));
 	}
     }
 
@@ -2003,7 +2003,7 @@
 	    mvaddchnstr(i-1, sizeWArea.x1+1, logline, sizeWArea.x2-sizeWArea.x1);
 	}
 
-	delete logline;
+	delete[] logline;
 
 	if(text.size() > sizeWArea.x2-sizeWArea.x1-2) text.resize(sizeWArea.x2-sizeWArea.x1-2);
 	mvhline(LINES-3, sizeWArea.x1+2, ' ', sizeWArea.x2-sizeWArea.x1-2);
@@ -2132,7 +2132,7 @@
 			    c = (icqcontact *) cm->getref(i);
 			}
 
-			if((unsigned int) c > 100) {
+			if((intptr_t) c > 100) {
 			    string current = c->getdispnick();
 			    len = current.size();
 			    if(len > nick.size()) len = nick.size();
