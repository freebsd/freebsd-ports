# $FreeBSD$

PORTNAME=	grafana3
PORTVERSION=	3.0.4
DISTVERSIONPREFIX=	v
CATEGORIES=	www

MAINTAINER=	john@pcbsd.org
COMMENT=	Dashboard and graph editor for Graphite, InfluxDB & OpenTSDB

LICENSE=	APACHE20

BUILD_DEPENDS=	${LOCALBASE}/bin/go:lang/go

ONLY_FOR_ARCHS=	i386 amd64

USE_RC_SUBR=	grafana3

USES=	compiler

USE_GITHUB=	yes

GH_ACCOUNT=	grafana BurntSushi:toml Unknwon:com aws:aws_sdk_go \
	bmizerany:assert bradfitz:gomemcache codegangsta:cli \
	davecgh:go_spew fatih:color franela:goreq go-ini:ini go-ldap:ldap \
	go-macaron:binding,gzip,inject,session go-sql-driver:mysql \
	go-stack:stack go-xorm:core,xorm gorilla:websocket gosimple:slug \
	hashicorp:go_version inconshreveable:log15 jmespath:go_jmespath \
	jtolds:gls klauspost:compress,cpuid,crc32 kr:pretty,text lib:pq \
	mattn:go_colorable,go_isatty,go_sqlite3 rainycape:unidecode \
	smartystreets:goconvey streadway:amqp golang:net,oauth2,sys \
	go-asn1-ber:asn1_ber go-bufio:bufio go-macaron:macaron \
	go-redis:redis jhixson74:grafana_public

GH_PROJECT=	grafana toml:toml com:com aws-sdk-go:aws_sdk_go \
	assert:assert gomemcache:gomemcache cli:cli go-spew:go_spew \
	color:color goreq:goreq ini:ini ldap:ldap binding:binding \
	gzip:gzip inject:inject session:session mysql:mysql stack:stack \
	core:core xorm:xorm websocket:websocket slug:slug \
	go-version:go_version log15:log15 go-jmespath:go_jmespath gls:gls \
	compress:compress cpuid:cpuid crc32:crc32 pretty:pretty text:text \
	pq:pq go-colorable:go_colorable go-isatty:go_isatty \
	go-sqlite3:go_sqlite3 unidecode:unidecode goconvey:goconvey \
	amqp:amqp net:net oauth2:oauth2 sys:sys asn1-ber:asn1_ber \
	bufio:bufio macaron:macaron redis:redis grafana_public:grafana_public

GH_TAGNAME=	0daadc9 v0.2.0:toml v1:com v1.1.36:aws_sdk_go \
	release.r60:assert release.r60:gomemcache v1.17.0:cli \
	5215b55:go_spew v0.1:color fc08df6:goreq v1.12.0:ini v2.3.0:ldap \
	bd00823:binding cad1c65:gzip c5ab7bf:inject 66031fc:session \
	v1.2:mysql v1.5.2:stack v0.5.3:core v0.5.3:xorm v1.0.0:websocket \
	v1.0:slug 0181db4:go_version v2.11:log15  0b12d6b:go_jmespath \
	v4.2.0:gls v1.0:compress v1.0:cpuid v1.0:crc32 add1dbc:pretty \
	7cafcd8:text e2402a7:pq v0.0.5:go_colorable v0.0.1:go_isatty \
	v1.1.0:go_sqlite3 cb7f23e:unidecode c53abc9:goconvey 2e25825:amqp \
	bc3663d:net 65a8d08:oauth2 62bee03:sys v1:asn1_ber v1:bufio \
	v1:macaron v2:redis v3.0.4:grafana_public

GRAFANA_USER?=	grafana
GRAFANA_GROUP?=	grafana

USERS=	${GRAFANA_USER}
GROUPS=	${GRAFANA_GROUP}

GRAFANAHOMEDIR= ${PREFIX}/share/grafana/
GRAFANADATADIR= /var/db/${PORTNAME}/
GRAFANALOGDIR=  /var/log/${PORTNAME}/
GRAFANAPIDDIR=  /var/run/${PORTNAME}/
GRAFANAPLUGINDIR= /var/db/${PORTNAME}/plugins
GRAFANADASHBOARDDIR= /var/db/${PORTNAME}/dashboards

SUB_FILES=  grafana3 grafana3.conf
SUB_LIST+=  GRAFANA_USER=${GRAFANA_USER} \
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
	NOTICE.md package.json packaging pkg public README.md symlink_git_hooks.sh \
	tasks test.sh tests trigger_grafana_packer.sh tsconfig.json \
	tsd.json tslint.json vendor
	@${MV} ${WRKSRC}/${src} \
		${WRKSRC}/src/github.com/grafana/grafana
.endfor
	@${MKDIR} ${WRKSRC}/src/github.com/BurntSushi
	@${MKDIR} ${WRKSRC}/src/github.com/Unknwon
	@${MKDIR} ${WRKSRC}/src/github.com/aws
	@${MKDIR} ${WRKSRC}/src/github.com/bmizerany
	@${MKDIR} ${WRKSRC}/src/github.com/bradfitz
	@${MKDIR} ${WRKSRC}/src/github.com/codegangsta
	@${MKDIR} ${WRKSRC}/src/github.com/davecgh
	@${MKDIR} ${WRKSRC}/src/github.com/fatih
	@${MKDIR} ${WRKSRC}/src/github.com/franela
	@${MKDIR} ${WRKSRC}/src/github.com/go-ini
	@${MKDIR} ${WRKSRC}/src/github.com/go-ldap
	@${MKDIR} ${WRKSRC}/src/github.com/go-macaron
	@${MKDIR} ${WRKSRC}/src/github.com/go-sql-driver
	@${MKDIR} ${WRKSRC}/src/github.com/go-stack
	@${MKDIR} ${WRKSRC}/src/github.com/go-xorm
	@${MKDIR} ${WRKSRC}/src/github.com/gorilla
	@${MKDIR} ${WRKSRC}/src/github.com/gosimple
	@${MKDIR} ${WRKSRC}/src/github.com/hashicorp
	@${MKDIR} ${WRKSRC}/src/github.com/inconshreveable
	@${MKDIR} ${WRKSRC}/src/github.com/jmespath
	@${MKDIR} ${WRKSRC}/src/github.com/jtolds
	@${MKDIR} ${WRKSRC}/src/github.com/klauspost
	@${MKDIR} ${WRKSRC}/src/github.com/kr
	@${MKDIR} ${WRKSRC}/src/github.com/lib
	@${MKDIR} ${WRKSRC}/src/github.com/mattn
	@${MKDIR} ${WRKSRC}/src/github.com/rainycape
	@${MKDIR} ${WRKSRC}/src/github.com/smartystreets
	@${MKDIR} ${WRKSRC}/src/github.com/streadway
	@${MKDIR} ${WRKSRC}/src/golang.org/x
	@${MKDIR} ${WRKSRC}/src/gopkg.in/asn1-ber.v1
	@${MKDIR} ${WRKSRC}/src/gopkg.in/bufio.v1
	@${MKDIR} ${WRKSRC}/src/gopkg.in/ini.v1
	@${MKDIR} ${WRKSRC}/src/gopkg.in/macaron.v1
	@${MKDIR} ${WRKSRC}/src/gopkg.in/redis.v2
	@${MV} ${WRKSRC_toml} \
		${WRKSRC}/src/github.com/BurntSushi/toml
	@${MV} ${WRKSRC_com} \
		${WRKSRC}/src/github.com/Unknwon/com
	@${MV} ${WRKSRC_aws_sdk_go} \
		${WRKSRC}/src/github.com/aws/aws-sdk-go
	@${MV} ${WRKSRC_assert} \
		${WRKSRC}/src/github.com/bmizerany/assert
	@${MV} ${WRKSRC_gomemcache} \
		${WRKSRC}/src/github.com/bradfitz/gomemcache
	@${MV} ${WRKSRC_cli} \
		${WRKSRC}/src/github.com/codegangsta/cli
	@${MV} ${WRKSRC_go_spew} \
		${WRKSRC}/src/github.com/davecgh/go-spew
	@${MV} ${WRKSRC_color} \
		${WRKSRC}/src/github.com/fatih/color
	@${MV} ${WRKSRC_goreq} \
		${WRKSRC}/src/github.com/franela/goreq
	@${MV} ${WRKSRC_ldap} \
		${WRKSRC}/src/github.com/go-ldap/ldap
	@${MV} ${WRKSRC_binding} \
		${WRKSRC}/src/github.com/go-macaron/binding
	@${MV} ${WRKSRC_gzip} \
		${WRKSRC}/src/github.com/go-macaron/gzip
	@${MV} ${WRKSRC_inject} \
		${WRKSRC}/src/github.com/go-macaron/inject
	@${MV} ${WRKSRC_session} \
		${WRKSRC}/src/github.com/go-macaron/session
	@${MV} ${WRKSRC_mysql} \
		${WRKSRC}/src/github.com/go-sql-driver/mysql
	@${MV} ${WRKSRC_stack} \
		${WRKSRC}/src/github.com/go-stack/stack
	@${MV} ${WRKSRC_core} \
		${WRKSRC}/src/github.com/go-xorm/core
	@${MV} ${WRKSRC_xorm} \
		${WRKSRC}/src/github.com/go-xorm/xorm
	@${MV} ${WRKSRC_websocket} \
		${WRKSRC}/src/github.com/gorilla/websocket
	@${MV} ${WRKSRC_slug} \
		${WRKSRC}/src/github.com/gosimple/slug
	@${MV} ${WRKSRC_go_version} \
		${WRKSRC}/src/github.com/hashicorp/go-version
	@${MV} ${WRKSRC_log15} \
		${WRKSRC}/src/github.com/inconshreveable/log15
	@${MV} ${WRKSRC_go_jmespath} \
		${WRKSRC}/src/github.com/jmespath/go-jmespath
	@${MV} ${WRKSRC_gls} \
		${WRKSRC}/src/github.com/jtolds/gls
	@${MV} ${WRKSRC_compress} \
		${WRKSRC}/src/github.com/klauspost/compress
	@${MV} ${WRKSRC_cpuid} \
		${WRKSRC}/src/github.com/klauspost/cpuid
	@${MV} ${WRKSRC_crc32} \
		${WRKSRC}/src/github.com/klauspost/crc32
	@${MV} ${WRKSRC_pretty} \
		${WRKSRC}/src/github.com/kr/pretty
	@${MV} ${WRKSRC_text} \
		${WRKSRC}/src/github.com/kr/text
	@${MV} ${WRKSRC_pq} \
		${WRKSRC}/src/github.com/lib/pq
	@${MV} ${WRKSRC_go_colorable} \
		${WRKSRC}/src/github.com/mattn/go-colorable
	@${MV} ${WRKSRC_go_isatty} \
		${WRKSRC}/src/github.com/mattn/go-isatty
	@${MV} ${WRKSRC_go_sqlite3} \
		${WRKSRC}/src/github.com/mattn/go-sqlite3
	@${MV} ${WRKSRC_unidecode} \
		${WRKSRC}/src/github.com/rainycape/unidecode
	@${MV} ${WRKSRC_goconvey} \
		${WRKSRC}/src/github.com/smartystreets/goconvey
	@${MV} ${WRKSRC_amqp} \
		${WRKSRC}/src/github.com/streadway/amqp
	@${MV} ${WRKSRC_net} \
		${WRKSRC}/src/golang.org/x/net
	@${MV} ${WRKSRC_oauth2} \
		${WRKSRC}/src/golang.org/x/oauth2
	@${MV} ${WRKSRC_sys} \
		${WRKSRC}/src/golang.org/x/sys
	@${MV} ${WRKSRC_asn1_ber} \
		${WRKSRC}/src/gopkg.in/asn1-ber.v1
	@${MV} ${WRKSRC_bufio} \
		${WRKSRC}/src/gopkg.in/bufio.v1
	@${MV} ${WRKSRC_ini} \
		${WRKSRC}/src/gopkg.in/ini.v1
	@${MV} ${WRKSRC_macaron} \
		${WRKSRC}/src/gopkg.in/macaron.v1
	@${MV} ${WRKSRC_redis} \
		${WRKSRC}/src/gopkg.in/redis.v2

	${RM} -rf ${WRKSRC}/src/github.com/grafana/grafana/public
	${MV} ${WRKSRC_grafana_public} ${WRKSRC}/src/github.com/grafana/grafana/public
	${MV} ${WRKSRC}/src/github.com/grafana/grafana/public/public_gen \
		${WRKSRC}/src/github.com/grafana/grafana/public_gen

do-build:
	cd ${WRKSRC}/src/github.com/${GH_ACCOUNT}/grafana; \
		${SETENV} ${BUILD_ENV} GOPATH=${WRKSRC} go run build.go build

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/github.com/grafana/grafana/bin/grafana-server \
		${STAGEDIR}${PREFIX}/bin/grafana-server
	cd ${WRKSRC}/src/github.com/grafana/grafana && \
		${COPYTREE_SHARE} public ${STAGEDIR}${PREFIX}/share/grafana
	cd ${WRKSRC}/src/github.com/grafana/grafana && \
		${COPYTREE_SHARE} public_gen ${STAGEDIR}${PREFIX}/share/grafana
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
