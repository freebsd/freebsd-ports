--- src/signaling/natsclient_loopback.go.orig	2020-12-25 20:55:38 UTC
+++ src/signaling/natsclient_loopback.go
@@ -29,7 +29,7 @@ import (
 	"sync"
 	"time"
 
-	"github.com/nats-io/go-nats"
+	"github.com/nats-io/nats.go"
 )
 
 type LoopbackNatsClient struct {
