--- include/vlc_sout.h.orig	2014-11-16 18:57:58 UTC
+++ include/vlc_sout.h
@@ -28,6 +28,9 @@
 #ifndef VLC_SOUT_H_
 #define VLC_SOUT_H_
 
+#include <sys/types.h>
+#include <vlc_es.h>
+
 /**
  * \file
  * This file defines structures and functions for stream output in vlc
@@ -37,9 +40,6 @@
 extern "C" {
 #endif
 
-#include <sys/types.h>
-#include <vlc_es.h>
-
 /** Stream output instance (FIXME: should be private to src/ to avoid
  * invalid unsynchronized access) */
 struct sout_instance_t
