# $FreeBSD$

PORTNAME=	vuls
DISTVERSIONPREFIX=	v
DISTVERSION=		0.6.1
PORTREVISION=		1
CATEGORIES=	security

MAINTAINER=	iscandr@gmail.com
COMMENT=	Agentless vulnerability scanner

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${LOCALBASE}/bin/go-cve-dictionary:security/go-cve-dictionary

USES=	go

USE_GITHUB=	yes
GH_ACCOUNT=	future-architect
GH_SUBDIR=	src/github.com/${GH_ACCOUNT_DEFAULT}/${PORTNAME}

GH_TUPLE+=	Azure:azure-sdk-for-go:v22.2.2:azuresdkforgo/vendor/github.com/Azure/azure-sdk-for-go
GH_TUPLE+=	Azure:go-autorest:v11.2.7:azuregoautorest/vendor/github.com/Azure/go-autorest
GH_TUPLE+=	BurntSushi:toml:v0.3.1:toml/vendor/github.com/BurntSushi/toml
GH_TUPLE+=	RackSec:srslog:a4725f0:srslog/vendor/github.com/RackSec/srslog
GH_TUPLE+=	VividCortex:ewma:v1.1.1:ewma/vendor/gopkg.in/VividCortex/ewma.v1
GH_TUPLE+=	asaskevich:govalidator:v9:govalidator/vendor/github.com/asaskevich/govalidator
GH_TUPLE+=	aws:aws-sdk-go:v1.15.77:awssdkgo/vendor/github.com/aws/aws-sdk-go
GH_TUPLE+=	boltdb:bolt:v1.3.1:bolt/vendor/github.com/boltdb/bolt
GH_TUPLE+=	cenkalti:backoff:v2.0.0:backoff/vendor/github.com/cenkalti/backoff
GH_TUPLE+=	cheggaaa:pb:v1.0.26:pbv1/vendor/gopkg.in/cheggaaa/pb.v1
GH_TUPLE+=	cheggaaa:pb:v2.0.6:pb/vendor/github.com/cheggaaa/pb
GH_TUPLE+=	census-ecosystem:opencensus-go-exporter-ocagent:00af367:ocagent/vendor/contrib.go.opencensus.io/exporter/ocagent
GH_TUPLE+=	census-instrumentation:opencensus-go:v0.18.0:opencensusgo/vendor/go.opencensus.io
GH_TUPLE+=	census-instrumentation:opencensus-proto:v0.1.0:opencensusproto/vendor/github.com/census-instrumentation/opencensus-proto
GH_TUPLE+=	dgrijalva:jwt-go:v3.2.0:jwtgo/vendor/github.com/dgrijalva/jwt-go
GH_TUPLE+=	fatih:color:v1.7.0:colorv1/vendor/github.com/fatih/color
GH_TUPLE+=	fsnotify:fsnotify:v1.4.7:fsnotify/vendor/github.com/fsnotify/fsnotify
GH_TUPLE+=	go-redis:redis:v6.14.2:redis/vendor/github.com/go-redis/redis
GH_TUPLE+=	go-sql-driver:mysql:v1.4.1:mysql/vendor/github.com/go-sql-driver/mysql
GH_TUPLE+=	go-stack:stack:v1.8.0:gostack/vendor/github.com/go-stack/stack
GH_TUPLE+=	go-yaml:yaml:v2.2.1:goyaml/vendor/gopkg.in/yaml.v2
GH_TUPLE+=	golang:crypto:3d3f9f4:crypto/vendor/golang.org/x/crypto
GH_TUPLE+=	golang:net:adae6a3:golangnet/vendor/golang.org/x/net
GH_TUPLE+=	golang:protobuf:aa810b6:protobuf/vendor/github.com/golang/protobuf
GH_TUPLE+=	golang:sync:42b3178:sync/vendor/golang.org/x/sync
GH_TUPLE+=	golang:sys:33540a1f6037:sys/vendor/golang.org/x/sys
GH_TUPLE+=	golang:text:f21a4df:golangtext/vendor/golang.org/x/text
GH_TUPLE+=	google:go-genproto:b5d4398:gogenproto/vendor/google.golang.org/genproto
GH_TUPLE+=	google:google-api-go-client:83a9d30:googleapigoclient/vendor/google.golang.org/api
GH_TUPLE+=	google:subcommands:46f0354:subcommands/vendor/github.com/google/subcommands
GH_TUPLE+=	gorilla:websocket:v1.4.0:websocket/vendor/github.com/gorilla/websocket
GH_TUPLE+=	gosuri:uitable:36ee7e9:uitable/vendor/github.com/gosuri/uitable
GH_TUPLE+=	grokify:html-strip-tags-go:e9e4496:htmlstriptagsgo/vendor/github.com/grokify/html-strip-tags-go
GH_TUPLE+=	grpc:grpc-go:v1.16.0:grpcgo/vendor/google.golang.org/grpc
GH_TUPLE+=	hashicorp:go-version:v1.0.0:goversion/vendor/github.com/hashicorp/go-version
GH_TUPLE+=	hashicorp:hcl:v1.0.0:hcl/vendor/github.com/hashicorp/hcl
GH_TUPLE+=	hashicorp:uuid:ebb0a03:hashicorpuuid/vendor/github.com/hashicorp/uuid
GH_TUPLE+=	howeyc:gopass:bf9dde6:gopass/vendor/github.com/howeyc/gopass
GH_TUPLE+=	inconshreveable:log15:v2.14:log15/vendor/github.com/inconshreveable/log15
GH_TUPLE+=	jinzhu:gorm:6ed508e:gorm/vendor/github.com/jinzhu/gorm
GH_TUPLE+=	jinzhu:inflection:0414036:inflection/vendor/github.com/jinzhu/inflection
GH_TUPLE+=	jroimartin:gocui:c055c87:gocui/vendor/github.com/jroimartin/gocui
GH_TUPLE+=	k0kubun:pp:v2.3.0:pp/vendor/github.com/k0kubun/pp
GH_TUPLE+=	knqyf263:go-cpe:659663f:gocpe/vendor/github.com/knqyf263/go-cpe
GH_TUPLE+=	knqyf263:go-deb-version:9865fe1:godebversion/vendor/github.com/knqyf263/go-deb-version
GH_TUPLE+=	knqyf263:go-rpm-version:74609b8:gorpmversion/vendor/github.com/knqyf263/go-rpm-version
GH_TUPLE+=	knqyf263:gost:920046a:gost/vendor/github.com/knqyf263/gost
GH_TUPLE+=	kotakanbe:go-cve-dictionary:9549cd3:gocvedictionary/vendor/github.com/kotakanbe/go-cve-dictionary
GH_TUPLE+=	kotakanbe:go-pingscanner:v0.1.0:gopingscanner/vendor/github.com/kotakanbe/go-pingscanner
GH_TUPLE+=	kotakanbe:goval-dictionary:v0.1.0:govaldictionary/vendor/github.com/kotakanbe/goval-dictionary
GH_TUPLE+=	kotakanbe:logrus-prefixed-formatter:928f735:logrusprefixedformatter/vendor/github.com/kotakanbe/logrus-prefixed-formatter
GH_TUPLE+=	labstack:gommon:7fd9f68:gommon/vendor/github.com/labstack/gommon
GH_TUPLE+=	lib:pq:4ded0e9:pq/vendor/github.com/lib/pq
GH_TUPLE+=	magiconair:properties:v1.8.0:properties/vendor/github.com/magiconair/properties
GH_TUPLE+=	marstr:guid:v1.1.0:guid/vendor/github.com/marstr/guid
GH_TUPLE+=	mattn:go-colorable:v0.0.9:gocolorable/vendor/github.com/mattn/go-colorable
GH_TUPLE+=	mattn:go-isatty:v0.0.4:goisatty/vendor/github.com/mattn/go-isatty
GH_TUPLE+=	mattn:go-runewidth:v0.0.3:gorunewidth/vendor/github.com/mattn/go-runewidth
GH_TUPLE+=	mattn:go-sqlite3:v1.10.0:gosqlite3/vendor/github.com/mattn/go-sqlite3
GH_TUPLE+=	mgutz:ansi:9520e82:ansi/vendor/github.com/mgutz/ansi
GH_TUPLE+=	mitchellh:go-homedir:v1.0.0:gohomedir/vendor/github.com/mitchellh/go-homedir
GH_TUPLE+=	mitchellh:mapstructure:v1.1.0:mapstructure/vendor/github.com/mitchellh/mapstructure
GH_TUPLE+=	moul:http2curl:9ac6cf4:http2curl/vendor/github.com/moul/http2curl
GH_TUPLE+=	mozqnet:go-exploitdb:48cac6d:goexploitdb/vendor/github.com/mozqnet/go-exploitdb
GH_TUPLE+=	nlopes:slack:v0.4.0:slack/vendor/github.com/nlopes/slack
GH_TUPLE+=	olekukonko:tablewriter:v0.0.1:tablewriter/vendor/github.com/olekukonko/tablewriter
GH_TUPLE+=	nsf:termbox-go:60ab7e3:termboxgo/vendor/github.com/nsf/termbox-go
GH_TUPLE+=	parnurzeal:gorequest:v0.2.15:gorequest/vendor/github.com/parnurzeal/gorequest
GH_TUPLE+=	pelletier:go-toml:v1.2.0:gotoml/vendor/github.com/pelletier/go-toml
GH_TUPLE+=	pkg:errors:v0.8.0:pkgerrors/vendor/github.com/pkg/errors
GH_TUPLE+=	rifflock:lfshook:v2.4:lfshook/vendor/github.com/rifflock/lfshook
GH_TUPLE+=	satori:go.uuid:v1.2.0:gouuid/vendor/github.com/satori/go.uuid
GH_TUPLE+=	sirupsen:logrus:44067ab:logrus/vendor/github.com/sirupsen/logrus
GH_TUPLE+=	spf13:afero:v1.1.2:afero/vendor/github.com/spf13/afero
GH_TUPLE+=	spf13:cast:v1.3.0:cast/vendor/github.com/spf13/cast
GH_TUPLE+=	spf13:jwalterweatherman:v1.0.0:jwalterweatherman/vendor/github.com/spf13/jwalterweatherman
GH_TUPLE+=	spf13:pflag:v1.0.3:pflag/vendor/github.com/spf13/pflag
GH_TUPLE+=	spf13:viper:v1.2.1:viper/vendor/github.com/spf13/viper
GH_TUPLE+=	valyala:bytebufferpool:v1.0.0:bytebufferpool/vendor/github.com/valyala/bytebufferpool
GH_TUPLE+=	valyala:fasttemplate:dcecefd:fasttemplate/vendor/github.com/valyala/fasttemplate
GH_TUPLE+=	ymomoi:goval-parser:0a0be1d:govalparser/vendor/github.com/ymomoi/goval-parser

GO_BUILDFLAGS=	-ldflags "-X main.version=${PORTVERSION}"

PLIST_FILES=	bin/${PORTNAME} \
		"@sample ${ETCDIR}/config.toml.sample"

post-patch:
	@${REINPLACE_CMD} -e 's|Sirupsen|sirupsen|' \
		${WRKSRC}/vendor/github.com/rifflock/lfshook/lfshook.go
	@${REINPLACE_CMD} -e 's|"gopkg.in/cheggaaa/pb.v2/termutil"|"github.com/cheggaaa/pb/termutil"|' \
		${WRKSRC}/vendor/github.com/cheggaaa/pb/pb.go
	@${REINPLACE_CMD} -e 's|%%ETCDIR%%|${ETCDIR}|' \
		${WRKSRC}/commands/configtest.go \
		${WRKSRC}/commands/report.go \
		${WRKSRC}/commands/scan.go
	@${REINPLACE_CMD} -e 's|gopkg.in/mattn/go-runewidth.v0|github.com/mattn/go-runewidth|' \
		${WRKSRC}/vendor/github.com/cheggaaa/pb/util.go
	@${REINPLACE_CMD} -e 's|gopkg.in/mattn/go-colorable.v0|github.com/mattn/go-colorable|' \
		${WRKSRC}/vendor/github.com/cheggaaa/pb/pb.go
	@${REINPLACE_CMD} -e 's|gopkg.in/mattn/go-isatty.v0|github.com/mattn/go-isatty|' \
		${WRKSRC}/vendor/github.com/cheggaaa/pb/pb.go
	@${REINPLACE_CMD} -e 's|gopkg.in/fatih/color.v1|github.com/fatih/color|' \
		${WRKSRC}/vendor/github.com/cheggaaa/pb/template.go

post-install:
	${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${FILESDIR}/config.toml.sample ${STAGEDIR}${ETCDIR}

.include <bsd.port.mk>
