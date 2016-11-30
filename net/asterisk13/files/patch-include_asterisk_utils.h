--- include/asterisk/utils.h.orig	2016-11-23 15:26:01 UTC
+++ include/asterisk/utils.h
@@ -1127,4 +1127,13 @@ int ast_file_is_readable(const char *fil
  */
 int ast_compare_versions(const char *version1, const char *version2);
 
+/*
+ * \brief Test that an OS supports IPv6 Networking.
+ * \since 13.14.0
+ *
+ * \return True (non-zero) if the IPv6 supported.
+ * \return False (zero) if the OS doesn't support IPv6.
+ */
+int ast_check_ipv6(void);
+
 #endif /* _ASTERISK_UTILS_H */
