--- src/post/goom/mmx.h.orig
+++ src/post/goom/mmx.h
@@ -721,17 +721,29 @@ void zoom_filter_xmmx (int prevX, int pr
 */
 #ifdef	MMX_TRACE
 
+#ifdef __clang__
+#define	emms() \
+	{ \
+		printf("emms()\n"); \
+		__asm__ __volatile__ ("emms"); \
+	}
+#else
 #define	emms() \
 	{ \
 		printf("emms()\n"); \
 		__asm__ __volatile__ ("emms" \
                         "st(1)","st(2)","st(3)","st(4)","st(5)","st(6)","st(7)"); \
 	}
+#endif
 
 #else
 
+#ifdef __clang__
+#define	emms() __asm__ __volatile__ ("emms")
+#else
 #define	emms() __asm__ __volatile__ ("emms"::: \
                       "st(1)","st(2)","st(3)","st(4)","st(5)","st(6)","st(7)")
+#endif
 
 #endif
 
