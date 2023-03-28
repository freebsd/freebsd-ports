--- go.mod.orig	2023-03-28 11:27:12 UTC
+++ go.mod
@@ -1,6 +1,6 @@
 module git.torproject.org/pluggable-transports/snowflake.git/v2
 
-go 1.15
+go 1.17
 
 require (
 	git.torproject.org/pluggable-transports/goptlib.git v1.3.0
@@ -19,8 +19,49 @@ require (
 	github.com/xtaci/smux v1.5.15
 	gitlab.torproject.org/tpo/anti-censorship/geoip v0.0.0-20210928150955-7ce4b3d98d01
 	golang.org/x/crypto v0.0.0-20220516162934-403b01795ae8
-	golang.org/x/net v0.0.0-20220425223048-2871e0cb64e4
+	golang.org/x/net v0.8.0
 	google.golang.org/protobuf v1.26.0
+)
+
+require (
+	github.com/beorn7/perks v1.0.1 // indirect
+	github.com/cespare/xxhash/v2 v2.1.1 // indirect
+	github.com/davecgh/go-spew v1.1.1 // indirect
+	github.com/golang/protobuf v1.5.2 // indirect
+	github.com/google/uuid v1.3.0 // indirect
+	github.com/gopherjs/gopherjs v0.0.0-20181017120253-0766667cb4d1 // indirect
+	github.com/jtolds/gls v4.20.0+incompatible // indirect
+	github.com/klauspost/cpuid v1.3.1 // indirect
+	github.com/klauspost/reedsolomon v1.9.9 // indirect
+	github.com/matttproud/golang_protobuf_extensions v1.0.1 // indirect
+	github.com/mmcloughlin/avo v0.0.0-20200803215136-443f81d77104 // indirect
+	github.com/pion/datachannel v1.5.2 // indirect
+	github.com/pion/dtls/v2 v2.1.5 // indirect
+	github.com/pion/interceptor v0.1.11 // indirect
+	github.com/pion/logging v0.2.2 // indirect
+	github.com/pion/mdns v0.0.5 // indirect
+	github.com/pion/randutil v0.1.0 // indirect
+	github.com/pion/rtcp v1.2.9 // indirect
+	github.com/pion/rtp v1.7.13 // indirect
+	github.com/pion/sctp v1.8.2 // indirect
+	github.com/pion/srtp/v2 v2.0.9 // indirect
+	github.com/pion/transport v0.13.0 // indirect
+	github.com/pion/turn/v2 v2.0.8 // indirect
+	github.com/pion/udp v0.1.1 // indirect
+	github.com/pkg/errors v0.9.1 // indirect
+	github.com/pmezard/go-difflib v1.0.0 // indirect
+	github.com/prometheus/common v0.18.0 // indirect
+	github.com/prometheus/procfs v0.6.0 // indirect
+	github.com/smartystreets/assertions v0.0.0-20180927180507-b2de0cb4f26d // indirect
+	github.com/templexxx/cpu v0.1.0 // indirect
+	github.com/templexxx/xorsimd v0.4.1 // indirect
+	github.com/tjfoc/gmsm v1.3.2 // indirect
+	golang.org/x/mod v0.8.0 // indirect
+	golang.org/x/sys v0.6.0 // indirect
+	golang.org/x/text v0.8.0 // indirect
+	golang.org/x/tools v0.6.0 // indirect
+	golang.org/x/xerrors v0.0.0-20200804184101-5ec99f83aff1 // indirect
+	gopkg.in/yaml.v3 v3.0.0-20200313102051-9f266ea9e77c // indirect
 )
 
 replace github.com/pion/webrtc/v3 v3.1.41 => github.com/xiaokangwang/webrtc/v3 v3.0.0-20230118142924-be9162e2b526
