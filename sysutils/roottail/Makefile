# New ports collection makefile for:	roottail
# Version required:		0.0.4b
# Date created:			30 September 1999
# Whom:				Chris D. Faulhaber <jedgar@fxp.org>
#
# $FreeBSD$
#

DISTNAME=	rt-0.0.4B
PKGNAME=	roottail-0.0.4b
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.hypertek.net/misc/ \
		http://www.fxp.org/~jedgar/
EXTRACT_SUFX=	.tgz

MAINTAINER=	jedgar@fxp.org

MAN1=		rt.1
USE_IMAKE=	yes
MANCOMPRESSED=	no

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rt ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/rt.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
