--- pkg/kube/wait.go.orig	2022-12-17 18:48:31 UTC
+++ pkg/kube/wait.go
@@ -22,7 +22,7 @@ import (
 	"time"
 
 	"github.com/pkg/errors"
-	"go.etcd.io/etcd/api/v3/v3rpc/rpctypes"
+	"go.etcd.io/etcd/api/v3/api/v3rpc/rpctypes"
 	"google.golang.org/grpc/codes"
 
 	appsv1 "k8s.io/api/apps/v1"
