# New ports collection makefile for:	l0pht-query
# Version required:     1.0
# Date created:		11 Jan 1999
# Whom:			Dom Mitchell <dom@myrddin.demon.co.uk>
#
# $Id$
#

DISTNAME=	l0pht-watch
PKGNAME=	l0pht-watch-1.0
CATEGORIES=	security
MASTER_SITES=   http://www.l0pht.com/advisories/

MAINTAINER=     dom@myrddin.demon.co.uk

NO_WRKSUBDIR=	yes

ALL_TARGET=	OpenBSD

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/temp-watch ${PREFIX}/bin

.include <bsd.port.mk>
