--- src/signaling/natsclient.go.orig	2020-12-25 20:55:38 UTC
+++ src/signaling/natsclient.go
@@ -29,7 +29,7 @@ import (
 	"os/signal"
 	"time"
 
-	"github.com/nats-io/go-nats"
+	"github.com/nats-io/nats.go"
 )
 
 const (
