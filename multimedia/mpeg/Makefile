# New ports collection makefile for:	mpeg
# Version required:	1.2.2
# Date created:		Sa  01 May 1999 15:00:00 MET
# Whom:			Tobias Reifenberger <treif@mayn.de>
#
# $FreeBSD$
#

DISTNAME=	MPEGv1.2.2
PKGNAME=	mpeg-1.2.2
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.uni-koeln.de/graph/mpeg/ \
		ftp://ftp.mni.mcgill.ca/pub/mpeg/ \
		ftp://ftp.u-aizu.ac.jp/pub/graphics/image/mpeg/mni.mcgill.ca/

MAINTAINER=	treif@mayn.de

WRKSRC=		${WRKDIR}/mpegdir
MAN1=		mpeg.1

pre-build:
	@${MV} ${WRKSRC}/makefile ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mpeg ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/mpeg.1 ${PREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/mpeg
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/mpeg/README
	${INSTALL_DATA} ${WRKSRC}/doc.ps ${PREFIX}/share/doc/mpeg/doc.ps
.endif

.include <bsd.port.mk>
