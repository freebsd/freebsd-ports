# New ports collection makefile for:	arping
# Date Created:				1 Oct 2000
# Whom:					Roman Shterenzon <roman@xpert.com>
#
# $FreeBSD$
#

PORTNAME=	arping
PORTVERSION=	2.05
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.habets.pp.se/pub/synscan/

MAINTAINER=	gavin.atkinson@ury.york.ac.uk
COMMENT=	ARP level "ping" utility

BUILD_DEPENDS=	${LIBNET_CONFIG}:${PORTSDIR}/net/libnet10

LDFLAGS+=	-lpcap

MAN8=		arping.8
PLIST_FILES=	sbin/arping

LIBNET_CONFIG?=	${LOCALBASE}/bin/libnet10-config

do-build:
	cd ${WRKSRC} &&  \
	${CC} ${CFLAGS} -I${LOCALBASE}/include -L${LOCALBASE}/lib \
	-DUSE_NETIF=1  -DFREEBSD=1 -c `${LIBNET_CONFIG} --defines` \
	`${LIBNET_CONFIG} --cflags` ${PORTNAME}.c && \
	${CC} ${CFLAGS} -I${LOCALBASE}/include -L${LOCALBASE}/lib \
	-DUSE_NETIF=1 -DFREEBSD=1 -o ${PORTNAME} ${PORTNAME}.o \
	`${LIBNET_CONFIG} --libs` ${LDFLAGS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/arping ${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/arping.8 ${PREFIX}/man/man8

.include <bsd.port.mk>
