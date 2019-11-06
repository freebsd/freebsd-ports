# $FreeBSD$

PORTNAME=	grafana
PORTVERSION=	2.6.0
DISTVERSIONPREFIX=	v
PORTREVISION=	3
CATEGORIES=	www
MASTER_SITES=	http://files.bartelmess.io/public/:static_assets
PKGNAMESUFFIX=	2
DISTFILES=	grafana-static-${PORTVERSION}.tar.gz:static_assets

MAINTAINER=	thomas@bartelmess.io
COMMENT=	Dashboard and graph editor for Graphite, InfluxDB & OpenTSDB

BROKEN=		unfetchable

LICENSE=	APACHE20

ONLY_FOR_ARCHS=	i386 amd64

USE_RC_SUBR=	grafana2

USES=	compiler go

USE_GITHUB=	yes
GH_SUBDIR=	src/github.com/${PORTNAME}/${PORTNAME}
GH_TUPLE= \
	  BurntSushi:toml:v0.1.0-21-g056c9bc:toml/src/github.com/BurntSushi/toml \
	  Unknwon:macaron:93de4f3:macaron/src/github.com/Unknwon/macaron \
	  Unknwon:com:d9bcf40:com/src/github.com/Unknwon/com \
	  davecgh:go-spew:2df1748:go_spew/src/github.com/davecgh/go-spew \
	  go-bufio:bufio:v1:bufio/src/gopkg.in/bufio.v1 \
	  macaron-contrib:binding:0fbe4b9:binding/src/github.com/macaron-contrib/binding \
	  macaron-contrib:session:31e841d:session/src/github.com/macaron-contrib/session \
	  jmespath:go-jmespath:0.2.2:go_jmespath/src/github.com/jmespath/go-jmespath \
	  lib:pq:go1.0-cutoff-13-g19eeca3:pq/src/github.com/lib/pq \
	  jtolds:gls:f1ac7f4:gls/src/github.com/jtolds/gls \
	  go-asn1-ber:asn1-ber:v1:asn1_ber/src/gopkg.in/asn1-ber.v1 \
	  go-xorm:core:be6e7ac:core/src/github.com/go-xorm/core \
	  go-xorm:xorm:v0.4.2-58-ge2889e5:xorm/src/github.com/go-xorm/xorm \
	  go-ini:ini:v0-16-g1772191:ini/src/gopkg.in/ini.v1 \
	  aws:aws-sdk-go:v1.0.0:aws_sdk_go/src/github.com/aws/aws-sdk-go \
	  mattn:go-sqlite3:e28cd44:go_sqlite3/src/github.com/mattn/go-sqlite3 \
	  go-ldap:ldap:v1-19-g83e6542:ldap/src/github.com/go-ldap/ldap \
	  go-redis:redis:v2.3.2:redis/src/gopkg.in/redis.v2 \
	  gosimple:slug:8d25846:slug/src/github.com/gosimple/slug \
	  streadway:amqp:150b7f2:amqp/src/github.com/streadway/amqp \
	  golang:oauth2:c58fcf0:oauth2/src/golang.org/x/oauth2 \
	  golang:net:972f0c5:net/src/golang.org/x/net \
	  smartystreets:goconvey:1.5.0-356-gfbc0a1c:goconvey/src/github.com/smartystreets/goconvey \
	  rainycape:unidecode:836ef0a:unidecode/src/github.com/rainycape/unidecode \
	  go-sql-driver:mysql:v1.2-26-g9543750:mysql/src/github.com/go-sql-driver/mysql

GRAFANA_USER?=	grafana
GRAFANA_GROUP?=	grafana

USERS=	${GRAFANA_USER}
GROUPS=	${GRAFANA_GROUP}

GRAFANAHOMEDIR=	${PREFIX}/share/grafana/
GRAFANADATADIR=	/var/db/${PKGBASE}/
GRAFANALOGDIR=	/var/log/${PKGBASE}/
GRAFANAPIDDIR=	/var/run/${PKGBASE}/

SUB_FILES=	grafana2 grafana2.conf
SUB_LIST+=	GRAFANA_USER=${GRAFANA_USER} \
	GRAFANA_GROUP=${GRAFANA_GROUP} \
	GRAFANADATADIR=${GRAFANADATADIR} \
	GRAFANALOGDIR=${GRAFANALOGDIR} \
	GRAFANAPIDDIR=${GRAFANAPIDDIR} \
	GRAFANAHOMEDIR=${GRAFANAHOMEDIR}

PLIST_SUB+=	GRAFANAHOMEDIR=${GRAFANAHOMEDIR}

post-extract:
	${RM} -r ${WRKSRC}/src/github.com/${PORTNAME}/${PORTNAME}/public
	${MV} ${WRKDIR}/public  ${WRKSRC}/src/github.com/${PORTNAME}/${PORTNAME}/
	${RM} ${WRKSRC}/src/github.com/${PORTNAME}/${PORTNAME}/public/.DS_Store
	${RM} ${WRKSRC}/src/github.com/${PORTNAME}/${PORTNAME}/public/app/.DS_Store
	${RM} ${WRKSRC}/src/github.com/${PORTNAME}/${PORTNAME}/public/._.DS_Store
	${RM} ${WRKSRC}/src/github.com/${PORTNAME}/${PORTNAME}/public/app/._.DS_Store

do-build:
	@cd ${WRKSRC}/src/github.com/${PORTNAME}/${PORTNAME}; \
		${SETENV} ${MAKE_ENV} ${BUILD_ENV} GOPATH=${WRKSRC} go run build.go build

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/github.com/${PORTNAME}/${PORTNAME}/bin/grafana-server \
	${STAGEDIR}${PREFIX}/bin/grafana-server
	cd ${WRKSRC}/src/github.com/${PORTNAME}/${PORTNAME} && \
	${COPYTREE_SHARE} public ${STAGEDIR}${PREFIX}/share/${PORTNAME}
	${MKDIR} ${STAGEDIR}${GRAFANAPIDDIR}
	${MKDIR} ${STAGEDIR}${GRAFANALOGDIR}
	${MKDIR} ${STAGEDIR}${GRAFANAHOMEDIR}
	${MKDIR} ${STAGEDIR}${GRAFANADATADIR}
	${MKDIR} ${STAGEDIR}${GRAFANAHOMEDIR}/conf
	${MKDIR} ${STAGEDIR}${GRAFANAHOMEDIR}/data
	${MKDIR} ${STAGEDIR}${GRAFANAHOMEDIR}/data/log
	${INSTALL_DATA} ${WRKSRC}/src/github.com/${PORTNAME}/${PORTNAME}/conf/defaults.ini \
	${STAGEDIR}${GRAFANAHOMEDIR}/conf/defaults.ini
	${INSTALL_DATA} ${WRKDIR}/grafana2.conf ${STAGEDIR}${PREFIX}/etc/grafana2.conf.sample

.include <bsd.port.pre.mk>

# golang assumes that if clang is in use, it is called "clang" and not "cc". If
# it's called "cc", go fails.
.if ${COMPILER_TYPE} == clang
BUILD_ENV=	CC=clang
.endif

.include <bsd.port.post.mk>
