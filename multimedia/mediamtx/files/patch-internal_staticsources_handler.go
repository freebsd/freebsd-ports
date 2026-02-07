--- internal/staticsources/handler.go.orig	2025-08-16 07:32:58 UTC
+++ internal/staticsources/handler.go
@@ -13,7 +13,7 @@ import (
 	"github.com/bluenviron/mediamtx/internal/logger"
 	sshls "github.com/bluenviron/mediamtx/internal/staticsources/hls"
 	ssmpegts "github.com/bluenviron/mediamtx/internal/staticsources/mpegts"
-	ssrpicamera "github.com/bluenviron/mediamtx/internal/staticsources/rpicamera"
+//	ssrpicamera "github.com/bluenviron/mediamtx/internal/staticsources/rpicamera"
 	ssrtmp "github.com/bluenviron/mediamtx/internal/staticsources/rtmp"
 	ssrtp "github.com/bluenviron/mediamtx/internal/staticsources/rtp"
 	ssrtsp "github.com/bluenviron/mediamtx/internal/staticsources/rtsp"
@@ -146,12 +146,12 @@ func (s *Handler) Initialize() {
 			Parent:      s,
 		}
 
-	case s.Conf.Source == "rpiCamera":
-		s.instance = &ssrpicamera.Source{
-			RTPMaxPayloadSize: s.RTPMaxPayloadSize,
-			LogLevel:          s.LogLevel,
-			Parent:            s,
-		}
+//	case s.Conf.Source == "rpiCamera":
+//		s.instance = &ssrpicamera.Source{
+//			RTPMaxPayloadSize: s.RTPMaxPayloadSize,
+//			LogLevel:          s.LogLevel,
+//			Parent:            s,
+//		}
 
 	default:
 		panic("should not happen")
