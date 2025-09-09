PORTNAME=	telegraf
DISTVERSIONPREFIX=v
DISTVERSION=	1.36.1
CATEGORIES=	net-mgmt

MAINTAINER=	girgen@FreeBSD.org
COMMENT=	Time-series data collection
WWW=		https://influxdata.com/time-series-platform/telegraf/

LICENSE=	MIT

ONLY_FOR_ARCHS=	aarch64 amd64 armv6 armv7

USES=		go:modules

USE_RC_SUBR=	telegraf

GO_MODULE=	github.com/influxdata/telegraf
GO_BUILDFLAGS=	-ldflags "-X github.com/influxdata/telegraf/internal.Version=${DISTVERSION}"
GO_TARGET=	./cmd/telegraf

SUB_FILES=	telegraf
SUB_LIST=	TELEGRAF_USER=${TELEGRAF_USER} \
		TELEGRAF_GROUP=${TELEGRAF_GROUP} \
		TELEGRAF_LOGDIR=${TELEGRAF_LOGDIR}
PLIST_SUB=	TELEGRAF_USER=${TELEGRAF_USER} \
		TELEGRAF_GROUP=${TELEGRAF_GROUP} \
		TELEGRAF_LOGDIR=${TELEGRAF_LOGDIR}

TELEGRAF_USER=	telegraf
TELEGRAF_GROUP=	telegraf

USERS=		${TELEGRAF_USER}
GROUPS=		${TELEGRAF_GROUP}

TELEGRAF_LOGDIR=/var/log/${PORTNAME}

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${PREFIX}|g' ${WRKSRC}/config/config.go

post-install:
	${MKDIR} ${STAGEDIR}${TELEGRAF_LOGDIR}

.include <bsd.port.mk>
