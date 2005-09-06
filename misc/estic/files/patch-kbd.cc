--- spunk/bsdsrc/kbd.cc.orig	Tue Dec 10 14:41:06 1996
+++ spunk/bsdsrc/kbd.cc	Tue Sep  6 09:54:21 2005
@@ -27,7 +27,7 @@
 #include <sys/time.h>
 #include <sys/ioctl.h>
 #ifdef FREEBSD
-#    include <machine/console.h>
+#    include <sys/kbio.h>
 #endif
 
 #include "../machine.h"
@@ -64,7 +64,7 @@
 
 
 // An array for mapping extended to virtual keys
-const VirtualMapSize = 50;
+const int VirtualMapSize = 50;
 struct { Key EK; Key VK; } VirtualMap [VirtualMapSize];
 static unsigned VirtualMapCount = 0;
 
@@ -192,7 +192,11 @@
 {
     static char CapBuf [128];
     char* CapPtr = CapBuf;
+#if __FreeBSD_version <= 500000
+    return tgetstr ((char *)Cap, &CapPtr);
+#else
     return tgetstr (Cap, &CapPtr);
+#endif
 }
 
 
@@ -649,10 +653,22 @@
 	    }
 
 	    // Now read in a new chunk of chars.
-	    int Count;
+	    int Count = 0;
 	    do {
-		Count = read (0, &Buf [BufFill], sizeof (Buf) - BufFill - 1);
-		if (Count == 0) {
+		// Timeout is 100ms
+		timeval Timeout;
+		Timeout.tv_usec = 100000;       // 100 ms
+		Timeout.tv_sec  = 0;
+
+		// File descriptor is 0 (stdin)
+		fd_set Desc;
+		FD_ZERO (&Desc);
+		FD_SET (STDIN_FILENO, &Desc);
+
+		// Check input status
+		if (select (STDIN_FILENO+1, &Desc, NULL, NULL, &Timeout) > 0) {
+		    Count = read (STDIN_FILENO, &Buf [BufFill], sizeof (Buf) - BufFill - 1);
+		} else {
 		    // Timeout waiting for a key, allow some idle processing
 		    App->Idle ();
 		}
