--- /dev/null	2026-01-13 23:17:10.457712000 +0000
+++ src/data_provider/src/extended_sources/wrappers/unix/freebsd/ipasswd_wrapper.hpp	2026-01-13 22:43:51.149517000 +0000
@@ -0,0 +1,69 @@
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
+#include <pwd.h>
+
+// Interface for the pwd darwin wrapper
+class IPasswdWrapperFreeBSD
+{
+    public:
+        /// Destructor
+        virtual ~IPasswdWrapperFreeBSD() = default;
+
+        /// @brief Retrieves the passwd entry for the given username.
+        /// @param name The username to search for.
+        /// @return A pointer to the passwd structure, or nullptr if not found.
+        virtual struct passwd* getpwnam(const char* name) = 0;
+
+        /// @brief Retrieves the passwd entry for the given user ID.
+        /// @param uid The user ID to search for.
+        /// @return A pointer to the passwd structure, or nullptr if not found.
+        virtual struct passwd* getpwuid(uid_t uid) = 0;
+
+        /// @brief Retrieves the passwd entry for the given user ID.
+        /// @param uid User ID to search.
+        /// @param pwd Pointer to a passwd structure to fill.
+        /// @param buf Buffer used to store string fields.
+        /// @param buflen Size of the buffer.
+        /// @param result Pointer to store the result (null if not found).
+        /// @return 0 on success, or an error number on failure.
+        virtual int getpwuid_r(uid_t uid, struct passwd* pwd,
+                               char* buf, size_t buflen, struct passwd** result) = 0;
+
+        /// @brief Retrieves the passwd entry for the given username.
+        /// @param name Username to search.
+        /// @param pwd Pointer to a passwd structure to fill.
+        /// @param buf Buffer used to store string fields.
+        /// @param buflen Size of the buffer.
+        /// @param result Pointer to store the result (null if not found).
+        /// @return 0 on success, or an error number on failure.
+        virtual int getpwnam_r(const char* name, struct passwd* pwd,
+                               char* buf, size_t buflen, struct passwd** result) = 0;
+
+        /// @brief Rewinds the passwd database to the beginning.
+        virtual void setpwent() = 0;
+
+        /// @brief Retrieves the next entry from the passwd database.
+        /// @return A pointer to the passwd structure, or nullptr if no more entries.
+        virtual struct passwd* getpwent() = 0;
+
+        /// @brief Retrieves the next entry from the passwd database.
+        /// @param pwd Pointer to a passwd structure to fill.
+        /// @param buf Buffer used to store string fields.
+        /// @param buflen Size of the buffer.
+        /// @param result Pointer to store the result (null if not found).
+        /// @return 0 on success, or an error number on failure.
+        virtual int getpwent_r(struct passwd* pwd, char* buf,
+                               size_t buflen, struct passwd** result) = 0;
+
+        /// @brief Closes the passwd database.
+        virtual void endpwent() = 0;
+};
