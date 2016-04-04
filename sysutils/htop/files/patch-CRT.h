--- CRT.h.orig	2016-03-07 21:32:06 UTC
+++ CRT.h
@@ -115,7 +115,7 @@ void CRT_fatalError(const char* note) __
 
 void CRT_handleSIGSEGV(int sgn);
 
-#define KEY_ALT(x) KEY_F(60) + (x - 'A')
+#define KEY_ALT(x) (KEY_F(64 - 26) + (x - 'A'))
 
 
 extern const char *CRT_treeStrAscii[TREE_STR_COUNT];
