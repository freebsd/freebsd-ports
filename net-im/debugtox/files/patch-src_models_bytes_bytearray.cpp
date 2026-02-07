Fix build with Qt >= 6.9.0

https://github.com/TokTok/debugtox/pull/23

--- src/models/bytes/bytearray.cpp.orig	2025-02-08 00:20:16 UTC
+++ src/models/bytes/bytearray.cpp
@@ -14,7 +14,8 @@ QString ByteArray::toString() const
         if (c.isPrint() || c.isSpace()) {
             result += c;
         } else {
-            result += QStringLiteral("\\x%1").arg(c.unicode(), 2, 16, QLatin1Char('0'));
+            result += QStringLiteral("\\x%1").arg(static_cast<quint16>(c.unicode()), 2, 16,
+                                                  QLatin1Char('0'));
         }
     }
     return result;
