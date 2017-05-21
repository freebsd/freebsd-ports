--- avidemux_core/ADM_coreVideoCodec/include/ADM_ffmp43.h.orig	2017-05-21 11:18:35 UTC
+++ avidemux_core/ADM_coreVideoCodec/include/ADM_ffmp43.h
@@ -180,7 +180,7 @@ ADM_COREVIDEOCODEC6_EXPORT void ADM_lavD
 #define WRAP_Open_Template(funcz,argz,display,codecid,extra) \
 {\
 AVCodec *codec=funcz(argz);\
-if(!codec) {GUI_Error_HIG("Codec",QT_TR_NOOP("Internal error finding codec"display));ADM_assert(0);} \
+if(!codec) {GUI_Error_HIG("Codec",QT_TR_NOOP("Internal error finding codec" display));ADM_assert(0);} \
   codecId=codecid; \
   _context = avcodec_alloc_context3 (codec);\
   ADM_assert (_context);\
@@ -210,13 +210,13 @@ if(!codec) {GUI_Error_HIG("Codec",QT_TR_
   \
   if (avcodec_open2(_context, codec, NULL) < 0)  \
                       { \
-                                        printf("[lavc] Decoder init: "display" video decoder failed!\n"); \
-                                        GUI_Error_HIG("Codec","Internal error opening "display); \
+                                        printf("[lavc] Decoder init: " display " video decoder failed!\n"); \
+                                        GUI_Error_HIG("Codec","Internal error opening " display); \
                                         ADM_assert(0); \
                                 } \
                                 else \
                                 { \
-                                        printf("[lavc] Decoder init: "display" video decoder initialized! (%s)\n",codec->long_name); \
+                                        printf("[lavc] Decoder init: " display " video decoder initialized! (%s)\n",codec->long_name); \
                                 } \
 }
 
