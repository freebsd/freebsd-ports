Fix for a build failure, taken from

http://article.gmane.org/gmane.mail.opensmtpd.general/2291

--- openbsd-compat/defines.h.orig
+++ openbsd-compat/defines.h
@@ -79,6 +79,10 @@
 # define MAXHOSTNAMELEN  64
 #endif
 
+#ifndef HOST_NAME_MAX
+# define HOST_NAME_MAX 255
+#endif
+
 #ifndef LOGIN_NAME_MAX
 # define LOGIN_NAME_MAX 9
 #endif
