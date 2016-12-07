This fixes a warning triggered by testing an unsigned parameter
against 0.  The patch solves this by creating a different template
for signed case. (PR: 178827)

--- misc.h.orig	2016-10-10 23:49:54 UTC
+++ misc.h
@@ -529,8 +529,10 @@ inline bool SafeConvert(T1 from, T2 &to)
 //! \param value the value to convert
 //! \param base the base to use during the conversion
 //! \returns the string representation of value in base.
+template<bool> struct IsUnsigned {};
+
 template <class T>
-std::string IntToString(T value, unsigned int base = 10)
+std::string IntToStringImpl(T value, unsigned int base, IsUnsigned<true>)
 {
 	// Hack... set the high bit for uppercase.
 	static const unsigned int HIGH_BIT = (1U << 31);
@@ -541,12 +543,6 @@ std::string IntToString(T value, unsigne
 	if (value == 0)
 		return "0";
 
-	bool negate = false;
-	if (value < 0)
-	{
-		negate = true;
-		value = 0-value;	// VC .NET does not like -a
-	}
 	std::string result;
 	while (value > 0)
 	{
@@ -554,11 +550,30 @@ std::string IntToString(T value, unsigne
 		result = char((digit < 10 ? '0' : (CH - 10)) + digit) + result;
 		value /= base;
 	}
+	return result;
+}
+
+template <class T>
+std::string IntToStringImpl(T value, unsigned int base, IsUnsigned<false>)
+{
+	bool negate = false;
+	if (value < 0)
+	{
+		negate = true;
+		value = 0-value;	// VC .NET does not like -a
+	}
+	std::string result = IntToStringImpl(value, base, IsUnsigned<true>());
 	if (negate)
 		result = "-" + result;
 	return result;
 }
 
+template <class T>
+std::string IntToString(T value, unsigned int base = 10)
+{
+	return IntToStringImpl(value, base, IsUnsigned<(static_cast<T>(-1) > 0)>());
+}
+
 //! \brief Converts an unsigned value to a string
 //! \param value the value to convert
 //! \param base the base to use during the conversion
