--- libjcore/code/jNew.h.orig	Fri Sep 20 13:49:44 2002
+++ libjcore/code/jNew.h	Fri Sep 20 13:50:41 2002
@@ -26,7 +26,7 @@
 	#ifdef __KCC
 	void* operator new(size_t size) MSIPL_THROW_STR(std::bad_alloc);
 	#else
-	void* operator new(size_t size);
+	// void* operator new(size_t size);
 	#endif
 
 	void* operator new(size_t size, const JCharacter* file, const JUInt32 line);
@@ -34,13 +34,13 @@
 	#ifdef __KCC
 	void* operator new[](size_t size) MSIPL_THROW_STR(std::bad_alloc);
 	#else
-	void* operator new[](size_t size);
+	//void* operator new[](size_t size);
 	#endif
 
 	void* operator new[](size_t size, const JCharacter* file, const JUInt32 line);
 
-	void operator delete(void* memory);
-	void operator delete[](void* memory);
+	//void operator delete(void* memory);
+	//void operator delete[](void* memory);
 
 	void LocateDelete(const JCharacter* file, const JUInt32 line);
 
