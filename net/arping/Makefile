# New ports collection makefile for:	arping
# Date Created:				1 Oct 2000
# Whom:					Roman Shterenzon <roman@xpert.com>
#
# $FreeBSD$
#

PORTNAME=	arping
PORTVERSION=	2.05
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.habets.pp.se/pub/synscan/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	ARP level "ping" utility

BUILD_DEPENDS=	libnet*<=1.1.0,1:${PORTSDIR}/net/libnet10

LDFLAGS+=	-lpcap

MAN8=		arping.8
PLIST_FILES=	sbin/arping

do-build:
	cd ${WRKSRC} &&  \
	${CC} ${CFLAGS} -I${LOCALBASE}/include -L${LOCALBASE}/lib \
	-DUSE_NETIF=1  -DFREEBSD=1 -c `libnet-config --defines` \
	`libnet-config --cflags` ${PORTNAME}.c && \
	${CC} ${CFLAGS} -I${LOCALBASE}/include -L${LOCALBASE}/lib \
	-DUSE_NETIF=1 -DFREEBSD=1 -o ${PORTNAME} ${PORTNAME}.o \
	`libnet-config --libs` ${LDFLAGS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/arping ${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/arping.8 ${PREFIX}/man/man8

.include <bsd.port.mk>
