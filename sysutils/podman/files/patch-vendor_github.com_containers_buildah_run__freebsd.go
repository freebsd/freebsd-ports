--- vendor/github.com/containers/buildah/run_freebsd.go.orig	2024-08-20 09:45:15 UTC
+++ vendor/github.com/containers/buildah/run_freebsd.go
@@ -244,7 +244,7 @@ func (b *Builder) Run(command []string, options RunOpt
 		// Only add entries here if we do not have to do setup network,
 		// if we do we have to do it much later after the network setup.
 		if !configureNetwork {
-			err = b.addResolvConfEntries(resolvFile, nil, nil, false, true)
+			err = b.addResolvConfEntries(resolvFile, nil, spec, false, true)
 			if err != nil {
 				return err
 			}
