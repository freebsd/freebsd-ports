lib/AutoTypeX11.cpp:195:16: error: assigning to 'Window' (aka 'unsigned long') from incompatible type 'nullptr_t'
        focusWindow = NULL;
                      ^~~~
--- src/lib/AutoTypeX11.cpp.orig	2009-09-13 14:43:10 UTC
+++ src/lib/AutoTypeX11.cpp
@@ -23,6 +23,7 @@
 #include "mainwindow.h"
 #include "lib/HelperX11.h"
 #include <QX11Info>
+#include <time.h>
 
 #ifndef GLOBAL_AUTOTYPE
 AutoType* autoType = NULL;
@@ -191,7 +192,7 @@ void AutoTypeX11::perform(IEntryHandle* entry, bool hi
 	}
 	
 	inAutoType = false;
-	focusWindow = NULL;
+	focusWindow = 0;
 }
 
 void AutoTypeX11::sleepTime(int msec){
