# ex:ts=8
# New ports collection makefile for:	flawfinder
# Date created:			Jul 23, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	flawfinder
PORTVERSION=	0.21
CATEGORIES=	security devel
MASTER_SITES=	http://www.dwheeler.com/flawfinder/

MAINTAINER=	ports@FreeBSD.org

USE_PYTHON=	yes
NO_BUILD=	yes

MAN1=	flawfinder.1

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/flawfinder ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/flawfinder.1 ${MANPREFIX}/man/man1

.include <bsd.port.mk>
