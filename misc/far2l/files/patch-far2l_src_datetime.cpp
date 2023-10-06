--- far2l/src/datetime.cpp.orig	2023-10-06 15:57:46 UTC
+++ far2l/src/datetime.cpp
@@ -531,15 +531,27 @@ int64_t FileTimeDifference(const FILETIME *a, const FI
 {
 	LARGE_INTEGER A =
 						{
+#if defined(__BYTE_ORDER__) && (__BYTE_ORDER__ == __ORDER_BIG_ENDIAN__)
+								{(LONG)a->dwHighDateTime, a->dwLowDateTime}
+#else
 								{a->dwLowDateTime, (LONG)a->dwHighDateTime}
+#endif
     },
+#if defined(__BYTE_ORDER__) && (__BYTE_ORDER__ == __ORDER_BIG_ENDIAN__)
+				B = {{(LONG)b->dwHighDateTime, b->dwLowDateTime}};
+#else
 				B = {{b->dwLowDateTime, (LONG)b->dwHighDateTime}};
+#endif
 	return A.QuadPart - B.QuadPart;
 }
 
 uint64_t FileTimeToUI64(const FILETIME *ft)
 {
+#if defined(__BYTE_ORDER__) && (__BYTE_ORDER__ == __ORDER_BIG_ENDIAN__)
+	ULARGE_INTEGER A = { {ft->dwHighDateTime, ft->dwLowDateTime} };
+#else
 	ULARGE_INTEGER A = { {ft->dwLowDateTime, ft->dwHighDateTime} };
+#endif
 	return A.QuadPart;
 }
 
@@ -761,7 +773,11 @@ void ConvertRelativeDate(const FILETIME &ft, FARString
 
 void ConvertRelativeDate(const FILETIME &ft, FARString &strDaysText, FARString &strTimeText)
 {
+#if defined(__BYTE_ORDER__) && (__BYTE_ORDER__ == __ORDER_BIG_ENDIAN__)
+	ULARGE_INTEGER time = { {ft.dwHighDateTime, ft.dwLowDateTime}};
+#else
 	ULARGE_INTEGER time = { {ft.dwLowDateTime, ft.dwHighDateTime}};
+#endif
 
 	UINT64 ms = (time.QuadPart/= 10000) % 1000;
 	UINT64 s = (time.QuadPart/= 1000) % 60;
