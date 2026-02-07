--- mdnsd/control.h.orig	2017-03-10 09:24:12 UTC
+++ mdnsd/control.h
@@ -26,10 +26,12 @@
 
 #include "mdnsd.h"
 
-struct {
+struct control_state {
 	struct event	ev;
 	int		fd;
-} control_state;
+};
+
+extern struct control_state control_state;
 
 enum blockmodes {
 	BM_NORMAL,
