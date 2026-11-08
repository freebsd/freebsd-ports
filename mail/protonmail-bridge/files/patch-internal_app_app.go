--- internal/app/app.go.orig	1979-11-29 15:00:00 UTC
+++ internal/app/app.go
@@ -47,7 +47,7 @@ import (
 	"github.com/ProtonMail/proton-bridge/v3/internal/vault"
 	"github.com/ProtonMail/proton-bridge/v3/pkg/keychain"
 	"github.com/ProtonMail/proton-bridge/v3/pkg/restarter"
-	"github.com/elastic/go-sysinfo"
+	// "github.com/elastic/go-sysinfo"
 	"github.com/pkg/profile"
 	"github.com/sirupsen/logrus"
 	"github.com/urfave/cli/v2"
@@ -450,17 +450,17 @@ func withLogging(c *cli.Context, crashHandler *crash.H
 		WithField("offset", now.Format("-07:00:00")).
 		Info("Time zone info")
 
-	host, err := sysinfo.Host()
-	if err != nil {
-		logrus.WithError(err).Error("Could not retrieve operating system info")
-	} else {
-		osInfo := host.Info().OS
-		logrus.
-			WithField("name", osInfo.Name).
-			WithField("version", osInfo.Version).
-			WithField("build", osInfo.Build).
-			Info("Operating system info")
-	}
+	// host, err := sysinfo.Host()
+	// if err != nil {
+	// 	logrus.WithError(err).Error("Could not retrieve operating system info")
+	// } else {
+	// 	osInfo := host.Info().OS
+	// 	logrus.
+	// 		WithField("name", osInfo.Name).
+	// 		WithField("version", osInfo.Version).
+	// 		WithField("build", osInfo.Build).
+	// 		Info("Operating system info")
+	// }
 
 	return fn(closer)
 }
