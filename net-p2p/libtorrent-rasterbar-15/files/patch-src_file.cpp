--- src/file.cpp.orig	2010-02-14 17:25:41.000000000 -0800
+++ src/file.cpp	2010-02-14 17:26:10.000000000 -0800
@@ -930,12 +930,12 @@
 				return false;
 			}
 #else
-			int ret = posix_fallocate(m_fd, 0, s);
-			if (ret != 0)
-			{
-				ec = error_code(ret, get_posix_category());
+			// int ret = posix_fallocate(m_fd, 0, s);
+			// if (ret != 0)
+			// {
+			// 	ec = error_code(ret, get_posix_category());
 				return false;
-			}
+			// }
 #endif
 		}
 #endif
