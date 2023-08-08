Remove "vmware" from the list of imported drivers so it will not be built.
It currently fails to build and we don't support VMware anyway.

--- pkg/minikube/registry/drvs/init.go.orig	2023-07-24 08:47:05 UTC
+++ pkg/minikube/registry/drvs/init.go
@@ -28,5 +28,4 @@ import (
 	_ "k8s.io/minikube/pkg/minikube/registry/drvs/qemu2"
 	_ "k8s.io/minikube/pkg/minikube/registry/drvs/ssh"
 	_ "k8s.io/minikube/pkg/minikube/registry/drvs/virtualbox"
-	_ "k8s.io/minikube/pkg/minikube/registry/drvs/vmware"
 )
