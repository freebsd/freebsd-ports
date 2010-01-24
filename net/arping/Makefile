# New ports collection makefile for:	arping
# Date Created:				1 Oct 2000
# Whom:					Roman Shterenzon <roman@xpert.com>
#
# $FreeBSD$
#

PORTNAME=	arping
PORTVERSION=	2.08
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.habets.pp.se/pub/synscan/

MAINTAINER=	gavin@FreeBSD.org
COMMENT=	ARP level "ping" utility

BUILD_DEPENDS=	${LIBNET_CONFIG}:${PORTSDIR}/net/libnet

LDFLAGS+=	-lpcap

MAN8=		arping.8
PLIST_FILES=	sbin/arping

LIBNET_CONFIG?=	${LOCALBASE}/bin/libnet11-config

do-build:
	cd ${WRKSRC} &&  \
	${CC} ${CFLAGS} -I${LOCALBASE}/include -L${LOCALBASE}/lib \
	-c `${LIBNET_CONFIG} --defines` \
	`${LIBNET_CONFIG} --cflags` ${PORTNAME}-2/${PORTNAME}.c && \
	${CC} ${CFLAGS} -I${LOCALBASE}/include -L${LOCALBASE}/lib \
	-o ${PORTNAME} ${PORTNAME}.o \
	`${LIBNET_CONFIG} --libs` ${LDFLAGS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/arping ${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/arping.8 ${PREFIX}/man/man8

.include <bsd.port.mk>
