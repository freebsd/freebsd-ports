--- src/skin.h.orig	Tue Sep 23 21:53:47 2003
+++ src/skin.h	Tue Jan 18 02:21:27 2005
@@ -8,8 +8,8 @@
 {
 public:
 	GdkCursor *cursor;
-	_Skin_cursor::_Skin_cursor();
-	_Skin_cursor::~_Skin_cursor();
+	_Skin_cursor();
+	~_Skin_cursor();
 };
 
 struct _Skin_pixbuf_1
