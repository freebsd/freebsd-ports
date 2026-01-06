--- src/libtscore/system/tsFileUtils.cpp 2026-01-06 14:00 UTC
+++ src/libtscore/system/tsFileUtils.cpp
@@ -355,8 +355,8 @@ bool ts::SetFileModificationTimeUTC(const UString& path, const Time& time)
     const cn::microseconds usec = std::max(cn::microseconds::zero(), cn::duration_cast<cn::microseconds>(time - Time::UnixEpoch));
     ::timeval times[2];
     // times[0] specifies the new access time, and times[1] specifies the new modification time.
-    times[0].tv_sec = times[1].tv_sec = usec.count() / 1'000'000;
-    times[0].tv_usec = times[1].tv_usec = usec.count() % 1'000'000;
+    times[0].tv_sec = times[1].tv_sec = decltype(times[0].tv_sec)(usec.count() / 1'000'000);
+    times[0].tv_usec = times[1].tv_usec = decltype(times[0].tv_usec)(usec.count() % 1'000'000);
     return ::utimes(path.toUTF8().c_str(), times) == 0;
 #endif
 }
