# New ports collection makefile for:	arping
# Date Created:				1 Oct 2000
# Whom:					Roman Shterenzon <roman@xpert.com>
#
# $FreeBSD$
#

PORTNAME=	arping
PORTVERSION=	1.00
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.habets.pp.se/pub/synscan/ \
		ftp://ftp.cerias.purdue.edu/pub/tools/unix/netutils/arping/

MAINTAINER=	roman@xpert.com

BUILD_DEPENDS=	${LOCALBASE}/lib/libnet.a:${PORTSDIR}/net/libnet

ALL_TARGET=	freebsd
MAN8=		arping.8

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/arping ${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/arping.8 ${PREFIX}/man/man8

.include <bsd.port.mk>
