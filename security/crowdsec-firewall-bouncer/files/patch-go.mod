--- go.mod.orig	2023-03-27 14:53:33 UTC
+++ go.mod
@@ -1,30 +1,55 @@
 module github.com/crowdsecurity/cs-firewall-bouncer
 
-go 1.14
+go 1.17
 
 require (
-	github.com/ahmetb/dlog v0.0.0-20170105205344-4fb5f8204f26 // indirect
-	github.com/antonmedv/expr v1.9.0 // indirect
 	github.com/coreos/go-systemd v0.0.0-20191104093116-d3cd4ed1dbcf
 	github.com/crowdsecurity/crowdsec v1.3.0
 	github.com/crowdsecurity/go-cs-bouncer v0.0.0-20220209104231-631313ec9d39
+	github.com/google/nftables v0.0.0-20220206174406-91d3b4571db1
+	github.com/pkg/errors v0.9.1
+	github.com/sirupsen/logrus v1.8.1
+	golang.org/x/sys v0.6.0
+	gopkg.in/natefinch/lumberjack.v2 v2.0.0
+	gopkg.in/tomb.v2 v2.0.0-20161208151619-d5d1b5820637
+	gopkg.in/yaml.v2 v2.4.0
+)
+
+require (
+	github.com/PuerkitoBio/purell v1.1.1 // indirect
+	github.com/PuerkitoBio/urlesc v0.0.0-20170810143723-de5bf2ad4578 // indirect
+	github.com/antonmedv/expr v1.9.0 // indirect
+	github.com/asaskevich/govalidator v0.0.0-20210307081110-f21760c49a8d // indirect
+	github.com/buger/jsonparser v1.1.1 // indirect
+	github.com/crowdsecurity/grokky v0.0.0-20220120093523-d5b3478363fa // indirect
+	github.com/davecgh/go-spew v1.1.1 // indirect
+	github.com/go-openapi/analysis v0.21.2 // indirect
+	github.com/go-openapi/errors v0.20.2 // indirect
+	github.com/go-openapi/jsonpointer v0.19.5 // indirect
+	github.com/go-openapi/jsonreference v0.19.6 // indirect
 	github.com/go-openapi/loads v0.21.1 // indirect
 	github.com/go-openapi/runtime v0.23.0 // indirect
+	github.com/go-openapi/spec v0.20.4 // indirect
 	github.com/go-openapi/strfmt v0.21.2 // indirect
 	github.com/go-openapi/swag v0.21.1 // indirect
+	github.com/go-openapi/validate v0.20.3 // indirect
 	github.com/go-stack/stack v1.8.1 // indirect
-	github.com/google/nftables v0.0.0-20220206174406-91d3b4571db1
+	github.com/google/go-cmp v0.5.7 // indirect
+	github.com/google/go-querystring v1.1.0 // indirect
 	github.com/hashicorp/go-version v1.4.0 // indirect
-	github.com/logrusorgru/grokky v0.0.0-20180829062225-47edf017d42c // indirect
+	github.com/josharian/intern v1.0.0 // indirect
+	github.com/josharian/native v1.0.0 // indirect
+	github.com/koneu/natend v0.0.0-20150829182554-ec0926ea948d // indirect
+	github.com/mailru/easyjson v0.7.7 // indirect
 	github.com/mdlayher/netlink v1.6.0 // indirect
-	github.com/pkg/errors v0.9.1
-	github.com/sirupsen/logrus v1.8.1
+	github.com/mdlayher/socket v0.1.1 // indirect
+	github.com/mitchellh/mapstructure v1.4.3 // indirect
+	github.com/oklog/ulid v1.3.1 // indirect
 	github.com/vishvananda/netns v0.0.0-20190625233234-7109fa855b0f // indirect
 	go.mongodb.org/mongo-driver v1.8.3 // indirect
-	golang.org/x/sys v0.0.0-20220207234003-57398862261d
-	gopkg.in/natefinch/lumberjack.v2 v2.0.0
-	gopkg.in/tomb.v2 v2.0.0-20161208151619-d5d1b5820637
-	gopkg.in/yaml.v2 v2.4.0
+	golang.org/x/net v0.0.0-20220127200216-cd36cc0744dd // indirect
+	golang.org/x/sync v0.0.0-20210220032951-036812b2e83c // indirect
+	golang.org/x/text v0.3.7 // indirect
 )
 
 exclude github.com/mattn/go-sqlite3 v2.0.3+incompatible
