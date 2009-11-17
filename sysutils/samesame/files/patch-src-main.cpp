--- src/main.cpp	Sun Nov 15 00:06:17 2009
+++ src/main.cpp	Mon Nov 16 14:09:26 2009
@@ -375,8 +375,12 @@
 	size_t oldMinSize = minSize;
 	Holder holder;
 
-	// Reserve 1M memory for later (better memory management)
-	char *dummy = new char[1048576];
+	// Reserve memory for later (better memory management)
+#ifdef LOW_MEMORY_PROFILE
+	char *dummy = new char[1048576]; // 1 MB
+#else // LOW_MEMORY_PROFILE
+	char *dummy = new char[5 * 1048576]; // 5 MB
+#endif // LOW_MEMORY_PROFILE
 
 	// Stage1 - reading the input
 	if (S_VERBOSE_LEVEL2(flags))
