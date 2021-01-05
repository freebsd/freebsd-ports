--- src/signaling/natsclient_loopback_test.go.orig	2020-12-25 20:55:38 UTC
+++ src/signaling/natsclient_loopback_test.go
@@ -29,7 +29,7 @@ import (
 	"testing"
 	"time"
 
-	"github.com/nats-io/go-nats"
+	"github.com/nats-io/nats.go"
 )
 
 func (c *LoopbackNatsClient) waitForSubscriptionsEmpty(ctx context.Context, t *testing.T) {
