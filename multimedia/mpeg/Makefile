# New ports collection makefile for:	mpeg
# Date created:		Sa  01 May 1999 15:00:00 MET
# Whom:			Tobias Reifenberger <treif@mayn.de>
#
# $FreeBSD$
#

PORTNAME=	mpeg
PORTVERSION=	1.2.2
CATEGORIES=	multimedia
MASTER_SITES=	ftp://ftp.uni-koeln.de/graph/mpeg/ \
		ftp://ftp.mni.mcgill.ca/pub/mpeg/ \
		ftp://ftp.u-aizu.ac.jp/pub/graphics/image/mpeg/mni.mcgill.ca/
DISTNAME=	MPEGv${PORTVERSION}

MAINTAINER=	treif@mayn.de
COMMENT=	PVRG's MPEG video stream encoder

WRKSRC=		${WRKDIR}/mpegdir
MAN1=		mpeg.1

pre-build:
	@-${MV} ${WRKSRC}/makefile ${WRKSRC}/Makefile
	cd ${WRKSRC} && lex -lt lexer.l >lexer.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mpeg ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/mpeg.1 ${PREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/mpeg
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/mpeg/README
	${INSTALL_DATA} ${WRKSRC}/doc.ps ${PREFIX}/share/doc/mpeg/doc.ps
.endif

.include <bsd.port.mk>
