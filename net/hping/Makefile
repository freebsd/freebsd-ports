# New ports collection makefile for:	hping
# Date Created:				5 Oct 2000
# Whom:					Roman Shterenzon <roman@xpert.com>
#
# $FreeBSD$
#

PORTNAME=	hping
PORTVERSION=	2b54
CATEGORIES=	security net
MASTER_SITES=	http://www.kyuzz.org/antirez/hping2-src/
DISTNAME=	hping2-beta54

MAINTAINER=	roman@xpert.com

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--force-libpcap

MAN8=	hping.8

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/hping2 ${PREFIX}/sbin/hping
	${INSTALL_MAN} ${WRKSRC}/docs/hping2.8 ${PREFIX}/man/man8/hping.8

.include <bsd.port.mk>
