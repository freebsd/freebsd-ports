--- src/VISmoveImage.s.orig	2008-08-15 19:49:00.000000000 +0000
+++ src/VISmoveImage.s	2009-03-29 14:08:42.000000000 +0000
@@ -779,7 +779,11 @@
 	 sub			%tmp3, %rightw, %curw
 
 return: return			%i7+8
+#if defined(__FreeBSD__)
+	 nop
+#else
 	 wr			%g0, 0, %fprs
+#endif
 
 narrowst:
 	and			%leftw, 0x38, %tmp1
@@ -2174,7 +2178,11 @@
 	 sub			%curw, %rightw, %curw
 
 rreturn:return			%i7+8
+#if defined(__FreeBSD__)
+	 nop
+#else
 	 wr			%g0, 0, %fprs
+#endif
 
 narrowstr:
 	cmp			%rightw, 64
