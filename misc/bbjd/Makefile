# New ports collection makefile for:	bbjd
# Date created:		3 February 1999
# Whom:			Dima Sivachenko
#
# $FreeBSD$
#

PORTNAME=	bbjd
PORTVERSION=	1.01
PORTREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	games/strategy

MAINTAINER=	demon@FreeBSD.org
COMMENT=	Beat the blackjack dealer

USE_GMAKE=	yes
WRKSRC=		${WRKDIR}/bbjd

do-install:
		@ ${INSTALL_PROGRAM} ${WRKSRC}/bbjd ${PREFIX}/bin/
		@ ${INSTALL_PROGRAM} ${WRKSRC}/simbj ${PREFIX}/bin/
		@ ${MKDIR} ${PREFIX}/share/bbjd
		@ ${INSTALL_DATA} ${WRKSRC}/Interactive ${PREFIX}/share/bbjd/
		@ ${INSTALL_DATA} ${WRKSRC}/Simulation ${PREFIX}/share/bbjd/
		@ ${INSTALL_DATA} ${WRKSRC}/Theory ${PREFIX}/share/bbjd/

post-install:
		@ ${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
