--- src/matchmatrix.cpp	Sat Nov 14 04:27:23 2009
+++ src/matchmatrix.cpp	Mon Nov 16 02:34:10 2009
@@ -98,6 +98,50 @@
 	return arr[i][j - i];
 }
 
+size_t MatchMatrix::getEqual(size_t i) const throw() 
+{
+	if (i > n)
+	{
+		fprintf(stderr, "%s:%u i (%u) must be smaller then %u\n",
+			__FILE__, __LINE__, i, n);
+		exit(EXIT_FAILURE);
+	}
+	return equal[i];
+}
+
+int MatchMatrix::getFd(size_t i) const throw()
+{
+	if (i > n)
+	{
+		fprintf(stderr, "%s:%u i (%u) must be smaller then %u\n",
+			__FILE__, __LINE__, i, n);
+		exit(EXIT_FAILURE);
+	}
+	return fd[i];
+}
+
+void *MatchMatrix::getMm(size_t i) const throw()
+{
+	if (i > n)
+	{
+		fprintf(stderr, "%s:%u i (%u) must be smaller then %u\n",
+			__FILE__, __LINE__, i, n);
+		exit(EXIT_FAILURE);
+	}
+	return mm[i];
+}
+
+void MatchMatrix::increaseEqual(size_t i) const throw()  
+{
+	if (i > n)
+	{
+		fprintf(stderr, "%s:%u i (%u) must be smaller then %u\n",
+			__FILE__, __LINE__, i, n);
+		exit(EXIT_FAILURE);
+	}
+	++equal[i];
+}
+
 void MatchMatrix::set(size_t i, size_t j, int result) throw()
 {
 	if (i > n)
@@ -114,6 +158,40 @@
 	}
 	arr[i][j - i] = result;
 }
+
+void MatchMatrix::setEqual(size_t i, size_t x) throw()
+{
+	if (i > n)
+	{
+		fprintf(stderr, "%s:%u i (%u) must be smaller then %u\n",
+			__FILE__, __LINE__, i, n);
+		exit(EXIT_FAILURE);
+	}
+	equal[i] = x;
+}
+
+int MatchMatrix::setFd(size_t i, int x) throw()
+{
+	if (i > n)
+	{
+		fprintf(stderr, "%s:%u i (%u) must be smaller then %u\n",
+			__FILE__, __LINE__, i, n);
+		exit(EXIT_FAILURE);
+	}
+	return fd[i] = x;
+}
+
+void MatchMatrix::setMm(size_t i, void *x) throw()
+{
+	if (i > n)
+	{
+		fprintf(stderr, "%s:%u i (%u) must be smaller then %u\n",
+			__FILE__, __LINE__, i, n);
+		exit(EXIT_FAILURE);
+	}
+	mm[i] = x;
+}
+
 #endif // DEBUG
 
 void MatchMatrix::reset(size_t n) throw()
