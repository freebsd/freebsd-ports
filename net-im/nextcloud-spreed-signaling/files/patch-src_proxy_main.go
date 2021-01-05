--- src/proxy/main.go.orig	2020-12-25 20:55:38 UTC
+++ src/proxy/main.go
@@ -36,7 +36,7 @@ import (
 
 	"github.com/dlintw/goconf"
 	"github.com/gorilla/mux"
-	"github.com/nats-io/go-nats"
+	"github.com/nats-io/nats.go"
 
 	"signaling"
 )
