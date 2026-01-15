--- /dev/null	2026-01-13 23:09:49.988051000 +0000
+++ src/data_provider/src/extended_sources/users/include/users_freebsd.hpp	2026-01-13 22:43:51.149043000 +0000
@@ -0,0 +1,66 @@
+/* Copyright (C) 2015, Wazuh Inc.
+ * All rights reserved.
+ *
+ * This program is free software; you can redistribute it
+ * and/or modify it under the terms of the GNU General Public
+ * License (version 2) as published by the FSF - Free Software
+ * Foundation.
+ */
+
+#include <map>
+#include <memory>
+#include <set>
+#include <string>
+
+#include "json.hpp"
+
+#include "ipasswd_wrapper.hpp"
+
+/// @brief Provides user information on FreeBSD systems.
+///
+/// Collects user data by combining information from the passwd database,
+///
+/// Dependencies are injected via wrappers for testability and abstraction.
+class UsersProvider
+{
+    public:
+        /// @brief Constructs a UsersProvider with the given wrappers.
+        /// @param passwdWrapper Wrapper for password database operations.
+        /// @param sysWrapper Wrapper for system-level operations.
+        explicit UsersProvider(
+            std::shared_ptr<IPasswdWrapperFreeBSD> passwdWrapper);
+
+        /// @brief Default constructor.
+        UsersProvider();
+
+        /// @brief Collects all user information, optionally including remote users.
+        /// @param include_remote Whether to include remote users in the collection (default: true).
+        /// @return JSON array of user information objects.
+        nlohmann::json collect(bool include_remote = true);
+
+        /// @brief Collects user information filtered by usernames and UIDs, optionally including remote users.
+        /// @param usernames Set of usernames to filter.
+        /// @param uids Set of UIDs to filter.
+        /// @param include_remote Whether to include remote users in the collection.
+        /// @return JSON array of user information objects matching the constraints.
+        nlohmann::json collectWithConstraints(const std::set<std::string>& usernames,
+                                              const std::set<uid_t>& uids,
+                                              bool include_remote);
+
+    private:
+        /// @brief Generates a JSON representation of a user from passwd struct.
+        /// @param pwd Pointer to passwd struct representing the user.
+        /// @param include_remote Boolean indicating whether remote users are included.
+        /// @return JSON object representing the user.
+        nlohmann::json genUserJson(const struct passwd* pwd, bool include_remote);
+
+        /// @brief Collects local users filtered by usernames and UIDs.
+        /// @param usernames Set of usernames to filter.
+        /// @param uids Set of UIDs to filter.
+        /// @return JSON array of local user information.
+        nlohmann::json collectUsers(const std::set<std::string>& usernames,
+                                         const std::set<uid_t>& uids);
+
+        /// @brief Passwd wrapper dependency.
+        std::shared_ptr<IPasswdWrapperFreeBSD> m_passwdWrapper;
+};
