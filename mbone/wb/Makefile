# New ports collection makefile for:	wb
# Version required:     1.59
# Date created:		2 Novermber 1996
# Whom:			fenner
#
# $Id: $
#

DISTNAME=       wb-1.59
CATEGORIES+=	mbone
MASTER_SITES=   ftp://ftp.ee.lbl.gov/conferencing/wb/
DISTFILES=      i386-wb-1.59.tar.Z

MAINTAINER=	fenner@FreeBSD.ORG

NO_WRKSUBDIR=	yes
NO_BUILD=	yes
USE_X11=	yes

# XXX ghostscript, ghostscript3 or ghostscript4 will all do.
RUN_DEPENDS=	gs:${PORTSDIR}/print/ghostscript4

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wb ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/wb
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/wb
	${INSTALL_DATA} ${WRKSRC}/CHANGES ${PREFIX}/share/doc/wb
	${INSTALL_DATA} ${WRKSRC}/NOTES ${PREFIX}/share/doc/wb
	${INSTALL_DATA} ${WRKSRC}/lblwb.ps ${PREFIX}/share/doc/wb
.endif

.include <bsd.port.mk>
