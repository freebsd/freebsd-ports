--- src/libreal/real_common.c.orig	Sun Jul  1 14:29:20 2007
+++ src/libreal/real_common.c	Sun Jul  1 14:29:55 2007
@@ -91,6 +91,7 @@
   else try_real_subpath("lib/codecs")
   else try_real_subpath("lib64/RealPlayer10/codecs")
   else try_real_subpath("lib/RealPlayer10/codecs")
+  else try_real_subpath("lib/RealPlayer/codecs")
   else try_real_subpath("lib64/RealPlayer9/users/Real/Codecs")
   else try_real_subpath("lib/RealPlayer9/users/Real/Codecs")
   else try_real_subpath("lib/RealPlayer8/Codecs")
