From daa6646d2af5d7fb5b30489f4934c7db89868c7c Mon Sep 17 00:00:00 2001
From: Cody Oss <6331106+codyoss@users.noreply.github.com>
Date: Mon, 1 Jul 2024 10:29:54 -0500
Subject: [PATCH] fix(auth): support gRPC API keys (#10460)

Porting https://github.com/googleapis/google-api-go-client/pull/2326
which happened after we had made parity change to new auth lib.

--- vendor/cloud.google.com/go/auth/grpctransport/grpctransport.go.orig	2024-06-12 21:20:20 UTC
+++ vendor/cloud.google.com/go/auth/grpctransport/grpctransport.go
@@ -77,6 +77,9 @@ type Options struct {
 	// configured for the client, which will be compared to the universe domain
 	// that is separately configured for the credentials.
 	UniverseDomain string
+	// APIKey specifies an API key to be used as the basis for authentication.
+	// If set DetectOpts are ignored.
+	APIKey string
 
 	// InternalOptions are NOT meant to be set directly by consumers of this
 	// package, they should only be set by generated client code.
@@ -99,7 +102,8 @@ func (o *Options) validate() error {
 	if o.InternalOptions != nil && o.InternalOptions.SkipValidation {
 		return nil
 	}
-	hasCreds := o.Credentials != nil ||
+	hasCreds := o.APIKey != "" ||
+		o.Credentials != nil ||
 		(o.DetectOpts != nil && len(o.DetectOpts.CredentialsJSON) > 0) ||
 		(o.DetectOpts != nil && o.DetectOpts.CredentialsFile != "")
 	if o.DisableAuthentication && hasCreds {
@@ -213,8 +217,15 @@ func dial(ctx context.Context, secure bool, opts *Opti
 		grpc.WithTransportCredentials(transportCreds),
 	}
 
-	// Authentication can only be sent when communicating over a secure connection.
-	if !opts.DisableAuthentication {
+	if opts.APIKey != "" {
+		grpcOpts = append(grpcOpts,
+			grpc.WithPerRPCCredentials(&grpcKeyProvider{
+				apiKey:   opts.APIKey,
+				metadata: opts.Metadata,
+				secure:   secure,
+			}),
+		)
+	} else if !opts.DisableAuthentication {
 		metadata := opts.Metadata
 
 		var creds *auth.Credentials
@@ -257,6 +268,26 @@ func dial(ctx context.Context, secure bool, opts *Opti
 	grpcOpts = append(grpcOpts, opts.GRPCDialOpts...)
 
 	return grpc.DialContext(ctx, endpoint, grpcOpts...)
+}
+
+// grpcKeyProvider satisfies https://pkg.go.dev/google.golang.org/grpc/credentials#PerRPCCredentials.
+type grpcKeyProvider struct {
+	apiKey   string
+	metadata map[string]string
+	secure   bool
+}
+
+func (g *grpcKeyProvider) GetRequestMetadata(ctx context.Context, uri ...string) (map[string]string, error) {
+	metadata := make(map[string]string, len(g.metadata)+1)
+	metadata["X-goog-api-key"] = g.apiKey
+	for k, v := range g.metadata {
+		metadata[k] = v
+	}
+	return metadata, nil
+}
+
+func (g *grpcKeyProvider) RequireTransportSecurity() bool {
+	return g.secure
 }
 
 // grpcCredentialsProvider satisfies https://pkg.go.dev/google.golang.org/grpc/credentials#PerRPCCredentials.
