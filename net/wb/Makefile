# New ports collection makefile for:	wb
# Date created:		2 Novermber 1996
# Whom:			fenner
#
# $FreeBSD$
#

PORTNAME=	wb
PORTVERSION=	1.59
PORTREVISION=	4
CATEGORIES=	net mbone
MASTER_SITES=	ftp://ftp.ee.lbl.gov/conferencing/wb/
DISTFILES=	i386-wb-1.59.tar.Z

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A shared drawing (whiteboard) tool using multicast

NO_WRKSUBDIR=	yes
NO_BUILD=	yes
STRIP=

# ghostscript, ghostscript3, ghostscript4 or ghostscript5 will all do.
USE_GHOSTSCRIPT_RUN=	yes

PLIST_FILES=	bin/wb
PORTDOCS=	README CHANGES NOTES lblwb.ps

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wb ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/CHANGES ${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/NOTES ${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/lblwb.ps ${DOCSDIR}/
.endif

.include <bsd.port.mk>
