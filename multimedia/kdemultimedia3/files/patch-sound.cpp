--- kscd/kscdmagic/sound.cpp	Fri Aug 11 17:44:48 2000
+++ kscd/kscdmagic/sound.cpp.new	Wed Jun 12 22:40:59 2002
@@ -49,7 +49,7 @@
 
 // who knows when we'll need that...
 #if defined (FreeBSD)
-#include <machine/soundcard.h>
+#include <sys/soundcard.h>
 #include <sys/cdio.h>
 #define CDROM_LEADOUT 0xAA
 #define CD_FRAMES 75 /* frames per second */
