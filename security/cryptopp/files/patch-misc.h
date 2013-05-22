--- misc.h.orig	2010-08-06 18:46:18.000000000 +0000
+++ misc.h	2013-05-22 08:43:01.949194748 +0000
@@ -405,17 +405,13 @@
 	return order == GetNativeByteOrder();
 }
 
+template<bool> struct IsUnsigned {};
+
 template <class T>
-std::string IntToString(T a, unsigned int base = 10)
+std::string IntToStringImpl(T a, unsigned int base, IsUnsigned<true>)
 {
 	if (a == 0)
 		return "0";
-	bool negate = false;
-	if (a < 0)
-	{
-		negate = true;
-		a = 0-a;	// VC .NET does not like -a
-	}
 	std::string result;
 	while (a > 0)
 	{
@@ -423,11 +419,30 @@
 		result = char((digit < 10 ? '0' : ('a' - 10)) + digit) + result;
 		a /= base;
 	}
+	return result;
+}
+
+template <class T>
+std::string IntToStringImpl(T a, unsigned int base, IsUnsigned<false>)
+{
+	bool negate = false;
+	if (a < 0)
+	{
+		negate = true;
+		a = 0-a;	// VC .NET does not like -a
+	}
+	std::string result = IntToStringImpl(a, base, IsUnsigned<true>());
 	if (negate)
 		result = "-" + result;
 	return result;
 }
 
+template <class T>
+std::string IntToString(T a, unsigned int base = 10)
+{
+	return IntToStringImpl(a, base, IsUnsigned<(static_cast<T>(-1) > 0)>());
+}
+
 template <class T1, class T2>
 inline T1 SaturatingSubtract(const T1 &a, const T2 &b)
 {
