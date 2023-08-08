--- go.mod.orig	2023-03-24 22:49:20 UTC
+++ go.mod
@@ -1,6 +1,6 @@
 module github.com/zrepl/zrepl
 
-go 1.12
+go 1.17
 
 require (
 	github.com/fatih/color v1.7.0
@@ -15,37 +15,68 @@ require (
 	github.com/google/uuid v1.1.2
 	github.com/jinzhu/copier v0.0.0-20170922082739-db4671f3a9b8
 	github.com/juju/ratelimit v1.0.1
-	github.com/k0kubun/colorstring v0.0.0-20150214042306-9440f1994b88 // indirect
 	github.com/kr/pretty v0.1.0
-	github.com/leodido/go-urn v1.2.1 // indirect
 	github.com/lib/pq v1.2.0
-	github.com/mattn/go-colorable v0.1.4 // indirect
 	github.com/mattn/go-isatty v0.0.8
 	github.com/montanaflynn/stats v0.5.0
-	github.com/onsi/ginkgo v1.10.2 // indirect
-	github.com/onsi/gomega v1.7.0 // indirect
 	github.com/pkg/errors v0.8.1
 	github.com/pkg/profile v1.2.1
 	github.com/problame/go-netssh v0.0.0-20200601114649-26439f9f0dc5
 	github.com/prometheus/client_golang v1.2.1
 	github.com/prometheus/common v0.7.0
 	github.com/robfig/cron/v3 v3.0.1
-	github.com/sergi/go-diff v1.0.1-0.20180205163309-da645544ed44 // indirect; go1.12 thinks it needs this
 	github.com/spf13/cobra v0.0.2
 	github.com/spf13/pflag v1.0.5
 	github.com/stretchr/testify v1.6.1
 	github.com/willf/bitset v1.1.10
 	github.com/yudai/gojsondiff v0.0.0-20170107030110-7b1b7adf999d
-	github.com/yudai/golcs v0.0.0-20170316035057-ecda9a501e82 // indirect; go1.12 thinks it needs this
-	github.com/yudai/pp v2.0.1+incompatible // indirect
 	github.com/zrepl/yaml-config v0.0.0-20191220194647-cbb6b0cf4bdd
 	gitlab.com/tslocum/cview v1.5.3
 	golang.org/x/net v0.0.0-20210119194325-5f4716e94777
 	golang.org/x/sync v0.0.0-20190423024810-112230192c58
-	golang.org/x/sys v0.0.0-20210124154548-22da62e12c0c
+	golang.org/x/sys v0.6.0
 	golang.org/x/tools v0.0.0-20190524140312-2c0ae7006135
-	google.golang.org/genproto v0.0.0-20210122163508-8081c04a3579 // indirect
 	google.golang.org/grpc v1.35.0
 	google.golang.org/protobuf v1.25.0
+)
+
+require (
+	github.com/alecthomas/template v0.0.0-20190718012654-fb15b899a751 // indirect
+	github.com/alecthomas/units v0.0.0-20190717042225-c3de453c63f4 // indirect
+	github.com/beorn7/perks v1.0.1 // indirect
+	github.com/cespare/xxhash/v2 v2.1.0 // indirect
+	github.com/davecgh/go-spew v1.1.1 // indirect
+	github.com/ftrvxmtrx/fd v0.0.0-20150925145434-c6d800382fff // indirect
+	github.com/gdamore/encoding v1.0.0 // indirect
+	github.com/go-playground/locales v0.13.0 // indirect
+	github.com/go-playground/universal-translator v0.17.0 // indirect
+	github.com/inconshreveable/mousetrap v1.0.0 // indirect
+	github.com/konsorten/go-windows-terminal-sequences v1.0.1 // indirect
+	github.com/kr/logfmt v0.0.0-20140226030751-b84e30acd515 // indirect
+	github.com/kr/text v0.1.0 // indirect
+	github.com/leodido/go-urn v1.2.1 // indirect
+	github.com/lucasb-eyer/go-colorful v1.0.3 // indirect
+	github.com/mattn/go-colorable v0.1.4 // indirect
+	github.com/mattn/go-runewidth v0.0.10 // indirect
+	github.com/matttproud/golang_protobuf_extensions v1.0.1 // indirect
+	github.com/onsi/ginkgo v1.10.2 // indirect
+	github.com/onsi/gomega v1.7.0 // indirect
+	github.com/pmezard/go-difflib v1.0.0 // indirect
+	github.com/prometheus/client_model v0.0.0-20190812154241-14fe0d1b01d4 // indirect
+	github.com/prometheus/procfs v0.0.5 // indirect
+	github.com/rivo/uniseg v0.2.0 // indirect
+	github.com/sergi/go-diff v1.0.1-0.20180205163309-da645544ed44 // indirect; go1.12 thinks it needs this
+	github.com/sirupsen/logrus v1.4.2 // indirect
+	github.com/theckman/goconstraint v1.11.0 // indirect
+	github.com/yudai/golcs v0.0.0-20170316035057-ecda9a501e82 // indirect; go1.12 thinks it needs this
+	github.com/yudai/pp v2.0.1+incompatible // indirect
+	gitlab.com/tslocum/cbind v0.1.4 // indirect
+	golang.org/x/crypto v0.0.0-20200622213623-75b288015ac9 // indirect
+	golang.org/x/term v0.0.0-20201210144234-2321bbc49cbf // indirect
+	golang.org/x/text v0.3.5 // indirect
+	google.golang.org/appengine v1.4.0 // indirect
+	google.golang.org/genproto v0.0.0-20210122163508-8081c04a3579 // indirect
+	gopkg.in/alecthomas/kingpin.v2 v2.2.6 // indirect
 	gopkg.in/go-playground/assert.v1 v1.2.1 // indirect
+	gopkg.in/yaml.v3 v3.0.0-20200313102051-9f266ea9e77c // indirect
 )
