# Created by: nbm
# $FreeBSD$

PORTNAME=	arprelease
PORTVERSION=	1.2
PORTREVISION=	3
CATEGORIES=	net
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Libnet tool to flush arp cache entries from devices (eg. routers)

LIB_DEPENDS=	net:${PORTSDIR}/net/libnet

WRKSRC=		${WRKDIR}/${PORTNAME}

PLIST_FILES=	bin/arprelease

LIBNET_CONFIG?=	${LOCALBASE}/bin/libnet11-config

NO_STAGE=	yes
do-build:
	(cd ${WRKSRC} && \
		${CC} ${CFLAGS} `${LIBNET_CONFIG} --defines` \
		`${LIBNET_CONFIG} --cflags` -o arprelease arprelease.c \
		`${LIBNET_CONFIG} --libs`)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/arprelease ${PREFIX}/bin

.include <bsd.port.mk>
