# New ports collection makefile for:    poink
# Date created:         12.04.2002
# Whom:                 janos.mohacsi@bsd.hu
#
# $FreeBSD$
#

PORTNAME=	poink
PORTVERSION=    1.5
CATEGORIES=	net
MASTER_SITES=   ${MASTER_SITE_NETBSD}

MAINTAINER=	ports@freebsd.org

MAN1=	poink.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/poink ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/ping.1 ${PREFIX}/man/man1/poink.1

.include <bsd.port.mk>
