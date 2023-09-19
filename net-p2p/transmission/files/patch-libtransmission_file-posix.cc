--- libtransmission/file-posix.cc.orig	2023-09-19 12:13:51 UTC
+++ libtransmission/file-posix.cc
@@ -556,7 +556,7 @@ tr_sys_file_t tr_sys_file_get_std(tr_std_sys_file_t st
         break;
 
     default:
-        TR_ASSERT_MSG(false, fmt::format(FMT_STRING("unknown standard file {:d}"), std_file));
+        TR_ASSERT_MSG(false, fmt::format(FMT_STRING("unknown standard file {:d}"), static_cast<int>(std_file)));
         tr_error_set_from_errno(error, EINVAL);
     }
 
