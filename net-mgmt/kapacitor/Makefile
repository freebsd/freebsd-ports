# Created by: Stefan Lambrev <cheffo@freebsd-bg.org>
# $FreeBSD$

PORTNAME=	kapacitor
DISTVERSIONPREFIX=	v
DISTVERSION=	1.5.1
CATEGORIES=	net-mgmt

MAINTAINER=	cheffo@freebsd-bg.org
COMMENT=	Time-series data collection

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	amd64 armv6 armv7 i386

BUILD_DEPENDS=	go>=1.6.0:lang/go

USE_RC_SUBR=	kapacitord

USE_GITHUB=	yes

GH_ACCOUNT=	influxdata
GH_SUBDIR=	src/github.com/${GH_ACCOUNT}/${PORTNAME}

SUB_FILES=	kapacitord
SUB_LIST+=	KAPACITORD_USER=${KAPACITORD_USER} \
		KAPACITORD_GROUP=${KAPACITORD_GROUP} \
		KAPACITORD_DBDIR=${KAPACITORD_DBDIR} \
		KAPACITORD_LOGDIR=${KAPACITORD_LOGDIR}
PLIST_SUB=	KAPACITORD_USER=${KAPACITORD_USER} \
		KAPACITORD_GROUP=${KAPACITORD_GROUP} \
		KAPACITORD_DBDIR=${KAPACITORD_DBDIR} \
		KAPACITORD_LOGDIR=${KAPACITORD_LOGDIR}

#Use influxd user as it's aleary present in ports system
KAPACITORD_USER=	influxd
KAPACITORD_GROUP=	influxd

USERS=		${KAPACITORD_USER}
GROUPS=		${KAPACITORD_GROUP}

.include <bsd.port.pre.mk>

.if ${OPSYS} == "FreeBSD" && ((${OSVERSION} >= 1100513 && ${OSVERSION} < 1200000) || \
	${OSVERSION} >= 1200015)
SUB_LIST+=	KAPACITORD_LOGCMD="daemon"
.else
SUB_LIST+=	KAPACITORD_LOGCMD="logger"
.endif

KAPACITORD_DBDIR=	/var/db/${PORTNAME}/
KAPACITORD_LOGDIR=	/var/log/${PORTNAME}/

do-build:
	@cd ${WRKSRC}/src/github.com/influxdata/${PORTNAME} \
		&& ${SETENV} ${MAKE_ENV} GOPATH=${WRKSRC} go install -ldflags "-X main.version=${DISTVERSION}" ./cmd/${PORTNAME} \
		&& ${SETENV} ${MAKE_ENV} GOPATH=${WRKSRC} go install -ldflags "-X main.version=${DISTVERSION}" ./cmd/${PORTNAME}d

do-install:
	${MKDIR} ${STAGEDIR}${KAPACITORD_DBDIR} \
	${STAGEDIR}${KAPACITORD_LOGDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${PORTNAME}d ${STAGEDIR}${PREFIX}/bin/${PORTNAME}d
	@${SED} -i .bak -e \
		"s|/var/lib/kapacitor|/var/db/kapacitor|g" \
		${WRKSRC}/src/github.com/${GH_ACCOUNT}/${GH_PROJECT}/etc/${PORTNAME}/${PORTNAME}.conf
	${INSTALL_DATA} \
		${WRKSRC}/src/github.com/${GH_ACCOUNT}/${GH_PROJECT}/etc/${PORTNAME}/${PORTNAME}.conf  \
		${STAGEDIR}${PREFIX}/etc/${PORTNAME}.conf.sample

.include <bsd.port.post.mk>
