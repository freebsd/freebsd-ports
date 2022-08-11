--- proxy/proxy_tokens_etcd.go.orig	2022-07-24 20:09:05 UTC
+++ proxy/proxy_tokens_etcd.go
@@ -33,8 +33,8 @@ import (
 	"github.com/dlintw/goconf"
 	"github.com/golang-jwt/jwt"
 
-	"go.etcd.io/etcd/client/pkg/v3/srv"
-	"go.etcd.io/etcd/client/pkg/v3/transport"
+	"go.etcd.io/etcd/client/pkg/srv"
+	"go.etcd.io/etcd/client/pkg/transport"
 	clientv3 "go.etcd.io/etcd/client/v3"
 
 	signaling "github.com/strukturag/nextcloud-spreed-signaling"
