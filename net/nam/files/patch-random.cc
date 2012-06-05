--- random.cc.org	2006-09-27 04:28:19.000000000 +0900
+++ random.cc	2012-06-04 19:23:10.000000000 +0900
@@ -50,8 +50,11 @@
 RANDOM_RETURN_TYPE
 random() GCC_THROW
 {
+	return (long)Random::uniform();
+	/*
 	printf("random() called in nam.\nRandom is not portable, please use Random::uniform() instead.\n");
 	abort();
+	*/
 }
 
 #endif /* !WIN32 */