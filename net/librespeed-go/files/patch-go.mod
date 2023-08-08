--- go.mod.orig	2023-03-20 15:04:13 UTC
+++ go.mod
@@ -1,6 +1,6 @@
 module github.com/librespeed/speedtest
 
-go 1.16
+go 1.17
 
 require (
 	github.com/breml/rootcerts v0.2.1
@@ -16,10 +16,27 @@ require (
 	github.com/oklog/ulid/v2 v2.0.2
 	github.com/pires/go-proxyproto v0.6.1
 	github.com/sirupsen/logrus v1.8.1
-	github.com/spf13/afero v1.8.0 // indirect
 	github.com/spf13/viper v1.10.1
 	github.com/umahmood/haversine v0.0.0-20151105152445-808ab04add26
 	go.etcd.io/bbolt v1.3.6
 	golang.org/x/image v0.0.0-20211028202545-6944b10bf410
-	golang.org/x/sys v0.0.0-20220114195835-da31bd327af9 // indirect
+)
+
+require (
+	github.com/fsnotify/fsnotify v1.5.1 // indirect
+	github.com/hashicorp/hcl v1.0.0 // indirect
+	github.com/kr/pretty v0.2.0 // indirect
+	github.com/magiconair/properties v1.8.5 // indirect
+	github.com/mitchellh/mapstructure v1.4.3 // indirect
+	github.com/pelletier/go-toml v1.9.4 // indirect
+	github.com/spf13/afero v1.8.0 // indirect
+	github.com/spf13/cast v1.4.1 // indirect
+	github.com/spf13/jwalterweatherman v1.1.0 // indirect
+	github.com/spf13/pflag v1.0.5 // indirect
+	github.com/subosito/gotenv v1.2.0 // indirect
+	golang.org/x/sys v0.6.0 // indirect
+	golang.org/x/text v0.3.7 // indirect
+	gopkg.in/check.v1 v1.0.0-20190902080502-41f04d3bba15 // indirect
+	gopkg.in/ini.v1 v1.66.2 // indirect
+	gopkg.in/yaml.v2 v2.4.0 // indirect
 )
