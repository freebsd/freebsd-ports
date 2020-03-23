--- Telegram/lib_base/base/thread_safe_wrap.h.orig	2020-01-29 09:41:30 UTC
+++ Telegram/lib_base/base/thread_safe_wrap.h
@@ -19,13 +19,13 @@ class thread_safe_wrap { (public)
 
 	template <typename Callback>
 	auto with(Callback &&callback) {
-		QMutexLocker lock(&_mutex);
+		QMutexLocker lock((QBasicMutex *)&_mutex);
 		return callback(_value);
 	}
 
 	template <typename Callback>
 	auto with(Callback &&callback) const {
-		QMutexLocker lock(&_mutex);
+		QMutexLocker lock((QBasicMutex *)&_mutex);
 		return callback(_value);
 	}
 
