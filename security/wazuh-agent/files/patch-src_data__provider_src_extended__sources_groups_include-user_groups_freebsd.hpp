--- /dev/null	2026-01-13 23:11:31.853795000 +0000
+++ src/data_provider/src/extended_sources/groups/include/user_groups_freebsd.hpp	2026-01-13 22:43:51.149735000 +0000
@@ -0,0 +1,81 @@
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
+#include "ipasswd_wrapper.hpp"
+
+#define EXPECTED_GROUPS_MAX 64
+
+class UserGroupsProvider
+{
+    public:
+        /// @brief Constructs a UserGroupsProvider with specific wrappers.
+        /// @param groupWrapper A shared pointer to an IGroupWrapperFreeBSD instance for group operations.
+        /// @param passwdWrapper A shared pointer to an IPasswdWrapperFreeBSD instance for passwd operations.
+        /// @param sysWrapper A shared pointer to an ISystemWrapper instance for system operations.
+        explicit UserGroupsProvider(std::shared_ptr<IGroupWrapperFreeBSD> groupWrapper,
+                                    std::shared_ptr<IPasswdWrapperFreeBSD> passwdWrapper);
+
+        /// @brief Default constructor that initializes the UserGroupsProvider with default wrappers.
+        /// @note This constructor uses default implementations of IGroupWrapperFreeBSD, and IPasswdWrapperFreeBSD.
+        UserGroupsProvider();
+
+        /// @brief Collects user groups information.
+        /// @param uids A set of user IDs (UIDs) to filter the results. If empty, all users are collected.
+        /// @return A JSON array containing user groups information, where each entry includes UID, GID, and group details.
+        nlohmann::json collect(const std::set<uid_t>& uids = {});
+
+        /// @brief Retrieves group names associated with the specified UIDs.
+        /// @param uids A set of user IDs (UIDs) for which to retrieve group names.
+        /// @return A JSON object where keys are UIDs and values are arrays of group names associated with those UIDs.
+        /// If a UID has no associated groups, the value will be an empty array.
+        /// @note This method is useful for quickly mapping UIDs to their group names without retrieving full group details.
+        /// @note If `uids` is empty, it retrieves group names for all users.
+        nlohmann::json getGroupNamesByUid(const std::set<uid_t>& uids = {});
+
+        /// @brief Retrieves usernames associated with the specified GIDs.
+        /// @param gids A set of group IDs (GIDs) for which to retrieve usernames.
+        /// @return A JSON object where keys are GIDs and values are arrays of usernames associated with those GIDs.
+        /// If a GID has no associated usernames, the value will be an empty array.
+        /// @note This method is useful for quickly mapping GIDs to their usernames without retrieving full user details.
+        /// @note If `gids` is empty, it retrieves usernames for all groups.
+        nlohmann::json getUserNamesByGid(const std::set<gid_t>& gids = {});
+
+    private:
+        std::shared_ptr<IGroupWrapperFreeBSD> m_groupWrapper;
+        std::shared_ptr<IPasswdWrapperFreeBSD> m_passwdWrapper;
+
+        /// @brief Structure to hold user information.
+        struct UserInfo
+        {
+            const char* name;
+            uid_t uid;
+            gid_t gid;
+        };
+
+        /// @brief Retrieves groups for each user and returns a vector of pairs containing UID and their associated groups.
+        /// @param uids A set of user IDs (UIDs) to filter the results. If empty, all users are processed.
+        /// @return A vector of pairs, where each pair contains a UID and a vector of GIDs representing the groups associated with that UID.
+        /// @note This method is used internally to gather user-group associations before formatting the results into JSON.
+        /// @note If a user has no associated groups, the vector of GIDs will be empty.
+        std::vector<std::pair<uid_t, std::vector<gid_t>>> getUserGroups(const std::set<uid_t>& uids);
+
+        /// @brief Adds groups to the results JSON array for a specific user.
+        /// @param results A reference to the JSON array where the group information will be added.
+        /// @param uid The user ID for which the groups are being added.
+        /// @param groups A pointer to an array of group IDs (GIDs) associated with the user.
+        /// @param ngroups The number of groups in the `groups` array.
+        /// @note This method formats the group information into JSON objects and appends them to the results array.
+        void addGroupsToResults(nlohmann::json& results, uid_t uid, const gid_t* groups, int ngroups);
+};
