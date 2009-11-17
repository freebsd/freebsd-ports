--- src/matchmatrix.h	Fri Nov 13 18:44:01 2009
+++ src/matchmatrix.h	Mon Nov 16 02:30:30 2009
@@ -28,12 +28,11 @@
 {
 	size_t n;
 	signed char **arr;
-
-public:  
 	size_t *equal;
 	int *fd;
 	void **mm;
-  
+
+public:  
 	/**
 	 * Creates a MatchMatrix that is able to store the match results of
 	 * n elements.
@@ -46,12 +45,41 @@
 	int get(size_t i, size_t j) const throw()
 	{ return arr[i][j - i]; }
 
+	size_t getEqual(size_t i) const throw()
+	{ return equal[i]; }
+
+	int getFd(size_t i) const throw()
+	{ return fd[i]; }
+
+	void *getMm(size_t i) const throw()
+	{ return mm[i]; }
+
+	void increaseEqual(size_t i) const throw()
+	{ ++equal[i]; }
+
 	void set(size_t i, size_t j, int result) throw()
 	{ arr[i][j - i] = result; }
 
+	void setEqual(size_t i, size_t x) throw()
+	{ equal[i] = x; }
+
+	int setFd(size_t i, int x) throw()
+	{ return fd[i] = x; }
+
+	void setMm(size_t i, void *x) throw()
+	{ mm[i] = x; }
 #else // DEBUG
 	int get(size_t i, size_t j) const throw();
+	size_t getEqual(size_t i) const throw();
+	int getFd(size_t i) const throw();
+	void *getMm(size_t i) const throw();
+
+	void increaseEqual(size_t i) const throw();
+
 	void set(size_t i, size_t j, int result) throw();
+	void setEqual(size_t i, size_t x) throw();
+	int setFd(size_t i, int x) throw();
+	void setMm(size_t i, void *x) throw();
 #endif // DEBUG
 
 	/**
