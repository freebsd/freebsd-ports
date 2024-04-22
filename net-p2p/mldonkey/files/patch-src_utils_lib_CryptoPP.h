src/utils/lib/CryptoPP.h:3941:26: error: ISO C++11 does not allow access declarations; use using declarations instead
        BufferedTransformation::Get;
                                ^

--- src/utils/lib/CryptoPP.h.orig	2020-07-06 02:50:39 UTC
+++ src/utils/lib/CryptoPP.h
@@ -86,6 +86,7 @@
 #define CRYPTOPP_H
 
 #include <inttypes.h>
+#define CAML_NAME_SPACE
 #include <caml/config.h>
 #include <stdio.h>
 
@@ -3938,15 +3939,15 @@ class CRYPTOPP_DLL CRYPTOPP_NO_VTABLE Sink : public Bu
 {
 protected:
 	// make these functions protected to help prevent unintentional calls to them
-	BufferedTransformation::Get;
-	BufferedTransformation::Peek;
-	BufferedTransformation::TransferTo;
-	BufferedTransformation::CopyTo;
-	BufferedTransformation::CopyRangeTo;
-	BufferedTransformation::TransferMessagesTo;
-	BufferedTransformation::CopyMessagesTo;
-	BufferedTransformation::TransferAllTo;
-	BufferedTransformation::CopyAllTo;
+	using BufferedTransformation::Get;
+	using BufferedTransformation::Peek;
+	using BufferedTransformation::TransferTo;
+	using BufferedTransformation::CopyTo;
+	using BufferedTransformation::CopyRangeTo;
+	using BufferedTransformation::TransferMessagesTo;
+	using BufferedTransformation::CopyMessagesTo;
+	using BufferedTransformation::TransferAllTo;
+	using BufferedTransformation::CopyAllTo;
 	unsigned int TransferTo2(BufferedTransformation& /* target */, unsigned long &transferBytes, const std::string& /* channel */ = NULL_CHANNEL, bool /* blocking */ = true)
 		{transferBytes = 0; return 0;}
 	unsigned int CopyRangeTo2(BufferedTransformation& /* target */, unsigned long& /* begin */, unsigned long /* end */ = ULONG_MAX, const std::string& /* channel */ = NULL_CHANNEL, bool /* blocking */ = true) const
