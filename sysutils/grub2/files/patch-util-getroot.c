--- util/getroot.c.orig	2010-06-11 10:37:54.000000000 +0400
+++ util/getroot.c	2010-06-11 10:38:31.000000000 +0400
@@ -454,7 +454,7 @@
 #else
 
   /* This might be truly slow, but is there any better way?  */
-  os_dev = find_root_device ("/dev", st.st_dev);
+  os_dev = find_root_device ("/dev", st.st_rdev);
 #endif
 #endif /* !__GNU__ */
 
