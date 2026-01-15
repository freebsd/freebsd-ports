--- /dev/null	2026-01-13 23:16:28.442788000 +0000
+++ src/data_provider/src/extended_sources/wrappers/unix/freebsd/igroup_wrapper.hpp	2026-01-13 22:43:51.149445000 +0000
@@ -0,0 +1,67 @@
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
+#include <grp.h>
+
+/// @brief Interface for group-related operations on FreeBSD systems.
+///
+/// Provides methods to retrieve group lists and counts for users, allowing for dependency injection
+/// and easier testing. This interface abstracts the system calls used to interact with the group database.
+class IGroupWrapperFreeBSD
+{
+    public:
+        /// @brief Default constructor.
+        virtual ~IGroupWrapperFreeBSD() = default;
+
+        /// @brief Retrieves the group entry for a given group ID.
+        /// @param gid The group ID to search for.
+        /// @param resultbuf A pointer to a group structure where the result will be stored.
+        /// @param buffer A buffer to hold the string data for the group entry.
+        /// @param buflen The size of the buffer.
+        /// @param result A pointer to a group structure pointer that will point to the result.
+        /// @return 0 on success, or an error code on failure.
+        virtual int getgrgid_r(gid_t gid, struct group* resultbuf, char* buffer, size_t buflen, struct group** result) const = 0;
+
+        /// @brief Retrieves the group entry for a given group name.
+        /// @param resultbuf A pointer to a group structure where the result will be stored.
+        /// @param buffer A buffer to hold the string data for the group entry.
+        /// @param buflen The size of the buffer.
+        /// @param result A pointer to a group structure pointer that will point to the result.
+        virtual int getgrent_r(struct group* resultbuf, char* buffer, size_t buflen, struct group** result) const = 0;
+
+        /// @brief Retrieves a group by its GID.
+        /// @param gid The group ID for which to retrieve the group structure.
+        /// @return A pointer to the group structure if found, or nullptr if not found.
+        virtual struct group* getgrgid(gid_t gid) const = 0;
+
+        /// @brief Retrieves the next group entry from the group database.
+        /// @return A pointer to the next group structure, or nullptr if there are no more entries
+        virtual struct group* getgrent() const = 0;
+
+        /// @brief Rewind the group-file stream.
+        virtual void setgrent() const = 0;
+
+        /// @brief Close the group-file stream.
+        virtual void endgrent() const = 0;
+
+        /// @brief Retrieves a group by its name.
+        /// @param name The name of the group to retrieve.
+        /// @return A pointer to the group structure if found, or nullptr if not found.
+        virtual struct group* getgrnam(const char* name) const = 0;
+
+        /// @brief Retrieves the list of groups for a user.
+        /// @param user The username for which to retrieve the group list.
+        /// @param group The primary group ID of the user.
+        /// @param groups Pointer to an array where the group IDs will be stored.
+        /// @param ngroups Pointer to an integer that indicates the size of the groups array.
+        /// @return The number of groups the user belongs to, or -1 on error.
+        virtual int getgrouplist(const char* user, gid_t group, gid_t* groups, int* ngroups) const = 0;
+};
