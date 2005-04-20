--- NCursesFrontend.cpp~	Wed Feb 23 09:05:23 2005
+++ NCursesFrontend.cpp	Fri Apr 15 15:43:27 2005
@@ -27,6 +27,7 @@
 #include <unistd.h>
 #include <stdarg.h>
 #include <signal.h>
+#include <libgen.h>
 
 #include "NCursesFrontend.h"
 
@@ -342,7 +343,7 @@
 					  NCURSES_COLORPAIR_DEBUG};
 
 	NCOLORON( iMessageTypeColor[Msg.m_eType] );
-	mvprintw( iRow, 0, szMessageType[ Msg.m_eType ] );
+	mvprintw( iRow, 0, (char *)szMessageType[ Msg.m_eType ] );
 	NCOLOROFF( iMessageTypeColor[Msg.m_eType] );
 
 	char szBuffer[512];
