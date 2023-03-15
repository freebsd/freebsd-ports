--- go.mod.orig	2023-03-15 09:41:05 UTC
+++ go.mod
@@ -3,7 +3,6 @@ module github.com/42wim/matterbridge
 require (
 	github.com/42wim/go-gitter v0.0.0-20170828205020-017310c2d557
 	github.com/Baozisoftware/qrcode-terminal-go v0.0.0-20170407111555-c0650d8dff0f
-	github.com/Jeffail/gabs v1.4.0 // indirect
 	github.com/Philipp15b/go-steam v1.0.1-0.20200727090957-6ae9b3c0a560
 	github.com/Rhymen/go-whatsapp v0.1.2-0.20210615184944-2b8a3e9b8aa2
 	github.com/SevereCloud/vksdk/v2 v2.10.0
@@ -13,7 +12,6 @@ require (
 	github.com/go-telegram-bot-api/telegram-bot-api v1.0.1-0.20200524105306-7434b0456e81
 	github.com/gomarkdown/markdown v0.0.0-20210514010506-3b9f47219fe7
 	github.com/google/gops v0.3.18
-	github.com/gopackage/ddp v0.0.0-20170117053602-652027933df4 // indirect
 	github.com/gorilla/schema v1.2.0
 	github.com/gorilla/websocket v1.4.2
 	github.com/hashicorp/golang-lru v0.5.4
@@ -30,10 +28,7 @@ require (
 	github.com/matterbridge/logrus-prefixed-formatter v0.5.3-0.20200523233437-d971309a77ba
 	github.com/mattermost/mattermost-server/v5 v5.30.1
 	github.com/mattn/godown v0.0.1
-	github.com/mgutz/ansi v0.0.0-20200706080929-d51e80ef957d // indirect
 	github.com/missdeer/golib v1.0.4
-	github.com/mreiferson/go-httpclient v0.0.0-20201222173833-5e475fde3a4d // indirect
-	github.com/mrexodia/wray v0.0.0-20160318003008-78a2c1f284ff // indirect
 	github.com/nelsonken/gomf v0.0.0-20180504123937-a9dd2f9deae9
 	github.com/paulrosania/go-charset v0.0.0-20190326053356-55c9d7a5834c
 	github.com/rs/xid v1.3.0
@@ -41,13 +36,11 @@ require (
 	github.com/saintfish/chardet v0.0.0-20120816061221-3af4cd4741ca
 	github.com/shazow/ssh-chat v1.10.1
 	github.com/sirupsen/logrus v1.8.1
-	github.com/skip2/go-qrcode v0.0.0-20200617195104-da1b6568686e // indirect
 	github.com/slack-go/slack v0.9.1
 	github.com/spf13/viper v1.8.0
 	github.com/stretchr/testify v1.7.0
 	github.com/vincent-petithory/dataurl v0.0.0-20191104211930-d1553a71de50
 	github.com/writeas/go-strip-markdown v2.0.1+incompatible
-	github.com/x-cray/logrus-prefixed-formatter v0.5.2 // indirect
 	github.com/yaegashi/msgraph.go v0.1.4
 	github.com/zfjagann/golang-ring v0.0.0-20210116075443-7c86fdb43134
 	golang.org/x/image v0.0.0-20210607152325-775e3b0c77b9
@@ -57,4 +50,70 @@ require (
 	layeh.com/gumble v0.0.0-20200818122324-146f9205029b
 )
 
-go 1.15
+require (
+	github.com/Jeffail/gabs v1.4.0 // indirect
+	github.com/blang/semver v3.5.1+incompatible // indirect
+	github.com/dgrijalva/jwt-go v3.2.0+incompatible // indirect
+	github.com/disintegration/imaging v1.6.2 // indirect
+	github.com/dyatlov/go-opengraph v0.0.0-20180429202543-816b6608b3c8 // indirect
+	github.com/francoispqt/gojay v1.2.13 // indirect
+	github.com/go-asn1-ber/asn1-ber v1.5.1 // indirect
+	github.com/golang/protobuf v1.5.2 // indirect
+	github.com/google/uuid v1.1.2 // indirect
+	github.com/gopackage/ddp v0.0.0-20170117053602-652027933df4 // indirect
+	github.com/hashicorp/errwrap v1.1.0 // indirect
+	github.com/hashicorp/go-multierror v1.1.0 // indirect
+	github.com/hashicorp/hcl v1.0.0 // indirect
+	github.com/labstack/gommon v0.3.0 // indirect
+	github.com/magiconair/properties v1.8.5 // indirect
+	github.com/mattermost/go-i18n v1.11.0 // indirect
+	github.com/mattermost/ldap v0.0.0-20191128190019-9f62ba4b8d4d // indirect
+	github.com/mattermost/logr v1.0.13 // indirect
+	github.com/mattn/go-colorable v0.1.8 // indirect
+	github.com/mattn/go-isatty v0.0.12 // indirect
+	github.com/mattn/go-runewidth v0.0.9 // indirect
+	github.com/mgutz/ansi v0.0.0-20200706080929-d51e80ef957d // indirect
+	github.com/mitchellh/mapstructure v1.4.1 // indirect
+	github.com/monaco-io/request v1.0.5 // indirect
+	github.com/mreiferson/go-httpclient v0.0.0-20201222173833-5e475fde3a4d // indirect
+	github.com/mrexodia/wray v0.0.0-20160318003008-78a2c1f284ff // indirect
+	github.com/pborman/uuid v1.2.1 // indirect
+	github.com/pelletier/go-toml v1.9.3 // indirect
+	github.com/philhofer/fwd v1.0.0 // indirect
+	github.com/pkg/errors v0.9.1 // indirect
+	github.com/pmezard/go-difflib v1.0.0 // indirect
+	github.com/rickb777/date v1.12.4 // indirect
+	github.com/rickb777/plural v1.2.0 // indirect
+	github.com/shazow/rateio v0.0.0-20200113175441-4461efc8bdc4 // indirect
+	github.com/skip2/go-qrcode v0.0.0-20200617195104-da1b6568686e // indirect
+	github.com/spf13/afero v1.6.0 // indirect
+	github.com/spf13/cast v1.3.1 // indirect
+	github.com/spf13/jwalterweatherman v1.1.0 // indirect
+	github.com/spf13/pflag v1.0.5 // indirect
+	github.com/subosito/gotenv v1.2.0 // indirect
+	github.com/technoweenie/multipartstreamer v1.0.1 // indirect
+	github.com/tinylib/msgp v1.1.2 // indirect
+	github.com/valyala/bytebufferpool v1.0.0 // indirect
+	github.com/valyala/fasttemplate v1.2.1 // indirect
+	github.com/wiggin77/cfg v1.0.2 // indirect
+	github.com/wiggin77/merror v1.0.2 // indirect
+	github.com/wiggin77/srslog v1.0.1 // indirect
+	github.com/x-cray/logrus-prefixed-formatter v0.5.2 // indirect
+	go.uber.org/atomic v1.7.0 // indirect
+	go.uber.org/multierr v1.6.0 // indirect
+	go.uber.org/zap v1.17.0 // indirect
+	golang.org/x/crypto v0.0.0-20210322153248-0c34fe9e7dc2 // indirect
+	golang.org/x/net v0.0.0-20210405180319-a5a99cb37ef4 // indirect
+	golang.org/x/sys v0.6.0 // indirect
+	golang.org/x/term v0.0.0-20201126162022-7de9c90e9dd1 // indirect
+	golang.org/x/text v0.3.6 // indirect
+	golang.org/x/time v0.0.0-20201208040808-7e3f01d25324 // indirect
+	google.golang.org/appengine v1.6.7 // indirect
+	google.golang.org/protobuf v1.26.0 // indirect
+	gopkg.in/ini.v1 v1.62.0 // indirect
+	gopkg.in/natefinch/lumberjack.v2 v2.0.0 // indirect
+	gopkg.in/yaml.v2 v2.4.0 // indirect
+	gopkg.in/yaml.v3 v3.0.0-20210107192922-496545a6307b // indirect
+)
+
+go 1.17
