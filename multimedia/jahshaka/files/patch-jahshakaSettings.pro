--- jahshakaSettings.pro.orig
+++ jahshakaSettings.pro
@@ -197,6 +197,79 @@
        
 }
 
+##############################################
+# FreeBSD specific settings here
+##############################################
+
+contains( OSNAME, FreeBSD ) {
+    message( "Using FreeBSD presets..." )
+    OSDEF = FOUND
+
+    #os specific variable
+    JAHOS=LINUX
+    DEFINES += JAHLINUX
+
+#    QTPATH = /usr/lib/qt-3.1
+#    JAHDEPENDPATH = /usr/lib/qt-3.1/include
+
+    #location of freetype libraries
+    FREEDIR = %%LOCALBASE%%/include/freetype2
+ 
+    #for the audio hack
+    contains( JAHAUDIO,true ) {
+    #we hack the directories where libaudio is on to freedir
+#    FREEDIR += /usr/local/include
+#    FREEDIR += /usr/include
+        DEFINES += AUDIOSUPPORT
+    }
+
+    #for avi
+    contains( LINUXAVISUPPORT,true ) {
+        DEFINES += LINUXAVISUPPORT
+    }
+
+    #for spaceball
+    contains( SPACEBALL,true ) {
+        DEFINES += SPACEBALL
+    }
+
+    #for native mpeg support
+    contains( JAHMPEGDECODER,true ) {
+        DEFINES += JAHMPEGDECODER
+    }
+
+    #for native mpeg encoder support
+    contains( JAHMPEGENCODER,true ) {
+        DEFINES += JAHMPEGENCODER
+    }
+
+    #for Clearspeed
+    contains( CLEARSPEED,true ) {
+        DEFINES += CLEARSPEED
+        DEFINES += __LITTLE_ENDIAN
+    }
+
+    #for Nvidia GPU
+    contains( NVIDIA_GPU,true ) {
+        DEFINES += NVIDIA_GPU
+    }
+
+    #for Nvidia GPGPU
+    contains( NVIDIA_GPGPU,true ) {
+        DEFINES += NVIDIA_GPGPU
+    }
+
+    #for qt theme support
+        contains( JAHTHEMES,true ) {
+        DEFINES += JAHTHEMES
+    }
+
+    #for jahplayer support
+    contains( JAHPLAYER,true ) {
+        DEFINES += JAHPLAYER
+    }
+}
+
 ###############################################################
 # Sgi Irix old Qt specific settings here
 
