--- fcgi.h.orig
+++ fcgi.h
@@ -57,10 +57,14 @@
 #define XtOffsetOf APR_OFFSETOF
 #define ap_select select
 
-#define ap_user_id        unixd_config.user_id
-#define ap_group_id       unixd_config.group_id
-#define ap_user_name      unixd_config.user_name
-#define ap_suexec_enabled unixd_config.suexec_enabled
+#if MODULE_MAGIC_NUMBER_MAJOR < 20081201
+#define ap_unixd_config unixd_config
+#endif
+
+#define ap_user_id        ap_unixd_config.user_id
+#define ap_group_id       ap_unixd_config.group_id
+#define ap_user_name      ap_unixd_config.user_name
+#define ap_suexec_enabled ap_unixd_config.suexec_enabled
 
 #ifndef S_ISDIR
 #define S_ISDIR(m)      (((m)&(S_IFMT)) == (S_IFDIR))
@@ -354,42 +358,42 @@
 #ifdef APACHE2
 
 #ifdef WIN32
-#define FCGI_LOG_EMERG          __FILE__,__LINE__,APLOG_EMERG,APR_FROM_OS_ERROR(GetLastError())
-#define FCGI_LOG_ALERT          __FILE__,__LINE__,APLOG_ALERT,APR_FROM_OS_ERROR(GetLastError())
-#define FCGI_LOG_CRIT           __FILE__,__LINE__,APLOG_CRIT,APR_FROM_OS_ERROR(GetLastError())
-#define FCGI_LOG_ERR            __FILE__,__LINE__,APLOG_ERR,APR_FROM_OS_ERROR(GetLastError())
-#define FCGI_LOG_WARN           __FILE__,__LINE__,APLOG_WARNING,APR_FROM_OS_ERROR(GetLastError())
-#define FCGI_LOG_NOTICE         __FILE__,__LINE__,APLOG_NOTICE,APR_FROM_OS_ERROR(GetLastError())
-#define FCGI_LOG_INFO           __FILE__,__LINE__,APLOG_INFO,APR_FROM_OS_ERROR(GetLastError())
-#define FCGI_LOG_DEBUG          __FILE__,__LINE__,APLOG_DEBUG,APR_FROM_OS_ERROR(GetLastError())
+#define FCGI_LOG_EMERG          APLOG_MARK,APLOG_EMERG,APR_FROM_OS_ERROR(GetLastError())
+#define FCGI_LOG_ALERT          APLOG_MARK,APLOG_ALERT,APR_FROM_OS_ERROR(GetLastError())
+#define FCGI_LOG_CRIT           APLOG_MARK,APLOG_CRIT,APR_FROM_OS_ERROR(GetLastError())
+#define FCGI_LOG_ERR            APLOG_MARK,APLOG_ERR,APR_FROM_OS_ERROR(GetLastError())
+#define FCGI_LOG_WARN           APLOG_MARK,APLOG_WARNING,APR_FROM_OS_ERROR(GetLastError())
+#define FCGI_LOG_NOTICE         APLOG_MARK,APLOG_NOTICE,APR_FROM_OS_ERROR(GetLastError())
+#define FCGI_LOG_INFO           APLOG_MARK,APLOG_INFO,APR_FROM_OS_ERROR(GetLastError())
+#define FCGI_LOG_DEBUG          APLOG_MARK,APLOG_DEBUG,APR_FROM_OS_ERROR(GetLastError())
 #else /* !WIN32 */
-#define FCGI_LOG_EMERG          __FILE__,__LINE__,APLOG_EMERG,APR_FROM_OS_ERROR(errno)
-#define FCGI_LOG_ALERT          __FILE__,__LINE__,APLOG_ALERT,APR_FROM_OS_ERROR(errno)
-#define FCGI_LOG_CRIT           __FILE__,__LINE__,APLOG_CRIT,APR_FROM_OS_ERROR(errno)
-#define FCGI_LOG_ERR            __FILE__,__LINE__,APLOG_ERR,APR_FROM_OS_ERROR(errno)
-#define FCGI_LOG_WARN           __FILE__,__LINE__,APLOG_WARNING,APR_FROM_OS_ERROR(errno)
-#define FCGI_LOG_NOTICE         __FILE__,__LINE__,APLOG_NOTICE,APR_FROM_OS_ERROR(errno)
-#define FCGI_LOG_INFO           __FILE__,__LINE__,APLOG_INFO,APR_FROM_OS_ERROR(errno)
-#define FCGI_LOG_DEBUG          __FILE__,__LINE__,APLOG_DEBUG,APR_FROM_OS_ERROR(errno)
+#define FCGI_LOG_EMERG          APLOG_MARK,APLOG_EMERG,APR_FROM_OS_ERROR(errno)
+#define FCGI_LOG_ALERT          APLOG_MARK,APLOG_ALERT,APR_FROM_OS_ERROR(errno)
+#define FCGI_LOG_CRIT           APLOG_MARK,APLOG_CRIT,APR_FROM_OS_ERROR(errno)
+#define FCGI_LOG_ERR            APLOG_MARK,APLOG_ERR,APR_FROM_OS_ERROR(errno)
+#define FCGI_LOG_WARN           APLOG_MARK,APLOG_WARNING,APR_FROM_OS_ERROR(errno)
+#define FCGI_LOG_NOTICE         APLOG_MARK,APLOG_NOTICE,APR_FROM_OS_ERROR(errno)
+#define FCGI_LOG_INFO           APLOG_MARK,APLOG_INFO,APR_FROM_OS_ERROR(errno)
+#define FCGI_LOG_DEBUG          APLOG_MARK,APLOG_DEBUG,APR_FROM_OS_ERROR(errno)
 #endif
 
-#define FCGI_LOG_EMERG_ERRNO    __FILE__,__LINE__,APLOG_EMERG,APR_FROM_OS_ERROR(errno)
-#define FCGI_LOG_ALERT_ERRNO    __FILE__,__LINE__,APLOG_ALERT,APR_FROM_OS_ERROR(errno)
-#define FCGI_LOG_CRIT_ERRNO     __FILE__,__LINE__,APLOG_CRIT,APR_FROM_OS_ERROR(errno)
-#define FCGI_LOG_ERR_ERRNO      __FILE__,__LINE__,APLOG_ERR,APR_FROM_OS_ERROR(errno)
-#define FCGI_LOG_WARN_ERRNO     __FILE__,__LINE__,APLOG_WARNING,APR_FROM_OS_ERROR(errno)
-#define FCGI_LOG_NOTICE_ERRNO   __FILE__,__LINE__,APLOG_NOTICE,APR_FROM_OS_ERROR(errno)
-#define FCGI_LOG_INFO_ERRNO     __FILE__,__LINE__,APLOG_INFO,APR_FROM_OS_ERROR(errno)
-#define FCGI_LOG_DEBUG_ERRNO    __FILE__,__LINE__,APLOG_DEBUG,APR_FROM_OS_ERROR(errno)
-
-#define FCGI_LOG_EMERG_NOERRNO    __FILE__,__LINE__,APLOG_EMERG,0
-#define FCGI_LOG_ALERT_NOERRNO    __FILE__,__LINE__,APLOG_ALERT,0
-#define FCGI_LOG_CRIT_NOERRNO     __FILE__,__LINE__,APLOG_CRIT,0
-#define FCGI_LOG_ERR_NOERRNO      __FILE__,__LINE__,APLOG_ERR,0
-#define FCGI_LOG_WARN_NOERRNO     __FILE__,__LINE__,APLOG_WARNING,0
-#define FCGI_LOG_NOTICE_NOERRNO   __FILE__,__LINE__,APLOG_NOTICE,0
-#define FCGI_LOG_INFO_NOERRNO     __FILE__,__LINE__,APLOG_INFO,0
-#define FCGI_LOG_DEBUG_NOERRNO    __FILE__,__LINE__,APLOG_DEBUG,0
+#define FCGI_LOG_EMERG_ERRNO    APLOG_MARK,APLOG_EMERG,APR_FROM_OS_ERROR(errno)
+#define FCGI_LOG_ALERT_ERRNO    APLOG_MARK,APLOG_ALERT,APR_FROM_OS_ERROR(errno)
+#define FCGI_LOG_CRIT_ERRNO     APLOG_MARK,APLOG_CRIT,APR_FROM_OS_ERROR(errno)
+#define FCGI_LOG_ERR_ERRNO      APLOG_MARK,APLOG_ERR,APR_FROM_OS_ERROR(errno)
+#define FCGI_LOG_WARN_ERRNO     APLOG_MARK,APLOG_WARNING,APR_FROM_OS_ERROR(errno)
+#define FCGI_LOG_NOTICE_ERRNO   APLOG_MARK,APLOG_NOTICE,APR_FROM_OS_ERROR(errno)
+#define FCGI_LOG_INFO_ERRNO     APLOG_MARK,APLOG_INFO,APR_FROM_OS_ERROR(errno)
+#define FCGI_LOG_DEBUG_ERRNO    APLOG_MARK,APLOG_DEBUG,APR_FROM_OS_ERROR(errno)
+
+#define FCGI_LOG_EMERG_NOERRNO    APLOG_MARK,APLOG_EMERG,0
+#define FCGI_LOG_ALERT_NOERRNO    APLOG_MARK,APLOG_ALERT,0
+#define FCGI_LOG_CRIT_NOERRNO     APLOG_MARK,APLOG_CRIT,0
+#define FCGI_LOG_ERR_NOERRNO      APLOG_MARK,APLOG_ERR,0
+#define FCGI_LOG_WARN_NOERRNO     APLOG_MARK,APLOG_WARNING,0
+#define FCGI_LOG_NOTICE_NOERRNO   APLOG_MARK,APLOG_NOTICE,0
+#define FCGI_LOG_INFO_NOERRNO     APLOG_MARK,APLOG_INFO,0
+#define FCGI_LOG_DEBUG_NOERRNO    APLOG_MARK,APLOG_DEBUG,0
 
 #else /* !APACHE2 */
 
