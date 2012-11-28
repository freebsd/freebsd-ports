--- ./src/sphinxstd.cpp.orig	2012-11-28 21:23:23.177922214 +0000
+++ ./src/sphinxstd.cpp	2012-11-28 21:23:34.961920201 +0000
@@ -1,5 +1,5 @@
 //
-// $Id: sphinxstd.cpp 3445 2012-10-12 10:45:41Z kevg $
+// $Id$
 //
 
 //
@@ -737,6 +737,24 @@
 {
 	m_pMutex = NULL;
 
+#ifdef __FreeBSD__
+	CSphString sError, sWarning;
+	if ( !m_pStorage.Alloc ( sizeof(sem_t) + iExtraSize, sError, sWarning ) )
+	{
+		m_sError.SetSprintf ( "storage.alloc, error='%s', warning='%s'", sError.cstr(), sWarning.cstr() );
+		return;
+	}
+
+	m_pMutex = (sem_t*) m_pStorage.GetWritePtr ();
+	int iRes = sem_init ( m_pMutex, 1, 1 );
+	if ( iRes )
+	{
+		m_sError.SetSprintf ( "sem_init, errno=%d ", iRes );
+		m_pMutex = NULL;
+		m_pStorage.Reset ();
+		return;
+	}
+#else
 	pthread_mutexattr_t tAttr;
 	int iRes = pthread_mutexattr_init ( &tAttr );
 	if ( iRes )
@@ -767,6 +785,7 @@
 		m_pStorage.Reset ();
 		return;
 	}
+#endif // __FreeBSD__
 }
 #else
 CSphProcessSharedMutex::CSphProcessSharedMutex ( int )
@@ -777,18 +796,28 @@
 void CSphProcessSharedMutex::Lock () const
 {
 #if !USE_WINDOWS
+#ifdef __FreeBSD__
+	if ( m_pMutex )
+		sem_wait ( m_pMutex );
+#else
 	if ( m_pMutex )
 		pthread_mutex_lock ( m_pMutex );
 #endif
+#endif
 }
 
 
 void CSphProcessSharedMutex::Unlock () const
 {
 #if !USE_WINDOWS
+#ifdef __FreeBSD__
+	if ( m_pMutex )
+		sem_post ( m_pMutex );
+#else
 	if ( m_pMutex )
 		pthread_mutex_unlock ( m_pMutex );
 #endif
+#endif
 }
 
 
@@ -802,6 +831,20 @@
 	if ( !m_pMutex )
 		return false;
 
+#ifdef __FreeBSD__
+	struct timespec tp;
+	clock_gettime ( CLOCK_REALTIME, &tp );
+
+	tp.tv_nsec += tmSpin * 1000;
+	if ( tp.tv_nsec > 1000000 )
+	{
+		int iDelta = (int)( tp.tv_nsec / 1000000 );
+		tp.tv_sec += iDelta * 1000000;
+		tp.tv_nsec -= iDelta * 1000000;
+	}
+
+	return ( sem_timedwait ( m_pMutex, &tp )==0 );
+#else
 #if defined(HAVE_PTHREAD_MUTEX_TIMEDLOCK) && defined(HAVE_CLOCK_GETTIME)
 	struct timespec tp;
 	clock_gettime ( CLOCK_REALTIME, &tp );
@@ -830,6 +873,7 @@
 
 	return iRes==0;
 #endif // HAVE_PTHREAD_MUTEX_TIMEDLOCK && HAVE_CLOCK_GETTIME
+#endif // __FreeBSD__
 #endif // USE_WINDOWS
 }
 
@@ -1338,5 +1382,5 @@
 #endif
 
 //
-// $Id: sphinxstd.cpp 3445 2012-10-12 10:45:41Z kevg $
+// $Id$
 //
