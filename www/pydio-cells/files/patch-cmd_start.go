--- cmd/start.go.orig	2021-05-06 12:02:02 UTC
+++ cmd/start.go
@@ -289,7 +289,11 @@ ENVIRONMENT
 				if (process == nil || len(process.Services) == 0) && len(childrenProcesses) == 0 {
 					return nil
 				}
-				log.Info("Services are still running ", zap.Any("services", process.Services))
+				// Already fixed upstream, should be in the next version after 2.2.7:
+				// https://github.com/pydio/cells/issues/325
+				if (process != nil) {
+					log.Info("Services are still running ", zap.Any("services", process.Services))
+				}
 				continue
 			case <-timeout:
 				return nil
