Fix build on i386.

/wrkdirs/usr/ports/multimedia/shotcut-qt6/work/src/shotcut/src/database.cpp:89:29:
error: non-constant-expression cannot be narrowed from type 'qint64' (aka 'long long')
to 'time_t' (aka 'int') in initializer list [-Wc++11-narrowing]
 89 | accessed.toSecsSinceEpoch() + offset, accessed.toSecsSinceEpoch() + offset

--- src/database.cpp.orig	2024-11-17 08:04:05 UTC
+++ src/database.cpp
@@ -86,7 +86,7 @@ QDir Database::thumbnailsDir()
                         auto accessed = query.value(1).toDateTime();
                         auto offset = accessed.timeZone().offsetFromUtc(accessed);
                         struct utimbuf utimes {
-                            accessed.toSecsSinceEpoch() + offset, accessed.toSecsSinceEpoch() + offset
+                            static_cast<time_t>(accessed.toSecsSinceEpoch() + offset), static_cast<time_t>(accessed.toSecsSinceEpoch() + offset)
                         };
                         ::utime(dir.filePath(fileName).toUtf8().constData(), &utimes);
                     }
