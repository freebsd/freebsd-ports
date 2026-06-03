--- app/node/project/serializer/serializer230220.cpp.orig	2026-03-01 03:09:36 UTC
+++ app/node/project/serializer/serializer230220.cpp
@@ -190,9 +190,9 @@ ProjectSerializer230220::LoadData ProjectSerializer230
             } else if (attr.name() == QStringLiteral("ptr")) {
               ptr = attr.value().toULongLong();
             } else if (attr.name() == QStringLiteral("items")) {
-              QVector<QStringRef> l = attr.value().split(',');
+              QList<QStringView> l = attr.value().split(',');
               items.reserve(l.size());
-              for (const QStringRef &s : l) {
+              for (QStringView s : l) {
                 items.append(s.toULongLong());
               }
             }
