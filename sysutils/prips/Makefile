# New ports collection makefile for:	prips
# Version required:	0.9.2
# Date created:		29 October 1999
# Whom:			Jeremy Shaffner <jeremy@external.org>
#
# $FreeBSD$
#

DISTNAME=	prips-0.9.2-src
PKGNAME=	prips-0.9.2
CATEGORIES=	sysutils
MASTER_SITES=	http://www.interloper.net/~dan/software/dist/prips/

MAINTAINER=	jeremy@external.org

WRKSRC=		${WRKDIR}/prips

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/prips ${PREFIX}/bin

.include <bsd.port.mk>
