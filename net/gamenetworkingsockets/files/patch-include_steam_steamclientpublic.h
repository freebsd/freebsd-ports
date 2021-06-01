--- include/steam/steamclientpublic.h.orig	2021-05-31 13:43:13 UTC
+++ include/steam/steamclientpublic.h
@@ -1257,7 +1257,7 @@ typedef void *BREAKPAD_HANDLE;
 	#define VALVE_CALLBACK_PACK_LARGE
 #else
 
-	#if defined(__linux__) || defined(__APPLE__) 
+	#if defined(__linux__) || defined(__APPLE__)  || defined(__FreeBSD__)
 	// The 32-bit version of gcc has the alignment requirement for uint64 and double set to
 	// 4 meaning that even with #pragma pack(8) these types will only be four-byte aligned.
 	// The 64-bit version of gcc has the alignment requirement for these types set to
