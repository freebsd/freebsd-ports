# New ports collection makefile for:	xpns
# Version required:     1.0
# Date created:         6 Apr 97
# Whom:                 Pedro Giffuni
#
# $Id: Makefile,v 1.3 1998/02/20 18:39:56 steve Exp $
#

DISTNAME=	pns_source
PKGNAME=	xpns-1.0
CATEGORIES=	misc cad
MASTER_SITES=	ftp://ftp.informatik.uni-stuttgart.de/pub/petri-nets/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	giffunip@asme.org

USE_X_PREFIX=	yes
NO_WRKSUBDIR=	yes
MAKEFILE=	makefile 
ALL_TARGET=	pns

do-install:
	${MKDIR} ${PREFIX}/lib/xpns
	${INSTALL_PROGRAM} ${WRKSRC}/pns ${PREFIX}/lib/xpns/
	${INSTALL_DATA} ${WRKSRC}/pns.hlp ${PREFIX}/lib/xpns/
	${INSTALL_DATA} ${WRKSRC}/pns.shell ${PREFIX}/lib/xpns/
	${INSTALL_SCRIPT} ${WRKSRC}/xpns ${PREFIX}/bin/xpns

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/xpns
	${CP} ${WRKSRC}/*.net ${PREFIX}/share/doc/xpns/
.endif

.include <bsd.port.mk>
