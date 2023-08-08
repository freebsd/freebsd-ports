--- OpenSP.xs.orig	2023-07-04 14:18:21 UTC
+++ OpenSP.xs
@@ -162,7 +162,7 @@ SV* SgmlParserOpenSP::cs2sv(const SGMLApplication::Cha
     {
         d = m_temp;
         for (i = 0; i < s.len; ++i)
-            d = uvuni_to_utf8_flags(d, s.ptr[i], 0);
+            d = uvchr_to_utf8_flags(d, s.ptr[i], 0);
         result = newSVpvn((const char*)m_temp, d - m_temp);
     }
     else
@@ -171,7 +171,7 @@ SV* SgmlParserOpenSP::cs2sv(const SGMLApplication::Cha
         for (i = 0; i < s.len; ++i)
         {
             d = (U8 *)SvGROW(result, SvCUR(result) + UTF8_MAXLEN + 1);
-            d = uvuni_to_utf8_flags(d + SvCUR(result), s.ptr[i], 0); 
+            d = uvchr_to_utf8_flags(d + SvCUR(result), s.ptr[i], 0); 
             SvCUR_set(result, d - (U8 *)SvPVX(result));
         }
     }
