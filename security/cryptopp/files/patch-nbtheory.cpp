--- nbtheory.cpp.orig	2013-05-22 00:16:26.761193859 +0000
+++ nbtheory.cpp	2013-05-22 00:15:29.401256454 +0000
@@ -307,7 +307,18 @@
 
 bool PrimeSieve::NextCandidate(Integer &c)
 {
+#if defined(__clang__) && defined(_LIBCPP_VERSION) &&  _LIBCPP_VERSION < 1101
+	// Workaround for a bug in libc++ in std::find on std::vector<bool>
+	std::vector<bool>::iterator pos = m_sieve.begin()+m_next;
+	for (std::vector<bool>::iterator end = m_sieve.end(); pos != end; ++pos)
+	{
+		if (*pos == false)
+			break;
+	}
+	bool safe = SafeConvert(pos - m_sieve.begin(), m_next);
+#else
 	bool safe = SafeConvert(std::find(m_sieve.begin()+m_next, m_sieve.end(), false) - m_sieve.begin(), m_next);
+#endif
 	assert(safe);
 	if (m_next == m_sieve.size())
 	{
