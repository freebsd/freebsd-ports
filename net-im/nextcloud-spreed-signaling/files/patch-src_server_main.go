--- src/server/main.go.orig	2020-12-25 20:55:38 UTC
+++ src/server/main.go
@@ -40,7 +40,7 @@ import (
 	"github.com/dlintw/goconf"
 	_ "github.com/gorilla/context"
 	"github.com/gorilla/mux"
-	"github.com/nats-io/go-nats"
+	"github.com/nats-io/nats.go"
 
 	"signaling"
 )
