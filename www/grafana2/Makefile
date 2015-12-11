# $FreeBSD$

PORTNAME=	grafana2
PORTVERSION=	2.5.0
DISTVERSIONPREFIX=	v
CATEGORIES=	www

MAINTAINER=	thomas@bartelmess.io
COMMENT=	Dashboard and graph editor for Graphite, InfluxDB & OpenTSDB

LICENSE=	APACHE20

BUILD_DEPENDS=	${LOCALBASE}/bin/go:${PORTSDIR}/lang/go

ONLY_FOR_ARCHS=	i386 amd64

USE_RC_SUBR=	grafana2

USES=	compiler

USE_GITHUB=	yes
GH_ACCOUNT=	grafana rainycape:unidecode go-redis:redis \
	go-sql-driver:mysql go-bufio:bufio lib:pq smartystreets:goconvey \
	gosimple:slug go-xorm:xorm,core vaughan0:go_ini go-ini:ini \
	jtolds:gls streadway:amqp golang:net,oauth2 \
	macaron-contrib:session,binding go-asn1-ber:asn1_ber \
	Unknwon:com,macaron mattn:go_sqlite3 BurntSushi:toml go-ldap:ldap \
	aws:aws_sdk_go davecgh:go_spew
GH_PROJECT=	grafana go-spew:go_spew mysql:mysql \
	aws-sdk-go:aws_sdk_go goconvey:goconvey asn1-ber:asn1_ber \
	amqp:amqp xorm:xorm toml:toml core:core session:session \
	go-sqlite3:go_sqlite3 com:com macaron:macaron ldap:ldap \
	bufio:bufio pq:pq ini:ini net:net go-ini:go_ini \
	unidecode:unidecode redis:redis slug:slug gls:gls binding:binding \
	oauth2:oauth2
GH_TAGNAME=	${DISTVERSIONPREFIX}${PORTVERSION} \
	v1.2-26-g9543750:mysql e28cd44:go_sqlite3 \
	1.5.0-356-gfbc0a1c:goconvey 150b7f2:amqp v0.4.2-58-ge2889e5:xorm \
	v0.1.0-21-g056c9bc:toml go1.0-cutoff-13-g19eeca3:pq \
	31e841d:session d9bcf40:com 93de4f3:macaron v1-19-g83e6542:ldap \
	v1:bufio 2df1748:go_spew be6e7ac:core v0-16-g1772191:ini \
	972f0c5:net v1:asn1_ber v0.9.16-3-g4944a94:aws_sdk_go v2.3.2:redis \
	836ef0a:unidecode 8d25846:slug f1ac7f4:gls a98ad7e:go_ini \
	0fbe4b9:binding c58fcf0:oauth2

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

.include <bsd.port.options.mk>

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
	${MKDIR} ${WRKSRC}/src/github.com/davecgh
	${MKDIR} ${WRKSRC}/src/gopkg.in
	${MKDIR} ${WRKSRC}/src/github.com/go-sql-driver
	${MKDIR} ${WRKSRC}/src/github.com/aws
	${MKDIR} ${WRKSRC}/src/github.com/smartystreets
	${MKDIR} ${WRKSRC}/src/gopkg.in
	${MKDIR} ${WRKSRC}/src/github.com/streadway
	${MKDIR} ${WRKSRC}/src/github.com/go-xorm
	${MKDIR} ${WRKSRC}/src/github.com/BurntSushi
	${MKDIR} ${WRKSRC}/src/github.com/go-xorm
	${MKDIR} ${WRKSRC}/src/github.com/macaron-contrib
	${MKDIR} ${WRKSRC}/src/github.com/Unknwon
	${MKDIR} ${WRKSRC}/src/github.com/Unknwon
	${MKDIR} ${WRKSRC}/src/github.com/go-ldap
	${MKDIR} ${WRKSRC}/src/gopkg.in
	${MKDIR} ${WRKSRC}/src/github.com/lib
	${MKDIR} ${WRKSRC}/src/golang.org/x
	${MKDIR} ${WRKSRC}/src/github.com/mattn
	${MKDIR} ${WRKSRC}/src/github.com/vaughan0
	${MKDIR} ${WRKSRC}/src/github.com/rainycape
	${MKDIR} ${WRKSRC}/src/gopkg.in
	${MKDIR} ${WRKSRC}/src/github.com/gosimple
	${MKDIR} ${WRKSRC}/src/github.com/jtolds
	${MKDIR} ${WRKSRC}/src/github.com/macaron-contrib
	${MKDIR} ${WRKSRC}/src/golang.org/x

	${MV} ${WRKSRC_go_spew} ${WRKSRC}/src/github.com/davecgh/go-spew
	${MV} ${WRKSRC_ini} ${WRKSRC}/src/gopkg.in/ini.v1
	${MV} ${WRKSRC_mysql} ${WRKSRC}/src/github.com/go-sql-driver/mysql
	${MV} ${WRKSRC_aws_sdk_go} ${WRKSRC}/src/github.com/aws/aws-sdk-go
	${MV} ${WRKSRC_goconvey} ${WRKSRC}/src/github.com/smartystreets/goconvey
	${MV} ${WRKSRC_asn1_ber} ${WRKSRC}/src/gopkg.in/asn1-ber.v1
	${MV} ${WRKSRC_amqp} ${WRKSRC}/src/github.com/streadway/amqp
	${MV} ${WRKSRC_xorm} ${WRKSRC}/src/github.com/go-xorm/xorm
	${MV} ${WRKSRC_toml} ${WRKSRC}/src/github.com/BurntSushi/toml
	${MV} ${WRKSRC_core} ${WRKSRC}/src/github.com/go-xorm/core
	${MV} ${WRKSRC_session} ${WRKSRC}/src/github.com/macaron-contrib/session
	${MV} ${WRKSRC_com} ${WRKSRC}/src/github.com/Unknwon/com
	${MV} ${WRKSRC_macaron} ${WRKSRC}/src/github.com/Unknwon/macaron
	${MV} ${WRKSRC_ldap} ${WRKSRC}/src/github.com/go-ldap/ldap
	${MV} ${WRKSRC_bufio} ${WRKSRC}/src/gopkg.in/bufio.v1
	${MV} ${WRKSRC_pq} ${WRKSRC}/src/github.com/lib/pq
	${MV} ${WRKSRC_net} ${WRKSRC}/src/golang.org/x/net
	${MV} ${WRKSRC_go_sqlite3} ${WRKSRC}/src/github.com/mattn/go-sqlite3
	${MV} ${WRKSRC_go_ini} ${WRKSRC}/src/github.com/vaughan0/go-ini
	${MV} ${WRKSRC_unidecode} ${WRKSRC}/src/github.com/rainycape/unidecode
	${MV} ${WRKSRC_redis} ${WRKSRC}/src/gopkg.in/redis.v2
	${MV} ${WRKSRC_slug} ${WRKSRC}/src/github.com/gosimple/slug
	${MV} ${WRKSRC_gls} ${WRKSRC}/src/github.com/jtolds/gls
	${MV} ${WRKSRC_binding} ${WRKSRC}/src/github.com/macaron-contrib/binding
	${MV} ${WRKSRC_oauth2} ${WRKSRC}/src/golang.org/x/oauth2
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
	${INSTALL_DATA} ${WRKDIR}/grafana2.conf ${STAGEDIR}${PREFIX}/etc/grafana2.conf

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} < 900044 && ${ARCH} == i386
BROKEN=	Does not build
.endif

# golang assumes that if clang is in use, it is called "clang" and not "cc". If
# it's called "cc", go fails.
.if ${COMPILER_TYPE} == clang
BUILD_ENV=	CC=clang
.endif

.include <bsd.port.post.mk>
