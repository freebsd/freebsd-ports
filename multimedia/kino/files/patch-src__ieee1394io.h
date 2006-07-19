--- src/ieee1394io.h.orig	Sun May 21 19:14:23 2006
+++ src/ieee1394io.h	Tue Jul 18 22:56:29 2006
@@ -20,8 +20,10 @@
 #ifndef _IEEE1394IO_H
 #define _IEEE1394IO_H 1
 
+#if 0
 #include <libraw1394/raw1394.h>
 #include <libraw1394/csr.h>
+#endif
 #ifdef HAVE_IEC61883
 #include <libiec61883/iec61883.h>
 #endif
@@ -29,6 +31,7 @@
 #include "dv1394.h"
 #endif
 
+#include <pthread.h>
 #include <string>
 using std::string;
 #include <deque>
@@ -114,7 +117,7 @@
 {
 private:
 	/// the handle to libraw1394
-	raw1394handle_t m_handle;
+	// raw1394handle_t m_handle;
 
 	/// the handle to libiec61883
 	iec61883_dv_fb_t m_iec61883dv;
@@ -130,7 +133,7 @@
 	void StopReceive( void );
 	bool StartThread( int port );
 	void StopThread( void );
-	int Handler( int length, int complete, unsigned char *data );
+	// int Handler( int length, int complete, unsigned char *data );
 	void *Thread();
 	void ResetHandler( void );
 
@@ -183,7 +186,7 @@
 	pthread_mutex_t avc_mutex;
 
 	/// the handle to the ieee1394 subsystem
-	raw1394handle_t avc_handle;
+	//raw1394handle_t avc_handle;
 
 public:
 	AVC( void );
@@ -211,7 +214,7 @@
 	}
 
 private:
-	static int ResetHandler( raw1394handle_t handle, unsigned int generation );
+	//static int ResetHandler( raw1394handle_t handle, unsigned int generation );
 
 };
 
