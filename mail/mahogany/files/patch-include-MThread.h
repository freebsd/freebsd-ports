--- include/MThread.h.orig	Wed Jul 23 00:01:38 2003
+++ include/MThread.h	Sun Oct  5 00:39:39 2003
@@ -19,8 +19,23 @@
 
 #if USE_THREADS
 
+#include "wx/thread.h"
+
 // use inheritance and not typedef to allow forward declaring it
-class MMutex : public wxMutex { };
+class MMutex : public wxMutex {
+public:
+    bool IsLocked() const {
+    	if ( TryLock() == wxMUTEX_NO_ERROR )
+	{
+	    Unlock();
+	    return false;
+	}
+	else 
+	{
+	    return true;
+	}
+    }
+};
 
 #else // !USE_THREADS
 
