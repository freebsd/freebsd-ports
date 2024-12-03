--- src/shared_modules/utils/timeHelper.h.orig	2024-10-17 00:22:27.000000000 -0700
+++ src/shared_modules/utils/timeHelper.h	2024-10-20 00:02:09.915969000 -0700
@@ -196,6 +196,17 @@
         return output.str();
     }
 
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
+
     /**
      * @brief Get seconds from epoch, since 1970-01-01 00:00:00 UTC.
      * @return seconds from epoch.
