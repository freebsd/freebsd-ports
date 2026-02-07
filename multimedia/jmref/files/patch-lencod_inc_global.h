--- lencod/inc/global.h.orig	2015-06-19 11:50:52 UTC
+++ lencod/inc/global.h
@@ -1606,7 +1606,7 @@ extern void make_frame_picture_JV( VideoParameters *p_
 
 
 
-char errortext[ET_SIZE]; //!< buffer for error message for exit with error()
+extern char errortext[ET_SIZE]; //!< buffer for error message for exit with error()
 extern void setup_coding_layer(VideoParameters *p_Vid);
 
 static inline int is_FREXT_profile(unsigned int profile_idc) 
