# New ports collection makefile for:	l0pht-query
# Version required:     1.1
# Date created:		11 Jan 1999
# Whom:			Dom Mitchell <dom@myrddin.demon.co.uk>
#
# $FreeBSD$
#

DISTNAME=	l0pht-watch
PKGNAME=	l0pht-watch-1.1
CATEGORIES=	security
MASTER_SITES=   http://www.l0pht.com/advisories/

MAINTAINER=     dom@myrddin.demon.co.uk

WRKSRC=		${WRKDIR}/temp-watch

ALL_TARGET=	OpenBSD

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/temp-watch ${PREFIX}/bin

.include <bsd.port.mk>
