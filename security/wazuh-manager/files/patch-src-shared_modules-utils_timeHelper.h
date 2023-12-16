--- src/shared_modules/utils/timeHelper.h	2023-12-12 19:27:07.563605000 -0500
+++ src/shared_modules/utils/timeHelper.h	2023-12-12 19:27:29.163243000 -0500
@@ -48,8 +48,19 @@
     {
         return getTimestamp(std::time(nullptr));
     }
+
+    static std::string timeToSeconds(std::string& str) {
+        int seconds;
+        std::tm t;
+        std::istringstream ss(str);
+        ss >> std::get_time(&t, "%H:%M.%S");
+
+        seconds = t.tm_hour * 3600 + t.tm_min * 60 + t.tm_sec;
+
+        return std::to_string(seconds);
+    }
 };
 
 #pragma GCC diagnostic pop
 
-#endif // _TIME_HELPER_H
\ No newline at end of file
+#endif // _TIME_HELPER_H
