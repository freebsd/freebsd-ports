--- pkg/eks/auth.go.orig	2018-08-17 20:19:48 UTC
+++ pkg/eks/auth.go
@@ -192,7 +192,7 @@ func (c *ClientConfig) WithExecHeptioAuthenticator() *
 	x := clientConfigCopy.Client.AuthInfos[c.ContextName]
 	x.Exec = &clientcmdapi.ExecConfig{
 		APIVersion: "client.authentication.k8s.io/v1alpha1",
-		Command:    "heptio-authenticator-aws",
+		Command:    "aws-iam-authenticator",
 		Args:       []string{"token", "-i", c.Cluster.ClusterName},
 		/*
 			Args:       []string{"token", "-i", c.Cluster.ClusterName, "-r", c.roleARN},
