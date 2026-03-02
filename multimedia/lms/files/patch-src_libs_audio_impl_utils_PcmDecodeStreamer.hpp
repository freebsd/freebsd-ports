--- src/libs/audio/impl/utils/PcmDecodeStreamer.hpp.orig	2026-03-02 18:25:37 UTC
+++ src/libs/audio/impl/utils/PcmDecodeStreamer.hpp
@@ -20,6 +20,7 @@
 #pragma once
 
 #include <cstddef>
+#include <span>
 #include <vector>
 
 #include <boost/asio/io_context.hpp>
@@ -78,4 +79,4 @@ namespace lms::audio::utils
 
         DecodeCompleteCallback _decodeCompleteCallback;
     };
-} // namespace lms::audio::utils
\ No newline at end of file
+} // namespace lms::audio::utils
