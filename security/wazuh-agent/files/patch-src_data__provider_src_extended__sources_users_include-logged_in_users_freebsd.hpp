--- /dev/null	2026-01-13 23:08:55.189229000 +0000
+++ src/data_provider/src/extended_sources/users/include/logged_in_users_freebsd.hpp	2026-01-13 22:43:51.148959000 +0000
@@ -0,0 +1,34 @@
+/* Copyright (C) 2015, Wazuh Inc.
+ * All rights reserved.
+ *
+ * This program is free software; you can redistribute it
+ * and/or modify it under the terms of the GNU General Public
+ * License (version 2) as published by the FSF - Free Software
+ * Foundation.
+ */
+
+#pragma once
+
+#include <map>
+#include <mutex>
+#include <string>
+#include <vector>
+
+#include "json.hpp"
+#include "iutmpx_wrapper.hpp"
+
+class LoggedInUsersProvider
+{
+    public:
+        explicit LoggedInUsersProvider(std::shared_ptr<IUtmpxWrapper> utmpxWrapper);
+
+        LoggedInUsersProvider();
+
+        nlohmann::json collect();
+
+    private:
+        std::shared_ptr<IUtmpxWrapper> m_utmpxWrapper;
+
+        static std::mutex utmpxMutex;
+        static const std::map<size_t, std::string> loginTypes;
+};
