--- libobs/graphics/graphics.h.orig	2015-03-27 21:29:37 UTC
+++ libobs/graphics/graphics.h
@@ -426,7 +426,7 @@ struct gs_window {
 	void                    *hwnd;
 #elif defined(__APPLE__)
 	__unsafe_unretained id  view;
-#elif defined(__linux__)
+#elif defined(__linux__) || defined(__FreeBSD__)
 	/* I'm not sure how portable defining id to uint32_t is. */
 	uint32_t id;
 	void* display;
