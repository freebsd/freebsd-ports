--- src/signaling/backend_server_test.go.orig	2020-12-25 20:55:38 UTC
+++ src/signaling/backend_server_test.go
@@ -42,7 +42,7 @@ import (
 	"github.com/dlintw/goconf"
 	"github.com/gorilla/mux"
 	"github.com/gorilla/websocket"
-	"github.com/nats-io/go-nats"
+	"github.com/nats-io/nats.go"
 )
 
 var (
