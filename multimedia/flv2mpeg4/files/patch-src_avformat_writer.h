Index: avformat_writer.h
@@ -28,7 +28,7 @@
 #include <memory.h>
 
 #include "type.h"
-#include "avformat.h" // libavformat is part of ffmpeg(http://ffmpeg.sf.net)
+#include "libavformat/avformat.h" // libavformat is part of ffmpeg(http://ffmpeg.sf.net)
 #include "mp3header.h"
 
 typedef struct _AVFWRITER
