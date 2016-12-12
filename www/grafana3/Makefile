# $FreeBSD$

PORTNAME=	grafana
PORTVERSION=	3.1.1
DISTVERSIONPREFIX=	v
PORTREVISION=	1
PKGNAMESUFFIX=	3
CATEGORIES=	www

MAINTAINER=	jhixson@gmail.com
COMMENT=	Dashboard and graph editor for Graphite, InfluxDB & OpenTSDB

LICENSE=	APACHE20

BUILD_DEPENDS=	${LOCALBASE}/bin/go:lang/go

ONLY_FOR_ARCHS=	i386 amd64

USE_RC_SUBR=	grafana3

USES=	compiler

USE_GITHUB=	yes

GH_TUPLE= \
	BurntSushi:toml:v0.2.0:toml/src/github.com/BurntSushi/toml                                       \
	Unknwon:com:v1:com/src/github.com/Unknwon/com                                                    \
	aws:aws-sdk-go:v1.1.36:aws_sdk_go/src/github.com/aws/aws-sdk-go                                  \
	bmizerany:assert:release.r60:assert/src/github.com/bmizerany/assert                              \
	bradfitz:gomemcache:release.r60:gomemcache/src/github.com/bradfitz/gomemcache                    \
	codegangsta:cli:v1.17.0:cli/src/github.com/codegangsta/cli                                       \
	davecgh:go-spew:5215b55:go_spew/src/github.com/davecgh/go-spew                                   \
	fatih:color:v0.1:color/src/github.com/fatih/color                                                \
	franela:goreq:fc08df6:goreq/src/github.com/franela/goreq                                         \
	go-ini:ini:v1.12.0:ini/src/gopkg.in/ini.v1                                                       \
	go-ldap:ldap:v2.3.0:ldap/src/github.com/go-ldap/ldap                                             \
	go-macaron:binding:bd00823:binding/src/github.com/go-macaron/binding                             \
	go-macaron:gzip:cad1c65:gzip/src/github.com/go-macaron/gzip                                      \
	go-macaron:inject:c5ab7bf:inject/src/github.com/go-macaron/inject                                \
	go-macaron:session:66031fc:session/src/github.com/go-macaron/session                             \
	go-sql-driver:mysql:v1.2:mysql/src/github.com/go-sql-driver/mysql                                \
	go-stack:stack:v1.5.2:stack/src/github.com/go-stack/stack                                        \
	go-xorm:core:v0.5.3:core/src/github.com/go-xorm/core                                             \
	go-xorm:xorm:v0.5.3:xorm/src/github.com/go-xorm/xorm                                             \
	gorilla:websocket:v1.0.0:websocket/src/github.com/gorilla/websocket                              \
	gosimple:slug:v1.0:slug/src/github.com/gosimple/slug                                             \
	hashicorp:go-version:0181db4:go_version/src/github.com/hashicorp/go-version                      \
	inconshreveable:log15:v2.11:log15/src/github.com/inconshreveable/log15                           \
	jmespath:go-jmespath:0b12d6b:go_jmespath/src/github.com/jmespath/go-jmespath                     \
	jtolds:gls:v4.2.0:gls/src/github.com/jtolds/gls                                                  \
	klauspost:compress:v1.0:compress/src/github.com/klauspost/compress                               \
	klauspost:cpuid:v1.0:cpuid/src/github.com/klauspost/cpuid                                        \
	klauspost:crc32:v1.0:crc32/src/github.com/klauspost/crc32                                        \
	kr:pretty:add1dbc:pretty/src/github.com/kr/pretty                                                \
	kr:text:7cafcd8:text/src/github.com/kr/text                                                      \
	lib:pq:e2402a7:pq/src/github.com/lib/pq                                                          \
	mattn:go-colorable:v0.0.5:go_colorable/src/github.com/mattn/go-colorable                         \
	mattn:go-isatty:v0.0.1:go_isatty/src/github.com/mattn/go-isatty                                  \
	mattn:go-sqlite3:v1.1.0:go_sqlite3/src/github.com/mattn/go-sqlite3                               \
	rainycape:unidecode:cb7f23e:unidecode/src/github.com/rainycape/unidecode                         \
	smartystreets:goconvey:c53abc9:goconvey/src/github.com/smartystreets/goconvey                    \
	streadway:amqp:2e25825:amqp/src/github.com/streadway/amqp                                        \
	golang:net:bc3663d:net/src/golang.org/x/net                                                      \
	golang:oauth2:65a8d08:oauth2/src/golang.org/x/oauth2                                             \
	golang:sys:62bee03:sys/src/golang.org/x/sys                                                      \
	go-asn1-ber:asn1-ber:v1:asn1_ber/src/gopkg.in/asn1-ber.v1                                       \
	go-bufio:bufio:v1:bufio/src/gopkg.in/bufio.v1                                                    \
	go-macaron:macaron:v1:macaron/src/gopkg.in/macaron.v1                                            \
	go-redis:redis:v2:redis/src/gopkg.in/redis.v2                                                    \
	jhixson74:grafana_public:${DISTVERSIONFULL}:grafana_public

GRAFANA_USER?=	grafana
GRAFANA_GROUP?=	grafana

USERS=	${GRAFANA_USER}
GROUPS=	${GRAFANA_GROUP}

GRAFANAHOMEDIR=	${PREFIX}/share/grafana/
GRAFANADATADIR=	/var/db/${PKGBASE}/
GRAFANALOGDIR=	/var/log/${PKGBASE}/
GRAFANAPIDDIR=	/var/run/${PKGBASE}/
GRAFANAPLUGINDIR=	/var/db/${PKGBASE}/plugins
GRAFANADASHBOARDDIR=	/var/db/${PKGBASE}/dashboards

SUB_FILES=	grafana3 grafana3.conf
SUB_LIST+=	GRAFANA_USER=${GRAFANA_USER} \
    GRAFANA_GROUP=${GRAFANA_GROUP} \
    GRAFANADATADIR=${GRAFANADATADIR} \
    GRAFANALOGDIR=${GRAFANALOGDIR} \
    GRAFANAPIDDIR=${GRAFANAPIDDIR} \
    GRAFANAHOMEDIR=${GRAFANAHOMEDIR} \
	GRAFANAPLUGINDIR=${GRAFANAPLUGINDIR} \
	GRAFANADASHBOARDDIR=${GRAFANADASHBOARDDIR}

PLIST_SUB+=	GRAFANAHOMEDIR=${GRAFANAHOMEDIR}

STRIP=

post-extract:
	@${MKDIR} ${WRKSRC}/src/github.com/grafana/grafana
.for src in .bowerrc .bra.toml .editorconfig .github .gitignore .hooks \
	.jscs.json .jsfmtrc .jshintrc appveyor.yml benchmarks bower.json \
	build.go CHANGELOG.md circle.yml conf docker docs emails examples \
	Godeps Gruntfile.js karma.conf.js latest.json LICENSE.md Makefile \
	NOTICE.md package.json packaging pkg README.md symlink_git_hooks.sh \
	tasks test.sh tests trigger_grafana_packer.sh tsconfig.json \
	tsd.json tslint.json vendor
	@${MV} ${WRKSRC}/${src} \
		${WRKSRC}/src/github.com/grafana/grafana
.endfor
	${RM} -r ${WRKSRC}/src/github.com/grafana/grafana/public
	${MV} ${WRKSRC_grafana_public}/public ${WRKSRC}/src/github.com/grafana/grafana/public
	${MV} ${WRKSRC_grafana_public}/public_gen ${WRKSRC}/src/github.com/grafana/grafana/public_gen
	${MV} ${WRKSRC_grafana_public}/node_modules ${WRKSRC}/src/github.com/grafana/grafana/node_modules

do-build:
	cd ${WRKSRC}/src/github.com/${GH_ACCOUNT}/grafana; \
		${SETENV} ${BUILD_ENV} GOPATH=${WRKSRC} go run build.go build

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/github.com/grafana/grafana/bin/grafana-server \
		${STAGEDIR}${PREFIX}/bin/grafana-server
	${INSTALL_PROGRAM} ${WRKSRC}/src/github.com/grafana/grafana/bin/grafana-cli \
		${STAGEDIR}${PREFIX}/bin/grafana-cli
	cd ${WRKSRC}/src/github.com/grafana/grafana && \
		${COPYTREE_SHARE} public ${STAGEDIR}${PREFIX}/share/grafana
	cd ${WRKSRC}/src/github.com/grafana/grafana && \
		${COPYTREE_SHARE} public_gen ${STAGEDIR}${PREFIX}/share/grafana
	cd ${WRKSRC}/src/github.com/grafana/grafana && \
		${COPYTREE_SHARE} node_modules ${STAGEDIR}${PREFIX}/share/grafana
	${MKDIR} ${STAGEDIR}${GRAFANAPIDDIR}
	${MKDIR} ${STAGEDIR}${GRAFANALOGDIR}
	${MKDIR} ${STAGEDIR}${GRAFANAHOMEDIR}
	${MKDIR} ${STAGEDIR}${GRAFANADATADIR}
	${MKDIR} ${STAGEDIR}${GRAFANAPLUGINDIR}
	${MKDIR} ${STAGEDIR}${GRAFANADASHBOARDDIR}
	${MKDIR} ${STAGEDIR}${GRAFANAHOMEDIR}/conf
	${MKDIR} ${STAGEDIR}${GRAFANAHOMEDIR}/data
	${MKDIR} ${STAGEDIR}${GRAFANAHOMEDIR}/data/log
	${INSTALL_DATA} ${WRKSRC}/src/github.com/grafana/grafana/conf/defaults.ini \
		${STAGEDIR}${GRAFANAHOMEDIR}/conf/defaults.ini
	${INSTALL_DATA} ${WRKDIR}/grafana3.conf ${STAGEDIR}${PREFIX}/etc/grafana3.conf.sample

.include <bsd.port.pre.mk>

.if ${COMPILER_TYPE} == clang
BUILD_ENV=	CC=clang
.endif

.include <bsd.port.post.mk>
