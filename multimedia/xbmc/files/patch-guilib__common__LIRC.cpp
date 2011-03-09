--- guilib/common/LIRC.cpp.orig	2011-03-07 14:16:12.000000000 +0100
+++ guilib/common/LIRC.cpp	2011-03-07 14:11:31.000000000 +0100
@@ -19,11 +19,14 @@
 *
 */
 
+#include "config.h"
 #include <sys/time.h>
 #include <sys/types.h>
 #include <sys/socket.h>
 #include <sys/un.h>
+#ifdef HAVE_INOTIFY
 #include <sys/inotify.h>
+#endif
 #include <limits.h>
 #include <unistd.h>
 #include "LIRC.h"
@@ -92,12 +95,14 @@
       close(m_fd);
     m_fd = -1;
     m_file = NULL;
+#ifdef HAVE_INOTIFY
     if (m_inotify_wd >= 0) {
       inotify_rm_watch(m_inotify_fd, m_inotify_wd);
       m_inotify_wd = -1;
     }
     if (m_inotify_fd >= 0)
       close(m_inotify_fd);
+#endif
 
     m_inReply = false;
     m_nrSending = 0;
@@ -148,6 +153,7 @@
         {
           if ((m_file = fdopen(m_fd, "r+")) != NULL)
           {
+#ifdef HAVE_INOTIFY
             // Setup inotify so we can disconnect if lircd is restarted
             if ((m_inotify_fd = inotify_init()) >= 0)
             {
@@ -168,6 +174,10 @@
                 }
               }
             }
+#else
+            m_bInitialized = true;
+            CLog::Log(LOGINFO, "LIRC %s: sucessfully started", __FUNCTION__);
+#endif
           }
           else
             CLog::Log(LOGERROR, "LIRC %s: fdopen failed: %s", __FUNCTION__, strerror(errno));
@@ -206,6 +216,7 @@
 }
 
 bool CRemoteControl::CheckDevice() {
+#ifdef HAVE_INOTIFY
   if (m_inotify_fd < 0 || m_inotify_wd < 0)
     return true; // inotify wasn't setup for some reason, assume all is well
   int bufsize = sizeof(struct inotify_event) + PATH_MAX;
@@ -220,6 +231,7 @@
     }
     i += sizeof(struct inotify_event)+e->len;
   }
+#endif
   return true;
 }
 
