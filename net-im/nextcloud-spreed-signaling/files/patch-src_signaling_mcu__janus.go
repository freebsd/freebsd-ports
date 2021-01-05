--- src/signaling/mcu_janus.go.orig	2020-12-25 20:55:38 UTC
+++ src/signaling/mcu_janus.go
@@ -33,7 +33,7 @@ import (
 	"time"
 
 	"github.com/dlintw/goconf"
-	"github.com/nats-io/go-nats"
+	"github.com/nats-io/nats.go"
 	"github.com/notedit/janus-go"
 )
 
