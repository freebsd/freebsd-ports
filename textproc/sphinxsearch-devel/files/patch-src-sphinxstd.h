--- src/sphinxstd.h~	2011-04-01 16:50:14.000000000 +0000
+++ src/sphinxstd.h	2011-06-15 09:22:46.000000000 +0000
@@ -1922,6 +1922,8 @@
 	T ReadValue() const
 	{
 		assert ( m_pValue );
+		if (!m_pValue)
+			return 0;
 		Lock();
 		T val = *m_pValue;
 		Unlock();
@@ -1930,6 +1932,8 @@
 	void WriteValue ( const T& tNewValue )
 	{
 		assert ( m_pValue );
+		if (!m_pValue)
+			return;
 		Lock();
 		*m_pValue = tNewValue;
 		Unlock();
