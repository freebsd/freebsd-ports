# New ports collection makefile for:	bbjd
# Version required:	1.01
# Date created:		3 February 1999
# Whom:			Dima Sivachenko
#
# $Id: $
#

DISTNAME=	bbjd-1.01
CATEGORIES=	misc math
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	games/strategy

MAINTAINER=	dima@chg.ru

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
		@ ${CAT} ${PKGDIR}/MESSAGE

.include <bsd.port.mk>
