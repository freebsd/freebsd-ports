--- src/lyxim.C.orig	Thu Jul 11 19:10:30 2002
+++ src/lyxim.C	Thu Jul 11 19:16:31 2002
@@ -19,6 +19,10 @@
 
 #define DUMMY_FONT_NAME       "-*-*-*-R-Normal--14-130-75-75-*-*"
 
+#include <iostream>
+
+using namespace std;
+
 //extern FD_form_main *fd_form_main;
 extern MiniBuffer *minibuffer;
 extern BufferView *current_view;
