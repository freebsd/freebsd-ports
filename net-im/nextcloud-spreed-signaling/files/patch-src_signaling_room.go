--- src/signaling/room.go.orig	2020-12-25 20:55:38 UTC
+++ src/signaling/room.go
@@ -31,7 +31,7 @@ import (
 	"sync"
 	"time"
 
-	"github.com/nats-io/go-nats"
+	"github.com/nats-io/nats.go"
 )
 
 const (
