--- kmid/player/sndcard.h	Tue Jul 14 07:49:07 1998
+++ kmid/player/sndcard.h.new	Wed Jun 12 22:38:48 2002
@@ -1,11 +1,7 @@
 #ifndef _SNDCARD_H
 #define _SNDCARD_H
 
-#ifndef __FreeBSD__
 #include <sys/soundcard.h>
-#else
-#include <machine/soundcard.h>
-#endif
 
 
 #ifndef HZ
