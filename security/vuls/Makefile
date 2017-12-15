# $FreeBSD$

PORTNAME=	vuls
DISTVERSIONPREFIX=	v
DISTVERSION=		0.4.2-2
DISTVERSIONSUFFIX=	-g383220f
CATEGORIES=	security

MAINTAINER=	iscandr@gmail.com
COMMENT=	Agentless vulnerability scanner

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${LOCALBASE}/bin/go-cve-dictionary:security/go-cve-dictionary

USES=	go:1.7.1+

USE_GITHUB=	yes
GH_ACCOUNT=	future-architect
GH_SUBDIR=	src/github.com/${GH_ACCOUNT_DEFAULT}/${PORTNAME}

GH_TUPLE+=	Azure:azure-sdk-for-go:2629e2d:azuresdkforgo/src/github.com/Azure/azure-sdk-for-go
GH_TUPLE+=	Azure:azure-storage-go:12ccaad:azurestoragego/src/github.com/Azure/azure-storage-go
GH_TUPLE+=	Azure:go-autorest:v8.1.0:azuregoautorest/src/github.com/Azure/go-autorest
GH_TUPLE+=	BurntSushi:toml:2ceedfe:toml/src/github.com/BurntSushi/toml
GH_TUPLE+=	GeertJohan:go.incremental:1172aab:goincremental/src/github.com/GeertJohan/go.incremental
GH_TUPLE+=	GeertJohan:go.rice:c02ca9a:gorice/src/github.com/GeertJohan/go.rice
GH_TUPLE+=	GoogleCloudPlatform:google-cloud-go:v0.9.0:googlecloudgo/src/cloud.google.com/go
GH_TUPLE+=	MichaelTJones:walk:4748e29:mtjwalk/src/github.com/MichaelTJones/walk
GH_TUPLE+=	PuerkitoBio:goquery:v1.1.0:goquery/src/github.com/PuerkitoBio/goquery
GH_TUPLE+=	VividCortex:ewma:v1.0:ewma/src/gopkg.in/VividCortex/ewma.v1
GH_TUPLE+=	airbrake:gobrake:v2.0.9:gobrake/src/gopkg.in/airbrake/gobrake.v2
GH_TUPLE+=	akavel:rsrc:ba14da1:rsrc/src/github.com/akavel/rsrc
GH_TUPLE+=	andybalholm:cascadia:349dd02:cascadia/src/github.com/andybalholm/cascadia
GH_TUPLE+=	asaskevich:govalidator:v6:govalidator/src/github.com/asaskevich/govalidator
GH_TUPLE+=	aws:aws-sdk-go:v1.10.3:awssdkgo/src/github.com/aws/aws-sdk-go
GH_TUPLE+=	boltdb:bolt:v1.3.0:bolt/src/github.com/boltdb/bolt
GH_TUPLE+=	camlistore:go4:034d17a:go4syncutil/src/go4.org
GH_TUPLE+=	cenkalti:backoff:v1.0.0:backoff/src/github.com/cenkalti/backoff
GH_TUPLE+=	cheggaaa:pb:v1.0.17:pb/src/github.com/cheggaaa/pb
GH_TUPLE+=	daaku:go.zipexe:a5fe243:gozipexe/src/github.com/daaku/go.zipexe
GH_TUPLE+=	davecgh:go-spew:346938d:gospew/src/github.com/davecgh/go-spew
GH_TUPLE+=	denisenkom:go-mssqldb:a8b933e:gomssqldb/src/github.com/denisenkom/go-mssqldb
GH_TUPLE+=	dgrijalva:jwt-go:v3.0.0:jwtgo/src/github.com/dgrijalva/jwt-go
GH_TUPLE+=	facebookgo:clock:600d898:clock/src/github.com/facebookgo/clock
GH_TUPLE+=	facebookgo:grace:4afe952:grace/src/github.com/facebookgo/grace
GH_TUPLE+=	facebookgo:httpdown:a3b1354:httpdown/src/github.com/facebookgo/httpdown
GH_TUPLE+=	facebookgo:stats:1b76add:stats/src/github.com/facebookgo/stats
GH_TUPLE+=	fatih:color:v1.5.0:colorv1/src/gopkg.in/fatih/color.v1
GH_TUPLE+=	gemnasium:logrus-airbrake-hook:v2.1.2:logrusairbrakehook/src/gopkg.in/gemnasium/logrus-airbrake-hook.v2
GH_TUPLE+=	go-godo:godo:v1.4.5:gogodov1/src/gopkg.in/godo.v1
GH_TUPLE+=	go-godo:godo:v2.0.9:gogodo/src/gopkg.in/godo.v2
GH_TUPLE+=	go-redis:redis:v6.5.0:redis/src/github.com/go-redis/redis
GH_TUPLE+=	go-sql-driver:mysql:v1.3:mysql/src/github.com/go-sql-driver/mysql
GH_TUPLE+=	gokyle:fswatch:1dbdf83:walk/src/github.com/gokyle/fswatch
GH_TUPLE+=	golang:crypto:ed779e1:crypto/src/golang.org/x/crypto
GH_TUPLE+=	golang:debug:e48e171:debug/src/golang.org/x/debug
GH_TUPLE+=	golang:geo:f65fe01:geo/src/github.com/golang/geo
GH_TUPLE+=	golang:glog:23def4e:glog/src/github.com/golang/glog
GH_TUPLE+=	golang:mock:93f6609:mock/src/github.com/golang/mock
GH_TUPLE+=	golang:net:5f8847a:golangnet/src/golang.org/x/net
GH_TUPLE+=	golang:oauth2:f047394:oauth2/src/golang.org/x/oauth2
GH_TUPLE+=	golang:protobuf:6a1fa94:protobuf/src/github.com/golang/protobuf
GH_TUPLE+=	golang:sync:f52d181:sync/src/golang.org/x/sync
GH_TUPLE+=	golang:sys:c23410a:sys/src/golang.org/x/sys
GH_TUPLE+=	golang:text:4e9ab9e:golangtext/src/golang.org/x/text
GH_TUPLE+=	golang:time:8be79e1:time/src/golang.org/x/time
GH_TUPLE+=	golang:tools:e6cb469:golangtools/src/golang.org/x/tools
GH_TUPLE+=	google:go-genproto:aa2eb68:gogenproto/src/google.golang.org/genproto
GH_TUPLE+=	google:google-api-go-client:1ba364a:googleapigoclient/src/google.golang.org/api
GH_TUPLE+=	google:subcommands:ce3d4cf:subcommands/src/github.com/google/subcommands
GH_TUPLE+=	googleapis:gax-go:84ed267:gaxgo/src/github.com/googleapis/gax-go
GH_TUPLE+=	gorilla:websocket:v1.2.0:websocket/src/github.com/gorilla/websocket
GH_TUPLE+=	gosuri:uitable:36ee7e9:uitable/src/github.com/gosuri/uitable
GH_TUPLE+=	grpc:grpc-go:v1.4.2:grpcgo/src/google.golang.org/grpc
GH_TUPLE+=	howeyc:gopass:bf9dde6:gopass/src/github.com/howeyc/gopass
GH_TUPLE+=	jessevdk:go-flags:5695738:goflags/src/github.com/jessevdk/go-flags
GH_TUPLE+=	jinzhu:gorm:eae7f6b:gorm/src/github.com/jinzhu/gorm
GH_TUPLE+=	jinzhu:inflection:1c35d90:inflection/src/github.com/jinzhu/inflection
GH_TUPLE+=	jroimartin:gocui:4e9ce9a:gocui/src/github.com/jroimartin/gocui
GH_TUPLE+=	k0kubun:pp:v2.3.0:pp/src/github.com/k0kubun/pp
GH_TUPLE+=	kardianos:osext:ae77be6:osext/src/github.com/kardianos/osext
GH_TUPLE+=	klauspost:compress:v1.2.1:compress/src/github.com/klauspost/compress
GH_TUPLE+=	klauspost:cpuid:09cded8:cpuid/src/github.com/klauspost/cpuid
GH_TUPLE+=	klauspost:crc32:1bab8b3:crc32/src/github.com/klauspost/crc32
GH_TUPLE+=	knqyf263:go-deb-version:9865fe1:godebversion/src/github.com/knqyf263/go-deb-version
GH_TUPLE+=	knqyf263:go-rpm-version:74609b8:gorpmversion/src/github.com/knqyf263/go-rpm-version
GH_TUPLE+=	kotakanbe:go-cve-dictionary:a64c5fc:gocvedictionary/src/github.com/kotakanbe/go-cve-dictionary
GH_TUPLE+=	kotakanbe:go-pingscanner:v0.1.0:gopingscanner/src/github.com/kotakanbe/go-pingscanner
GH_TUPLE+=	kotakanbe:goval-dictionary:3523cc1:govaldictionary/src/github.com/kotakanbe/goval-dictionary
GH_TUPLE+=	kotakanbe:logrus-prefixed-formatter:75edb2e:logrusprefixedformatter/src/github.com/kotakanbe/logrus-prefixed-formatter
GH_TUPLE+=	labstack:echo:bc173df:echo/src/github.com/labstack/echo
GH_TUPLE+=	labstack:gommon:1121fd3:gommon/src/github.com/labstack/gommon
GH_TUPLE+=	lib:pq:8837942:pq/src/github.com/lib/pq
GH_TUPLE+=	mattn:go-colorable:v0.0.8:gocolorable/src/github.com/mattn/go-colorable
GH_TUPLE+=	mattn:go-isatty:v0.0.2:goisatty/src/github.com/mattn/go-isatty
GH_TUPLE+=	mattn:go-runewidth:97311d9:gorunewidth/src/github.com/mattn/go-runewidth
GH_TUPLE+=	mattn:go-sqlite3:v1.2.0:gosqlite3/src/github.com/mattn/go-sqlite3
GH_TUPLE+=	mgutz:ansi:9520e82:ansi/src/github.com/mgutz/ansi
GH_TUPLE+=	mgutz:goa:d673c4f:goa/src/github.com/mgutz/goa
GH_TUPLE+=	mgutz:minimist:39eb8cf:minimist/src/github.com/mgutz/minimist
GH_TUPLE+=	mgutz:str:968bf66:str/src/github.com/mgutz/str
GH_TUPLE+=	mgutz:to:00c0640:to/src/github.com/mgutz/to
GH_TUPLE+=	moul:http2curl:4e24498:http2curl/src/github.com/moul/http2curl
GH_TUPLE+=	nlopes:slack:c86337c:slack/src/github.com/nlopes/slack
GH_TUPLE+=	nozzle:throttler:d9b45f1:throttler/src/github.com/nozzle/throttler
GH_TUPLE+=	nsf:termbox-go:72800b7:termboxgo/src/github.com/nsf/termbox-go
GH_TUPLE+=	parnurzeal:gorequest:v0.2.15:gorequest/src/github.com/parnurzeal/gorequest
GH_TUPLE+=	pkg:errors:c605e28:pkgerrors/src/github.com/pkg/errors
GH_TUPLE+=	rifflock:lfshook:1.6:lfshook/src/github.com/rifflock/lfshook
GH_TUPLE+=	satori:go.uuid:5bf94b6:gouuid/src/github.com/satori/uuid
GH_TUPLE+=	shopspring:decimal:16a9418:decimal/src/github.com/shopspring/decimal
GH_TUPLE+=	sirupsen:logrus:1.0.2:logrus/src/github.com/sirupsen/logrus
GH_TUPLE+=	stretchr:testify:f6abca5:testify/src/github.com/stretchr/testify
GH_TUPLE+=	tylerb:graceful:v1.2.15:graceful/src/gopkg.in/tylerb/graceful.v1
GH_TUPLE+=	urfave:negroni:460c556:negroni/src/github.com/urfave/negroni
GH_TUPLE+=	valyala:bytebufferpool:e746df9:bytebufferpool/src/github.com/valyala/bytebufferpool
GH_TUPLE+=	valyala:fasthttp:0f5182f:fasthttp/src/github.com/valyala/fasthttp
GH_TUPLE+=	valyala:fasttemplate:dcecefd:fasttemplate/src/github.com/valyala/fasttemplate
GH_TUPLE+=	valyala:tcplisten:ceec8f9:tcplisten/src/github.com/valyala/tcplisten
GH_TUPLE+=	ymomoi:goval-parser:0a0be1d:govalparser/src/github.com/ymomoi/goval-parser

PLIST_FILES=	bin/${PORTNAME} \
		"@sample ${ETCDIR}/config.toml.sample"

post-patch:
	@${REINPLACE_CMD} -e 's|Sirupsen|sirupsen|' \
		${WRKSRC}/src/github.com/rifflock/lfshook/lfshook.go
	@${REINPLACE_CMD} -e 's|github.com/tylerb/graceful|gopkg.in/tylerb/graceful.v1|' \
		${WRKSRC}/src/github.com/labstack/echo/recipe/graceful-shutdown/graceful/server.go
	@${REINPLACE_CMD} -e 's|%%ETCDIR%%|${ETCDIR}|' \
		${WRKSRC}/commands/configtest.go \
		${WRKSRC}/commands/report.go \
		${WRKSRC}/commands/scan.go

do-build:
	@cd ${GO_WRKSRC} && \
		${SETENV} ${MAKE_ENV} ${GO_ENV} GOPATH=${WRKSRC} \
		${GO_CMD} build -v -x -ldflags "-X main.version=${PORTVERSION}" \
		-o ${WRKSRC}/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${FILESDIR}/config.toml.sample ${STAGEDIR}${ETCDIR}

.include <bsd.port.mk>
