--- src/post/goom/mmx.h.orig
+++ src/post/goom/mmx.h
@@ -725,13 +725,13 @@ void zoom_filter_xmmx (int prevX, int pr
 	{ \
 		printf("emms()\n"); \
 		__asm__ __volatile__ ("emms" \
-                        "st(1)","st(2)","st(3)","st(4)","st(5)","st(6)","st(7)"); \
+                        "st","st(1)","st(2)","st(3)","st(4)","st(5)","st(6)","st(7)"); \
 	}
 
 #else
 
 #define	emms() __asm__ __volatile__ ("emms"::: \
-                      "st(1)","st(2)","st(3)","st(4)","st(5)","st(6)","st(7)")
+                      "st","st(1)","st(2)","st(3)","st(4)","st(5)","st(6)","st(7)")
 
 #endif
 
