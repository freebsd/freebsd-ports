--- ./lib/server/CClientProxy1_0.cpp.orig	2006-04-02 03:47:03.000000000 +0200
+++ ./lib/server/CClientProxy1_0.cpp	2007-07-24 16:59:59.000000000 +0200
@@ -401,7 +401,7 @@
 							&x, &y, &w, &h, &dummy1, &mx, &my)) {
 		return false;
 	}
-	LOG((CLOG_DEBUG "received client \"%s\" info shape=%d,%d %dx%d", getName().c_str(), x, y, w, h));
+	LOG((CLOG_DEBUG "received client \"%s\" info shape=%d,%d %dx%d mouse=%d,%d", getName().c_str(), x, y, w, h, mx, my));
 
 	// validate
 	if (w <= 0 || h <= 0) {
@@ -413,8 +413,14 @@
 	m_info.m_y  = y;
 	m_info.m_w  = w;
 	m_info.m_h  = h;
-	m_info.m_mx = mx;
-	m_info.m_my = my;
+	
+	if(mx >= x && mx < x+w && my >= y && my < y+h) {
+		m_info.m_mx = mx;
+		m_info.m_my = my;
+	} else {
+		m_info.m_mx = x + w/2;
+		m_info.m_my = y + h/2;
+	}
 
 	// acknowledge receipt
 	LOG((CLOG_DEBUG1 "send info ack to \"%s\"", getName().c_str()));
