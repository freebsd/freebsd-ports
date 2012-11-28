--- ./src/sphinxstd.h.orig	2012-11-28 21:23:17.008920478 +0000
+++ ./src/sphinxstd.h	2012-11-28 21:23:38.979912416 +0000
@@ -1,5 +1,5 @@
 //
-// $Id: sphinxstd.h 3461 2012-10-19 09:48:07Z kevg $
+// $Id$
 //
 
 //
@@ -62,6 +62,9 @@
 #include <sys/mman.h>
 #include <errno.h>
 #include <pthread.h>
+#ifdef __FreeBSD__
+#include <semaphore.h>
+#endif
 #endif
 
 /////////////////////////////////////////////////////////////////////////////
@@ -2032,7 +2035,11 @@
 protected:
 #if !USE_WINDOWS
 	CSphSharedBuffer<BYTE>		m_pStorage;
+#ifdef __FreeBSD__
+	sem_t *						m_pMutex;
+#else
 	pthread_mutex_t *			m_pMutex;
+#endif
 	CSphString					m_sError;
 #endif
 };
@@ -2050,7 +2057,11 @@
 	{
 		if ( m_pMutex )
 		{
+#ifdef __FreeBSD__
+			m_pValue = reinterpret_cast<T*> ( m_pStorage.GetWritePtr () + sizeof ( sem_t ) );
+#else
 			m_pValue = reinterpret_cast<T*> ( m_pStorage.GetWritePtr () + sizeof ( pthread_mutex_t ) );
+#endif
 			*m_pValue = tInitValue;
 		}
 	}
@@ -2478,5 +2489,5 @@
 #endif // _sphinxstd_
 
 //
-// $Id: sphinxstd.h 3461 2012-10-19 09:48:07Z kevg $
+// $Id$
 //
