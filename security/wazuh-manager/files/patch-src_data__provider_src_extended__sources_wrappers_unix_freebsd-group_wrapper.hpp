--- /dev/null	2026-01-13 23:16:40.390101000 +0000
+++ src/data_provider/src/extended_sources/wrappers/unix/freebsd/group_wrapper.hpp	2026-01-13 22:43:51.149572000 +0000
@@ -0,0 +1,90 @@
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
+#include "igroup_wrapper.hpp"
+
+#include <grp.h>
+#include <unistd.h>
+
+/// @brief Wrapper class for group-related operations on FreeBSD systems.
+///
+/// Provides methods to retrieve group lists and counts for users, allowing for dependency injection
+/// and easier testing. This class implements the IGroupWrapperFreeBSD interface and uses the system calls
+/// to interact with the group database.
+class GroupWrapperFreeBSD : public IGroupWrapperFreeBSD
+{
+    public:
+        /// @brief Retrieves the group entry for a given group ID.
+        /// @param gid The group ID to search for.
+        /// @param resultbuf A pointer to a group structure where the result will be stored.
+        /// @param buffer A buffer to hold the string data for the group entry.
+        /// @param buflen The size of the buffer.
+        /// @param result A pointer to a group structure pointer that will point to the result.
+        /// @return 0 on success, or an error code on failure.
+        int getgrgid_r(gid_t gid, struct group* resultbuf, char* buffer, size_t buflen, struct group** result) const override
+        {
+            return ::getgrgid_r(gid, resultbuf, buffer, buflen, result);
+        }
+
+        /// @brief Retrieves a group by its GID.
+        /// @param gid The group ID for which to retrieve the group structure.
+        /// @return A pointer to the group structure if found, or nullptr if not found.
+        struct group* getgrgid(gid_t gid) const override
+        {
+            return ::getgrgid(gid);
+        }
+
+        /// @brief Retrieves the group entry for a given group name.
+        /// @param resultbuf A pointer to a group structure where the result will be stored.
+        /// @param buffer A buffer to hold the string data for the group entry.
+        /// @param buflen The size of the buffer.
+        /// @param result A pointer to a group structure pointer that will point to the result.
+        int getgrent_r(struct group* resultbuf, char* buffer, size_t buflen, struct group** result) const override
+        {
+            return ::getgrent_r(resultbuf, buffer, buflen, result);
+        }
+
+        /// @brief Retrieves the next group entry from the group database.
+        /// @return A pointer to the next group structure, or nullptr if there are no more entries.
+        struct group* getgrent() const override
+        {
+            return ::getgrent();
+        }
+
+        /// @brief Rewind the group-file stream.
+        void setgrent() const override
+        {
+            ::setgrent();
+        }
+        /// @brief Close the group-file stream.
+        void endgrent() const override
+        {
+            ::endgrent();
+        }
+        /// @brief Retrieves a group by its name.
+        /// @param name The name of the group to retrieve.
+        /// @return A pointer to the group structure if found, or nullptr if not found.
+        struct group* getgrnam(const char* name) const override
+        {
+            return ::getgrnam(name);
+        }
+
+        /// @brief Retrieves the list of groups for a user.
+        /// @param user The username for which to retrieve the group list.
+        /// @param group The primary group ID of the user.
+        /// @param groups Pointer to an array where the group IDs will be stored.
+        /// @param ngroups Pointer to an integer that indicates the size of the groups array.
+        /// @return The number of groups the user belongs to, or -1 on error.
+        int getgrouplist(const char* user, gid_t group, gid_t* groups, int* ngroups) const override
+        {
+            return ::getgrouplist(user, group, groups, ngroups);
+        }
+};
