# New ports collection makefile for: arprelease
# Date created:		02 Aug 2001
# Whom:			nbm
#
# $FreeBSD$
#

PORTNAME=	arprelease
PORTVERSION=	1.2
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Libnet tool to flush arp cache entries from devices (eg. routers)

BUILD_DEPENDS=	${LIBNET_CONFIG}:${PORTSDIR}/net/libnet

WRKSRC=		${WRKDIR}/${PORTNAME}

PLIST_FILES=	bin/arprelease

LIBNET_CONFIG?=	${LOCALBASE}/bin/libnet11-config

do-build:
	(cd ${WRKSRC} && \
		${CC} ${CFLAGS} `${LIBNET_CONFIG} --defines` \
		`${LIBNET_CONFIG} --cflags` -o arprelease arprelease.c \
		`${LIBNET_CONFIG} --libs`)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/arprelease ${PREFIX}/bin

.include <bsd.port.mk>
