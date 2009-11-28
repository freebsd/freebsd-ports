--- JavaScriptCore/yarr/RegexJIT.h.orig	2009-10-09 23:47:41.000000000 -0400
+++ JavaScriptCore/yarr/RegexJIT.h	2009-10-09 23:48:19.000000000 -0400
@@ -73,7 +73,7 @@ public:
 
     int execute(const UChar* input, unsigned start, unsigned length, int* output)
     {
-        return reinterpret_cast<RegexJITCode>(m_ref.m_code.executableAddress())(input, start, length, output);
+        return ((RegexJITCode)m_ref.m_code.executableAddress())(input, start, length, output);
     }
 
 private:
