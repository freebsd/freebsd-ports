--- matchmatrix.cpp.orig	2009-05-22 12:45:27.000000000 +0200
+++ matchmatrix.cpp	2009-06-30 22:24:35.000000000 +0200
@@ -35,6 +35,7 @@
 	arr[0] = ((signed char *)tmp) + n * sizeof(char **);
 	for (size_t i = 1; i < n; ++i)
 		arr[i] = arr[i - 1] + n - i + 1;
+	memset(arr[0], 0, (n + 1) * n / 2);
 #ifdef DEBUG
 	if (tmp + n * sizeof(char **) + (n + 1) * n / 2 <= arr[n - 1])
 	{
