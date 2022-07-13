# Created by: Stefan Lambrev <cheffo@freebsd-bg.org>

PORTNAME=	telegraf
DISTVERSIONPREFIX=v
DISTVERSION=	1.23.0
PORTREVISION=	1
CATEGORIES=	net-mgmt

MAINTAINER=	girgen@FreeBSD.org
COMMENT=	Time-series data collection

LICENSE=	MIT

ONLY_FOR_ARCHS=	aarch64 amd64 armv6 armv7 i386

USES=		go:modules

USE_RC_SUBR=	telegraf

GO_MODULE=	github.com/influxdata/telegraf
GO_BUILDFLAGS=	-ldflags "-X main.goos=freebsd -X main.goarch=${ARCH} -X main.version=${DISTVERSION}"
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

post-install:
	${MKDIR} ${STAGEDIR}${TELEGRAF_LOGDIR}
	${INSTALL_DATA} \
		${WRKSRC}/${GH_SUBDIR}/etc/${PORTNAME}.conf  \
		${STAGEDIR}${PREFIX}/etc/${PORTNAME}.conf.sample

.include <bsd.port.mk>
