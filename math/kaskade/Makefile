# New ports collection makefile for:	Kaskade
# Version required:	3.1.1
# Date created:		19 Sept. 1997
# Whom:			Pedro Giffuni
#
# $Id: Makefile,v 1.5 1998/09/27 08:12:54 steve Exp $
#

DISTNAME=	3.1.1
PKGNAME=	kaskade-3.1.1
CATEGORIES=	cad
MASTER_SITES=	ftp://elib.zib-berlin.de/pub/kaskade/3.x/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	giffunip@asme.org

DIST_SUBDIR=	kaskade
WRKSRC=         ${WRKDIR}/3.1
MAKEFILE=	makefile
ALL_TARGET=	k6
USE_X_PREFIX=	yes

do-install:
	$(INSTALL_PROGRAM) $(WRKSRC)/k6 $(PREFIX)/bin

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/examples/kaskade
	${INSTALL_DATA} ${WRKSRC}/*.cmd ${PREFIX}/share/examples/kaskade
	${INSTALL_DATA} ${WRKSRC}/*.geo ${PREFIX}/share/examples/kaskade
	${INSTALL_DATA} ${WRKSRC}/*.mat ${PREFIX}/share/examples/kaskade
.endif

.include <bsd.port.mk>
