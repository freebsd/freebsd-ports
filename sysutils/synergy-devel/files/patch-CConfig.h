--- src/lib/server/CConfig.h.orig	2013-09-12 16:03:30.000000000 +0800
+++ src/lib/server/CConfig.h	2013-09-12 16:04:07.000000000 +0800
@@ -483,7 +483,7 @@
 	bool			readLine(CString&);
 	UInt32			getLineNumber() const;
 
-	operator void*() const;
+	operator bool() const;
 	bool			operator!() const;
 
 	OptionValue		parseBoolean(const CString&) const;
