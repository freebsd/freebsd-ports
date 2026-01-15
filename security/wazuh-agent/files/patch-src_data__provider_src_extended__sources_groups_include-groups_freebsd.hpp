--- /dev/null	2026-01-13 23:10:56.926889000 +0000
+++ src/data_provider/src/extended_sources/groups/include/groups_freebsd.hpp	2026-01-13 22:43:51.149789000 +0000
@@ -0,0 +1,43 @@
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
+#include <set>
+
+#include "json.hpp"
+#include "igroup_wrapper.hpp"
+
+/// @brief Class for collecting group information on FreeBSD systems.
+///
+/// This class provides methods to collect group information from the
+/// Darwin operating system. It uses the system's group database to retrieve
+/// group details such as group name and GID. The collected data is returned
+/// in JSON format.
+class GroupsProvider
+{
+    public:
+        explicit GroupsProvider(std::shared_ptr<IGroupWrapperFreeBSD> groupWrapper);
+
+        /// @brief Default destructor.
+        GroupsProvider();
+
+        /// @brief Collects group information based on provided group IDs.
+        /// @param gids A set of group IDs to collect information for.
+        /// @return A JSON array containing group information.
+        nlohmann::json collect(const std::set<gid_t>& gids = {});
+
+    private:
+        std::shared_ptr<IGroupWrapperFreeBSD> m_groupWrapper;
+
+        /// @brief Adds a group to the results JSON array.
+        /// @param results A reference to the JSON array where the group information will be added.
+        /// @param group A pointer to the group structure containing the group information.
+        void addGroupToResults(nlohmann::json& results, const struct group* group);
+};
