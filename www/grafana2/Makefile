# $FreeBSD$

PORTNAME=	grafana2
PORTVERSION=	2.6.0
PORTREVISION=	1
DISTVERSIONPREFIX=	v
CATEGORIES=	www

MAINTAINER=	thomas@bartelmess.io
COMMENT=	Dashboard and graph editor for Graphite, InfluxDB & OpenTSDB

LICENSE=	APACHE20

BUILD_DEPENDS=	${LOCALBASE}/bin/go:lang/go

ONLY_FOR_ARCHS=	i386 amd64

USE_RC_SUBR=	grafana2

USES=	compiler

USE_GITHUB=	yes
GH_ACCOUNT=	grafana rainycape:unidecode aws:aws_sdk_go \
	Unknwon:macaron,com jtolds:gls streadway:amqp mattn:go_sqlite3 \
	davecgh:go_spew golang:net,oauth2 smartystreets:goconvey \
	jmespath:go_jmespath go-bufio:bufio BurntSushi:toml gosimple:slug \
	go-sql-driver:mysql macaron-contrib:session,binding lib:pq \
	go-ldap:ldap go-redis:redis go-ini:ini go-xorm:core,xorm \
	go-asn1-ber:asn1_ber
GH_PROJECT=	grafana mysql:mysql aws-sdk-go:aws_sdk_go ini:ini \
	session:session gls:gls core:core bufio:bufio net:net \
	go-sqlite3:go_sqlite3 go-jmespath:go_jmespath slug:slug xorm:xorm \
	amqp:amqp redis:redis macaron:macaron toml:toml go-spew:go_spew \
	goconvey:goconvey asn1-ber:asn1_ber pq:pq binding:binding \
	unidecode:unidecode ldap:ldap com:com oauth2:oauth2
GH_TAGNAME=	\
	v1.2-26-g9543750:mysql 972f0c5:net v1.0.0:aws_sdk_go \
	v0-16-g1772191:ini 31e841d:session f1ac7f4:gls c58fcf0:oauth2 \
	v1:bufio go1.0-cutoff-13-g19eeca3:pq v0.1.0-21-g056c9bc:toml \
	8d25846:slug v0.4.2-58-ge2889e5:xorm 0.2.2:go_jmespath \
	150b7f2:amqp v2.3.2:redis 93de4f3:macaron e28cd44:go_sqlite3 \
	d9bcf40:com 1.5.0-356-gfbc0a1c:goconvey v1:asn1_ber \
	0fbe4b9:binding 836ef0a:unidecode v1-19-g83e6542:ldap \
	2df1748:go_spew be6e7ac:core

GRAFANA_USER?=	grafana
GRAFANA_GROUP?=	grafana

USERS=	${GRAFANA_USER}
GROUPS=	${GRAFANA_GROUP}

GRAFANAHOMEDIR=	${PREFIX}/share/grafana/
GRAFANADATADIR=	/var/db/${PORTNAME}/
GRAFANALOGDIR=	/var/log/${PORTNAME}/
GRAFANAPIDDIR=	/var/run/${PORTNAME}/

SUB_FILES=	grafana2 grafana2.conf
SUB_LIST+=	GRAFANA_USER=${GRAFANA_USER} \
	GRAFANA_GROUP=${GRAFANA_GROUP} \
	GRAFANADATADIR=${GRAFANADATADIR} \
	GRAFANALOGDIR=${GRAFANALOGDIR} \
	GRAFANAPIDDIR=${GRAFANAPIDDIR} \
	GRAFANAHOMEDIR=${GRAFANAHOMEDIR}

PLIST_SUB+=	GRAFANAHOMEDIR=${GRAFANAHOMEDIR}

MASTER_SITES+=	http://files.bartelmess.io/public/:static_assets
DISTFILES+=	grafana-static-${PORTVERSION}.tar.gz:static_assets

post-extract:
	@${MKDIR} ${WRKSRC}/src/github.com/${GH_ACCOUNT}/grafana
.for src in .bra.toml .jscs.json CHANGELOG.md Gruntfile.js README.md build.go docker main.go pkg tasks \
	.gitignore .jsfmtrc CONTRIBUTING.md LICENSE.md appveyor.yml circle.yml docs package.json public tests \
	.hooks .jshintrc Godeps NOTICE.md benchmarks conf latest.json packaging vendor
	@${MV} ${WRKSRC}/${src} \
	${WRKSRC}/src/github.com/${GH_ACCOUNT}/grafana
.endfor
	@${MKDIR} ${WRKSRC}/src/github.com/go-sql-driver
	@${MKDIR} ${WRKSRC}/src/github.com/aws
	@${MKDIR} ${WRKSRC}/src/gopkg.in
	@${MKDIR} ${WRKSRC}/src/github.com/macaron-contrib
	@${MKDIR} ${WRKSRC}/src/github.com/jtolds
	@${MKDIR} ${WRKSRC}/src/github.com/go-xorm
	@${MKDIR} ${WRKSRC}/src/gopkg.in
	@${MKDIR} ${WRKSRC}/src/github.com/mattn
	@${MKDIR} ${WRKSRC}/src/github.com/jmespath
	@${MKDIR} ${WRKSRC}/src/golang.org/x
	@${MKDIR} ${WRKSRC}/src/github.com/gosimple
	@${MKDIR} ${WRKSRC}/src/github.com/smartystreets
	@${MKDIR} ${WRKSRC}/src/github.com/davecgh
	@${MKDIR} ${WRKSRC}/src/github.com/streadway
	@${MKDIR} ${WRKSRC}/src/golang.org/x
	@${MKDIR} ${WRKSRC}/src/gopkg.in
	@${MKDIR} ${WRKSRC}/src/github.com/Unknwon
	@${MKDIR} ${WRKSRC}/src/github.com/macaron-contrib
	@${MKDIR} ${WRKSRC}/src/github.com/go-xorm
	@${MKDIR} ${WRKSRC}/src/github.com/Unknwon
	@${MKDIR} ${WRKSRC}/src/gopkg.in
	@${MKDIR} ${WRKSRC}/src/github.com/BurntSushi
	@${MKDIR} ${WRKSRC}/src/github.com/rainycape
	@${MKDIR} ${WRKSRC}/src/github.com/go-ldap
	@${MKDIR} ${WRKSRC}/src/github.com/lib

	@${MV} ${WRKSRC_mysql} ${WRKSRC}/src/github.com/go-sql-driver/mysql
	@${MV} ${WRKSRC_aws_sdk_go} ${WRKSRC}/src/github.com/aws/aws-sdk-go
	@${MV} ${WRKSRC_ini} ${WRKSRC}/src/gopkg.in/ini.v1
	@${MV} ${WRKSRC_session} ${WRKSRC}/src/github.com/macaron-contrib/session
	@${MV} ${WRKSRC_gls} ${WRKSRC}/src/github.com/jtolds/gls
	@${MV} ${WRKSRC_core} ${WRKSRC}/src/github.com/go-xorm/core
	@${MV} ${WRKSRC_bufio} ${WRKSRC}/src/gopkg.in/bufio.v1
	@${MV} ${WRKSRC_go_sqlite3} ${WRKSRC}/src/github.com/mattn/go-sqlite3
	@${MV} ${WRKSRC_go_jmespath} ${WRKSRC}/src/github.com/jmespath/go-jmespath
	@${MV} ${WRKSRC_net} ${WRKSRC}/src/golang.org/x/net
	@${MV} ${WRKSRC_slug} ${WRKSRC}/src/github.com/gosimple/slug
	@${MV} ${WRKSRC_goconvey} ${WRKSRC}/src/github.com/smartystreets/goconvey
	@${MV} ${WRKSRC_go_spew} ${WRKSRC}/src/github.com/davecgh/go-spew
	@${MV} ${WRKSRC_amqp} ${WRKSRC}/src/github.com/streadway/amqp
	@${MV} ${WRKSRC_oauth2} ${WRKSRC}/src/golang.org/x/oauth2
	@${MV} ${WRKSRC_redis} ${WRKSRC}/src/gopkg.in/redis.v2
	@${MV} ${WRKSRC_macaron} ${WRKSRC}/src/github.com/Unknwon/macaron
	@${MV} ${WRKSRC_binding} ${WRKSRC}/src/github.com/macaron-contrib/binding
	@${MV} ${WRKSRC_xorm} ${WRKSRC}/src/github.com/go-xorm/xorm
	@${MV} ${WRKSRC_com} ${WRKSRC}/src/github.com/Unknwon/com
	@${MV} ${WRKSRC_asn1_ber} ${WRKSRC}/src/gopkg.in/asn1-ber.v1
	@${MV} ${WRKSRC_toml} ${WRKSRC}/src/github.com/BurntSushi/toml
	@${MV} ${WRKSRC_unidecode} ${WRKSRC}/src/github.com/rainycape/unidecode
	@${MV} ${WRKSRC_ldap} ${WRKSRC}/src/github.com/go-ldap/ldap
	@${MV} ${WRKSRC_pq} ${WRKSRC}/src/github.com/lib/pq

	${RM} -rf ${WRKSRC}/src/github.com/${GH_ACCOUNT}/grafana/public
	${MV} ${WRKDIR}/public  ${WRKSRC}/src/github.com/${GH_ACCOUNT}/grafana/
	${RM} ${WRKSRC}/src/github.com/${GH_ACCOUNT}/grafana/public/.DS_Store
	${RM} ${WRKSRC}/src/github.com/${GH_ACCOUNT}/grafana/public/app/.DS_Store
	${RM} ${WRKSRC}/src/github.com/${GH_ACCOUNT}/grafana/public/._.DS_Store
	${RM} ${WRKSRC}/src/github.com/${GH_ACCOUNT}/grafana/public/app/._.DS_Store

do-build:
	cd ${WRKSRC}/src/github.com/${GH_ACCOUNT}/grafana; \
	${SETENV} ${BUILD_ENV} GOPATH=${WRKSRC} go run build.go build

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/github.com/${GH_ACCOUNT}/grafana/bin/grafana-server \
	${STAGEDIR}${PREFIX}/bin/grafana-server
	cd ${WRKSRC}/src/github.com/${GH_ACCOUNT}/grafana && \
	${COPYTREE_SHARE} public ${STAGEDIR}${PREFIX}/share/grafana
	${MKDIR} ${STAGEDIR}${GRAFANAPIDDIR}
	${MKDIR} ${STAGEDIR}${GRAFANALOGDIR}
	${MKDIR} ${STAGEDIR}${GRAFANAHOMEDIR}
	${MKDIR} ${STAGEDIR}${GRAFANADATADIR}
	${MKDIR} ${STAGEDIR}${GRAFANAHOMEDIR}/conf
	${MKDIR} ${STAGEDIR}${GRAFANAHOMEDIR}/data
	${MKDIR} ${STAGEDIR}${GRAFANAHOMEDIR}/data/log
	${INSTALL_DATA} ${WRKSRC}/src/github.com/${GH_ACCOUNT}/grafana/conf/defaults.ini \
	${STAGEDIR}${GRAFANAHOMEDIR}/conf/defaults.ini
	${INSTALL_DATA} ${WRKDIR}/grafana2.conf ${STAGEDIR}${PREFIX}/etc/grafana2.conf.sample

.include <bsd.port.pre.mk>

# golang assumes that if clang is in use, it is called "clang" and not "cc". If
# it's called "cc", go fails.
.if ${COMPILER_TYPE} == clang
BUILD_ENV=	CC=clang
.endif

.include <bsd.port.post.mk>
