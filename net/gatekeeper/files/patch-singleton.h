--- singleton.h.orig	Thu Oct  7 19:42:31 2004
+++ singleton.h	Thu Oct  7 19:42:49 2004
@@ -87,12 +87,7 @@
 	Singleton();
 	~Singleton();
 
-#ifdef WIN32
   public:
-#else
-  private:
-	friend T *InstanceOf<T>();
-#endif
 	static SingletonBase *m_Instance;
 	static PMutex m_CreationLock;
 };
