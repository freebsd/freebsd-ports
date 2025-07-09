PORTNAME=	kapacitor
DISTVERSIONPREFIX=	v
DISTVERSION=	1.5.1
PORTREVISION=	27
CATEGORIES=	net-mgmt

MAINTAINER=	cheffo@freebsd-bg.org
COMMENT=	Time-series data collection
WWW=		https://influxdata.com/time-series-platform/kapacitor/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	amd64 armv6 armv7 i386

USES=		go

USE_RC_SUBR=	kapacitord

USE_GITHUB=	yes

GH_ACCOUNT=	influxdata
GH_SUBDIR=	src/github.com/${GH_ACCOUNT}/${PORTNAME}

GO_BUILDFLAGS+=	-ldflags "-X main.version=${DISTVERSION}"
GO_TARGET=	./cmd/kapacitor \
		./cmd/kapacitord

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

KAPACITORD_DBDIR=	/var/db/${PORTNAME}/
KAPACITORD_LOGDIR=	/var/log/${PORTNAME}/

post-install:
	${MKDIR} ${STAGEDIR}${KAPACITORD_DBDIR} \
	${STAGEDIR}${KAPACITORD_LOGDIR}
	@${SED} -i .bak -e \
		"s|/var/lib/kapacitor|/var/db/kapacitor|g" \
		${WRKSRC}/etc/${PORTNAME}/${PORTNAME}.conf
	${INSTALL_DATA} \
		${WRKSRC}/etc/${PORTNAME}/${PORTNAME}.conf  \
		${STAGEDIR}${PREFIX}/etc/${PORTNAME}.conf.sample

.include <bsd.port.mk>
