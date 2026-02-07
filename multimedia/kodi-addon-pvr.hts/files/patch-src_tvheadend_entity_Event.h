[ 74%] Building CXX object CMakeFiles/pvr.hts.dir/src/tvheadend/entity/RecordingBase.cpp.o
/usr/bin/c++  -DADDON_GLOBAL_VERSION_GUI_USED -DADDON_GLOBAL_VERSION_MAIN_USED -DADDON_INSTANCE_VERSION_PVR_USED -DBUILD_KODI_ADDON -DUSE_DEMUX -Dpvr_hts_EXPORTS -I/usr/local/include -I/usr/local/include/kodi -I/usr/local/include/p8-platform -I/usr/home/decke/dev/ports/multimedia/kodi-addon-pvr-hts/work/pvr.hts-4.4.2-Leia/lib -std=c++11 -O2 -pipe -fstack-protector -fno-strict-aliasing -fPIC   -D_LINUX -DTARGET_POSIX -DTARGET_FREEBSD -DHAVE_SSE=1 -DHAVE_SSE2=1 -DHAVE_SSE3=1 -DHAVE_SSSE3=1 -DHAVE_SSE4_1=1 -DHAVE_SSE4_2=1 -o CMakeFiles/pvr.hts.dir/src/tvheadend/entity/RecordingBase.cpp.o -c /usr/home/decke/dev/ports/multimedia/kodi-addon-pvr-hts/work/pvr.hts-4.4.2-Leia/src/tvheadend/entity/RecordingBase.cpp
--- CMakeFiles/pvr.hts.dir/src/tvheadend/entity/Event.cpp.o ---
In file included from /usr/home/decke/dev/ports/multimedia/kodi-addon-pvr-hts/work/pvr.hts-4.4.2-Leia/src/tvheadend/entity/Event.cpp:22:
/usr/home/decke/dev/ports/multimedia/kodi-addon-pvr-hts/work/pvr.hts-4.4.2-Leia/src/tvheadend/entity/Event.h:105:7: error: unknown type name 'time_t'
      time_t GetStart() const { return m_start; }
      ^
/usr/home/decke/dev/ports/multimedia/kodi-addon-pvr-hts/work/pvr.hts-4.4.2-Leia/src/tvheadend/entity/Event.h:106:21: error: unknown type name 'time_t'
      void SetStart(time_t start) { m_start = start; }
                    ^
/usr/home/decke/dev/ports/multimedia/kodi-addon-pvr-hts/work/pvr.hts-4.4.2-Leia/src/tvheadend/entity/Event.h:108:7: error: unknown type name 'time_t'
      time_t GetStop() const { return m_stop; }
      ^
/usr/home/decke/dev/ports/multimedia/kodi-addon-pvr-hts/work/pvr.hts-4.4.2-Leia/src/tvheadend/entity/Event.h:109:20: error: unknown type name 'time_t'
      void SetStop(time_t stop) { m_stop = stop; }
                   ^
/usr/home/decke/dev/ports/multimedia/kodi-addon-pvr-hts/work/pvr.hts-4.4.2-Leia/src/tvheadend/entity/Event.h:117:7: error: unknown type name 'time_t'
      time_t GetAired() const { return m_aired; }

Submitted by:	Bernhard Froehlich <decke@FreeBSD.org>
[ 74%] Building CXX object CMakeFiles/pvr.hts.dir/src/tvheadend/entity/RecordingBase.cpp.o
/usr/bin/c++  -DADDON_GLOBAL_VERSION_GUI_USED -DADDON_GLOBAL_VERSION_MAIN_USED -DADDON_INSTANCE_VERSION_PVR_USED -DBUILD_KODI_ADDON -DUSE_DEMUX -Dpvr_hts_EXPORTS -I/usr/local/include -I/usr/local/include/kodi -I/usr/local/include/p8-platform -I/usr/home/decke/dev/ports/multimedia/kodi-addon-pvr-hts/work/pvr.hts-4.4.2-Leia/lib -std=c++11 -O2 -pipe -fstack-protector -fno-strict-aliasing -fPIC   -D_LINUX -DTARGET_POSIX -DTARGET_FREEBSD -DHAVE_SSE=1 -DHAVE_SSE2=1 -DHAVE_SSE3=1 -DHAVE_SSSE3=1 -DHAVE_SSE4_1=1 -DHAVE_SSE4_2=1 -o CMakeFiles/pvr.hts.dir/src/tvheadend/entity/RecordingBase.cpp.o -c /usr/home/decke/dev/ports/multimedia/kodi-addon-pvr-hts/work/pvr.hts-4.4.2-Leia/src/tvheadend/entity/RecordingBase.cpp
--- src/tvheadend/entity/Event.h.orig	2020-12-03 21:26:09 UTC
+++ src/tvheadend/entity/Event.h
@@ -10,6 +10,7 @@
 
 #include "Entity.h"
 
+#include <sys/types.h>
 #include <cstdint>
 #include <map>
 #include <string>
