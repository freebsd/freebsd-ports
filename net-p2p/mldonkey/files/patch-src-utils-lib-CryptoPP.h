--- src/utils/lib/CryptoPP.h.orig
+++ src/utils/lib/CryptoPP.h
@@ -274,7 +274,7 @@
 // CodeWarrior defines _MSC_VER
 #if !defined(CRYPTOPP_DISABLE_X86ASM) && ((defined(_MSC_VER) && !defined(__MWERKS__) && defined(_M_IX86)) || (defined(__GNUC__) && defined(__i386__)))
 	// The x86 version of MacOSX fails when asm is enabled.
-	#if !defined(__i386__) || !defined(__APPLE__)
+	#if !defined(__APPLE__) && !defined(__clang__)
 		#define CRYPTOPP_X86ASM_AVAILABLE
 	#endif
 #endif
