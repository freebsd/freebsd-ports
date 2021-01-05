--- src/signaling/clientsession.go.orig	2020-12-25 20:55:38 UTC
+++ src/signaling/clientsession.go
@@ -32,7 +32,7 @@ import (
 	"time"
 	"unsafe"
 
-	"github.com/nats-io/go-nats"
+	"github.com/nats-io/nats.go"
 )
 
 var (
