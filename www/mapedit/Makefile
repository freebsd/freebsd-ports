# New ports collection makefile for:	mapedit
# Version required:	2.24
# Date created:		Fr   4 Apr 1997 17:45:31 MET DST
# Whom:			Andreas Klemm <andreas@klemm.gtn.com>
#
# $Id: Makefile,v 1.7 1997/10/04 14:53:06 andreas Exp $
#

DISTNAME=	mapedit2.24
PKGNAME=	mapedit-2.24
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.boutell.com/pub/boutell/mapedit/
EXTRACT_SUFX=	.freebsd.tar.Z

MAINTAINER=	andreas@FreeBSD.ORG

USE_X11=		yes
NO_BUILD=		yes
DOCDIR=		${PREFIX}/lib/X11/mapedit

pre-install:
	@cat ${WRKSRC}/README.TXT
	@echo ""

do-install:
	${MKDIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README.TXT ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/help.html ${DOCDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/mapedit ${PREFIX}/bin

.include <bsd.port.mk>
