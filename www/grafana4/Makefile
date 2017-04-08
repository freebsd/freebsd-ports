# $FreeBSD$

PORTNAME=	grafana
PORTVERSION=	4.2.0
DISTVERSIONPREFIX=	v
CATEGORIES=	www
MASTER_SITES+=	https://s3-us-west-2.amazonaws.com/:public
PKGNAMESUFFIX=	${PORTVERSION:C/([0-9]).*/\1/1}
DISTFILES=	grafana-releases/release/grafana-${PORTVERSION}.linux-x64${EXTRACT_SUFX}:public

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Dashboard and graph editor for Graphite, InfluxDB & OpenTSDB

LICENSE=	APACHE20

BUILD_DEPENDS=	${LOCALBASE}/bin/go:lang/go

ONLY_FOR_ARCHS=	i386 amd64

USE_RC_SUBR=	grafana4

USES=	compiler

PLIST_SUB=	PORTVERSION_MAJOR="${PORTVERSION:C/([0-9]).*/\1/1}"

USE_GITHUB=	yes

GRAFANA_USER?=	grafana
GRAFANA_GROUP?=	grafana

USERS=		${GRAFANA_USER}
GROUPS=		${GRAFANA_GROUP}

GRAFANAHOMEDIR=		${PREFIX}/share/grafana/
GRAFANADATADIR=		/var/db/${PKGBASE}/
GRAFANALOGDIR=		/var/log/${PKGBASE}/
GRAFANAPIDDIR=		/var/run/${PKGBASE}/
GRAFANAPLUGINDIR=	/var/db/${PKGBASE}/plugins
GRAFANADASHBOARDDIR=	/var/db/${PKGBASE}/dashboards

SUB_FILES=	grafana4 grafana4.conf
SUB_LIST+=	GRAFANA_USER=${GRAFANA_USER} \
		GRAFANA_GROUP=${GRAFANA_GROUP} \
		GRAFANADATADIR=${GRAFANADATADIR} \
		GRAFANALOGDIR=${GRAFANALOGDIR} \
		GRAFANAPIDDIR=${GRAFANAPIDDIR} \
		GRAFANAHOMEDIR=${GRAFANAHOMEDIR} \
		GRAFANAPLUGINDIR=${GRAFANAPLUGINDIR} \
		GRAFANADASHBOARDDIR=${GRAFANADASHBOARDDIR}

PLIST_SUB+=	GRAFANAHOMEDIR=${GRAFANAHOMEDIR}

post-extract:
	@${MV} ${WRKSRC}/vendor/ ${WRKSRC}/src/
	@${MKDIR} ${WRKSRC}/src/github.com/grafana/grafana
.for src in CHANGELOG.md Gruntfile.js LICENSE.md Makefile NOTICE.md README.md \
	bower.json build.go circle.yml conf docker docs emails examples \
	karma.conf.js latest.json package.json packaging pkg scripts tasks \
	tests tsconfig.json tslint.json yarn.lock
	@${MV} ${WRKSRC}/${src} \
		${WRKSRC}/src/github.com/grafana/grafana
.endfor
	${RM} -r ${WRKSRC}/src/github.com/grafana/grafana/public
	${MV} ${WRKDIR}/grafana-${PORTVERSION}/public ${WRKSRC}/src/github.com/grafana/grafana/public

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
	${INSTALL_DATA} ${WRKDIR}/grafana4.conf ${STAGEDIR}${PREFIX}/etc/grafana4.conf.sample

.include <bsd.port.pre.mk>

.if ${COMPILER_TYPE} == clang
BUILD_ENV=	CC=clang
.endif

.include <bsd.port.post.mk>
