--- go.mod.orig	2023-03-21 15:50:06 UTC
+++ go.mod
@@ -1,11 +1,10 @@
 module github.com/go-graphite/carbonapi
 
-go 1.14
+go 1.17
 
 require (
 	bitbucket.org/tebeka/strftime v0.0.0-20140926081919-2194253a23c0
 	github.com/JaderDias/movingmedian v0.0.0-20170611140316-de8c410559fa
-	github.com/aclements/go-moremath v0.0.0-20190830160640-d16893ddf098 // indirect
 	github.com/ansel1/merry v1.5.1
 	github.com/bradfitz/gomemcache v0.0.0-20190913173617-a41fca850d0b
 	github.com/dgryski/go-expirecache v0.0.0-20170314133854-743ef98b2adb
@@ -13,16 +12,8 @@ require (
 	github.com/dgryski/httputil v0.0.0-20160116060654-189c2918cd08
 	github.com/dustin/go-humanize v1.0.0
 	github.com/evmar/gocairo v0.0.0-20160222165215-ddd30f837497
-	github.com/facebookgo/atomicfile v0.0.0-20151019160806-2de1f203e7d5 // indirect
-	github.com/facebookgo/clock v0.0.0-20150410010913-600d898af40a // indirect
-	github.com/facebookgo/ensure v0.0.0-20200202191622-63f1cf65ac4c // indirect
-	github.com/facebookgo/freeport v0.0.0-20150612182905-d4adf43b75b9 // indirect
 	github.com/facebookgo/grace v0.0.0-20180706040059-75cf19382434
-	github.com/facebookgo/httpdown v0.0.0-20180706035922-5979d39b15c2 // indirect
 	github.com/facebookgo/pidfile v0.0.0-20150612191647-f242e2999868
-	github.com/facebookgo/stack v0.0.0-20160209184415-751773369052 // indirect
-	github.com/facebookgo/stats v0.0.0-20151006221625-1b76add642e4 // indirect
-	github.com/facebookgo/subset v0.0.0-20200203212716-c811ad88dec4 // indirect
 	github.com/go-graphite/protocol v0.4.3
 	github.com/golang/protobuf v1.4.0
 	github.com/gorilla/handlers v1.4.2
@@ -32,7 +23,6 @@ require (
 	github.com/maruel/natural v0.0.0-20180416170133-dbcb3e2e8cf1
 	github.com/mjibson/go-dsp v0.0.0-20180508042940-11479a337f12
 	github.com/peterbourgon/g2g v0.0.0-20161124161852-0c2bab2b173d
-	github.com/philhofer/fwd v1.0.0 // indirect
 	github.com/satori/go.uuid v1.2.0
 	github.com/spf13/viper v1.6.3
 	github.com/stretchr/testify v1.5.1
@@ -42,4 +32,39 @@ require (
 	gonum.org/v1/gonum v0.7.0
 	google.golang.org/grpc v1.29.1
 	gopkg.in/yaml.v2 v2.2.8
+)
+
+require (
+	github.com/aclements/go-moremath v0.0.0-20190830160640-d16893ddf098 // indirect
+	github.com/davecgh/go-spew v1.1.1 // indirect
+	github.com/facebookgo/atomicfile v0.0.0-20151019160806-2de1f203e7d5 // indirect
+	github.com/facebookgo/clock v0.0.0-20150410010913-600d898af40a // indirect
+	github.com/facebookgo/ensure v0.0.0-20200202191622-63f1cf65ac4c // indirect
+	github.com/facebookgo/freeport v0.0.0-20150612182905-d4adf43b75b9 // indirect
+	github.com/facebookgo/httpdown v0.0.0-20180706035922-5979d39b15c2 // indirect
+	github.com/facebookgo/stack v0.0.0-20160209184415-751773369052 // indirect
+	github.com/facebookgo/stats v0.0.0-20151006221625-1b76add642e4 // indirect
+	github.com/facebookgo/subset v0.0.0-20200203212716-c811ad88dec4 // indirect
+	github.com/fsnotify/fsnotify v1.4.7 // indirect
+	github.com/gogo/protobuf v1.2.1 // indirect
+	github.com/hashicorp/hcl v1.0.0 // indirect
+	github.com/magiconair/properties v1.8.1 // indirect
+	github.com/mitchellh/mapstructure v1.1.2 // indirect
+	github.com/pelletier/go-toml v1.2.0 // indirect
+	github.com/philhofer/fwd v1.0.0 // indirect
+	github.com/pmezard/go-difflib v1.0.0 // indirect
+	github.com/spf13/afero v1.1.2 // indirect
+	github.com/spf13/cast v1.3.0 // indirect
+	github.com/spf13/jwalterweatherman v1.0.0 // indirect
+	github.com/spf13/pflag v1.0.3 // indirect
+	github.com/subosito/gotenv v1.2.0 // indirect
+	go.uber.org/atomic v1.6.0 // indirect
+	go.uber.org/multierr v1.5.0 // indirect
+	golang.org/x/net v0.0.0-20190620200207-3b0461eec859 // indirect
+	golang.org/x/sys v0.6.0 // indirect
+	golang.org/x/text v0.3.0 // indirect
+	golang.org/x/xerrors v0.0.0-20191204190536-9bdfabe68543 // indirect
+	google.golang.org/genproto v0.0.0-20190819201941-24fa4b261c55 // indirect
+	google.golang.org/protobuf v1.21.0 // indirect
+	gopkg.in/ini.v1 v1.51.0 // indirect
 )
