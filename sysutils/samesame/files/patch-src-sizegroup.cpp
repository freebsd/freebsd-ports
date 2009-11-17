--- src/sizegroup.cpp	Sat Nov 14 23:34:59 2009
+++ src/sizegroup.cpp	Mon Nov 16 02:29:51 2009
@@ -36,7 +36,7 @@
 static struct SameGroupBuffer
 {
 	size_t n, size, pagesize;
-	char *buffer;
+	char *buf;
 
 	SameGroupBuffer();
 	~SameGroupBuffer();
@@ -53,12 +53,12 @@
 #else // LOW_MEMORY_PROFILE
 	size = 1 << 24;
 #endif // LOW_MEMORY_PROFILE
-	buffer = new char[size];
+	buf = new char[size];
 }
 
 SameGroupBuffer::~SameGroupBuffer()
 {
-	delete buffer;
+	delete buf;
 }
 
 void SameGroupBuffer::setN(size_t n)
@@ -77,7 +77,7 @@
 			exit(EXIT_FAILURE);
 	}
 #endif // DEBUG
-	return buffer + index * pagesize;
+	return buf + index * pagesize;
 }
 #endif // READ_ONLY_ONCES
 
@@ -136,7 +136,7 @@
 				__FILE__, __LINE__);
 			exit(EXIT_FAILURE);
 		}
-#endif
+#endif // DEBUG
 	for (size_t i = 0; i < n; ++i)
 		hash[i]->sort(compareFilename);
 #ifdef DEBUG
@@ -147,7 +147,7 @@
 				__FILE__, __LINE__);
 			exit(EXIT_FAILURE);
 		}
-#endif
+#endif // DEBUG
 	hash.sort(compare);
 }
 
@@ -188,8 +188,6 @@
 	int (&f)(const SizeGroup &, const FileGroup &, const Filename &, 
 		const FileGroup &, const Filename &, int),
 	size_t fileSize, size_t &nIdenticals, 
-#ifndef READ_ONLY_ONCES
-#endif // READ_ONLY_ONCES
 	int flags, size_t &i, size_t &j, size_t &n,
 	FileGroup &left, FileGroup &right)
 {
@@ -213,7 +211,7 @@
 
 #ifndef READ_ONLY_ONCES
 	// Do a physically check if we couldn't use logic
-	if (!(result))
+	if (!result)
 	{
 		result = left.fcmp(right, fileSize);
 		if (result > 0 && result & FILE_IDENTICAL)
@@ -306,10 +304,6 @@
 	 * If READ_ONLY_ONCES is not defined the code will use less memory.
 	 */
 #ifdef READ_ONLY_ONCES
-	size_t *equal = match.equal;
-	int *fd = match.fd;
-	void **mm = match.mm;
-
 	// Open files
 	buffer.setN(n);
 	for (size_t i = 0; i < n; ++i)
@@ -333,12 +327,15 @@
 			if (preCheck != NULL && preCheck(*this, *hash[i], *hash[j]))
 			{
 				match.set(i, j, FILE_DIFFERENT);
-				++equal[i], ++equal[j];
+				match.increaseEqual(i);
+				match.increaseEqual(j);
 			}
 
 		// Open files
-		if (equal[i] < n -1 && (fd[i] = hash[i]->open(O_RDONLY)) < 0)
+		if (match.getEqual(i) < n -1 &&
+			match.setFd(i, hash[i]->open(O_RDONLY)) < 0)
 			match.set(i, n-1, FILE_OPEN1_ERROR);
+
 	}
 
 	// Compare the files
@@ -350,50 +347,51 @@
 
 		// read pages
 		for (size_t i = 0; i < n; ++i)
-			if (match.get(i, n-1) >= 0 && equal[i] < n - 1)
+			if (match.get(i, n-1) >= 0 && match.getEqual(i) < n - 1)
 				if (USE_MMAP(fileSize))
 				{
-					mm[i] = mmap(0, size, PROT_READ, MAP_SHARED, fd[i], offset);
-					mm[i] = mmap(0, size, PROT_READ, MAP_SHARED, fd[i], offset);
-					if (mm[i] == MAP_FAILED)
+					void *mm = mmap(0, size, PROT_READ, MAP_SHARED, match.getFd(i), offset);
+					match.setMm(i, mm);
+					if (mm == MAP_FAILED)
 						match.set(i, n-1, FILE_READ1_ERROR);
-					posix_madvise(mm[i], size, POSIX_MADV_WILLNEED);
+					posix_madvise(mm, size, POSIX_MADV_WILLNEED);
 				}
-				else if (read(fd[i], buffer[i], size) < 0)
+				else if (read(match.getFd(i), buffer[i], size) < 0)
 					match.set(i, n-1, FILE_READ1_ERROR);
 
 		// compare pages
 		for (size_t i = 0; i < n; ++i)
 		{
-			if (equal[i] == n - 1 || match.get(i, n-1) < 0)
+			if (match.getEqual(i) == n - 1 || match.get(i, n-1) < 0)
 				continue;
 			for (size_t j = i + 1; j < n; ++j)
 				if (match.get(i, j) == FILE_DIFFERENT)
 					continue;
 				else if (memcmp(
-					USE_MMAP(fileSize) ?  mm[i] : buffer[i],
-					USE_MMAP(fileSize) ?  mm[j] : buffer[j],
+					USE_MMAP(fileSize) ?  match.getMm(i) : buffer[i],
+					USE_MMAP(fileSize) ?  match.getMm(j) : buffer[j],
 					size) != 0)
 				{
 					match.set(i, j, FILE_DIFFERENT);
-					++equal[i], ++equal[j];
+					match.increaseEqual(i);
+					match.increaseEqual(j);
 				}
 		}
 
 		// unread?
 		for (size_t i = 0; i < n; ++i)
-			if (mm[i] != NULL)
+			if (match.getMm(i) != NULL)
 			{
-				posix_madvise(mm[i], size, POSIX_MADV_NORMAL);
-				munmap(mm[i], size);
-				mm[i] = NULL;
+				posix_madvise(match.getMm(i), size, POSIX_MADV_NORMAL);
+				munmap(match.getMm(i), size);
+				match.setMm(i, NULL);
 			}
 	}
 
 	// close files
 	for (size_t i = 0; i < n; ++i)
-		if (fd[i] != 0)
-			close(fd[i]);
+		if (!match.getFd(i) != 0)
+			close(match.getFd(i));
 
 	// mark identicals
 	for (size_t i = 0; i < n; ++i)
