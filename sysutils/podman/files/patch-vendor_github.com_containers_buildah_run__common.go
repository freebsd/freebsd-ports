--- vendor/github.com/containers/buildah/run_common.go.orig	2024-08-20 09:45:05 UTC
+++ vendor/github.com/containers/buildah/run_common.go
@@ -83,12 +83,17 @@ func (b *Builder) addResolvConfEntries(file string, ne
 
 // addResolvConf copies files from host and sets them up to bind mount into container
 func (b *Builder) addResolvConfEntries(file string, networkNameServer []string,
-	namespaces []specs.LinuxNamespace, keepHostServers, ipv6 bool) error {
+	spec *specs.Spec, keepHostServers, ipv6 bool) error {
 	defaultConfig, err := config.Default()
 	if err != nil {
 		return fmt.Errorf("failed to get config: %w", err)
 	}
 
+	var namespaces []specs.LinuxNamespace
+	if spec.Linux != nil {
+		namespaces = spec.Linux.Namespaces
+	}
+
 	dnsServers, dnsSearch, dnsOptions := b.CommonBuildOpts.DNSServers, b.CommonBuildOpts.DNSSearch, b.CommonBuildOpts.DNSOptions
 	nameservers := make([]string, 0, len(defaultConfig.Containers.DNSServers.Get())+len(dnsServers))
 	nameservers = append(nameservers, defaultConfig.Containers.DNSServers.Get()...)
@@ -1253,7 +1258,7 @@ func (b *Builder) runUsingRuntimeSubproc(isolation def
 			}
 
 			if resolvFile != "" {
-				err = b.addResolvConfEntries(resolvFile, netResult.dnsServers, spec.Linux.Namespaces, netResult.keepHostResolvers, netResult.ipv6)
+				err = b.addResolvConfEntries(resolvFile, netResult.dnsServers, spec, netResult.keepHostResolvers, netResult.ipv6)
 				if err != nil {
 					return err
 				}
