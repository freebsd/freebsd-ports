# New ports collection makefile for:	xicq
# Version required:			23 June 1998
# Date created:				29 June 1998
# Whom:					scrappy
#
# $Id: Makefile,v 1.1.1.1 1998/06/29 18:39:26 scrappy Exp $
#

DISTNAME=	xicq-062398-snapshot
PKGNAME=	xicq-062398
CATEGORIES=	net
MASTER_SITES=	http://www.xtrophy.dk/xicq/

MAINTAINER=	scrappy@freebsd.org

WRKSRC=		${WRKDIR}/xicq-062398-snapshot

USE_GMAKE=	yes

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/bin/xicq ${PREFIX}/bin
		${MKDIR} ${PREFIX}/share/examples/xicq
.for file in contact config
		${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/examples/xicq
.endfor

.include <bsd.port.mk>
