# New ports collection makefile for:	xicq
# Version required:			12 July 1998
# Date created:				29 June 1998
# Whom:					scrappy
#
# $Id: Makefile,v 1.3 1998/08/23 04:18:46 scrappy Exp $
#

DISTNAME=	xicq-071298-snapshot.src
PKGNAME=	xicq-071298
CATEGORIES=	net
MASTER_SITES=	http://www.xtrophy.dk/xicq/

MAINTAINER=	scrappy@freebsd.org

WRKSRC=		${WRKDIR}/xicq-071298

BROKEN=		build

USE_GMAKE=	yes

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/src/xicq/main ${PREFIX}/bin/xicq
		${MKDIR} ${PREFIX}/share/examples/xicq
.for file in contact config
		${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/examples/xicq
.endfor

.include <bsd.port.mk>
