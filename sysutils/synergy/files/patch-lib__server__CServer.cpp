--- ./lib/server/CServer.cpp.orig	2006-04-02 03:47:04.000000000 +0200
+++ ./lib/server/CServer.cpp	2007-07-24 16:59:59.000000000 +0200
@@ -434,16 +434,23 @@
 				SInt32 x, SInt32 y, bool forScreensaver)
 {
 	assert(dst != NULL);
+	assert(m_active != NULL);
+
+	LOG((CLOG_INFO "switch from \"%s\" to \"%s\" at %d,%d", getName(m_active).c_str(), getName(dst).c_str(), x, y));
+
 #ifndef NDEBUG
 	{
 		SInt32 dx, dy, dw, dh;
 		dst->getShape(dx, dy, dw, dh);
-		assert(x >= dx && y >= dy && x < dx + dw && y < dy + dh);
+
+		if(!(x >= dx && y >= dy && x < dx + dw && y < dy + dh)) {
+			LOG((CLOG_ERR "debug check failed"));
+			LOG((CLOG_ERR "x=%d dx=%d dw=%d", x, dx, dw));
+			LOG((CLOG_ERR "y=%d dy=%d dh=%d", y, dy, dh));
+			assert(0);
+		}
 	}
 #endif
-	assert(m_active != NULL);
-
-	LOG((CLOG_INFO "switch from \"%s\" to \"%s\" at %d,%d", getName(m_active).c_str(), getName(dst).c_str(), x, y));
 
 	// stop waiting to switch
 	stopSwitch();
