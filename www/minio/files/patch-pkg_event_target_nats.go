--- pkg/event/target/nats.go.orig	2019-04-26 02:36:49 UTC
+++ pkg/event/target/nats.go
@@ -24,7 +24,7 @@ import (
 	"github.com/minio/minio/pkg/event"
 	xnet "github.com/minio/minio/pkg/net"
 	"github.com/nats-io/go-nats-streaming"
-	"github.com/nats-io/nats"
+	"github.com/nats-io/go-nats"
 )
 
 // NATSArgs - NATS target arguments.
