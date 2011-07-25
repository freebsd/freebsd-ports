# New ports collection makefile for:	mpeg
# Date created:		Sa  01 May 1999 15:00:00 MET
# Whom:			Tobias Reifenberger <treif@mayn.de>
#
# $FreeBSD$
#

PORTNAME=	mpeg
PORTVERSION=	1.2.2
PORTREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	ftp://ftp.u-aizu.ac.jp/pub/graphics/image/mpeg/mni.mcgill.ca/
DISTNAME=	MPEGv${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PVRG's MPEG video stream encoder

WRKSRC=		${WRKDIR}/mpegdir
MAN1=		mpeg.1

post-patch:
	@-${MV} ${WRKSRC}/makefile ${WRKSRC}/Makefile
	${REINPLACE_CMD} -e 's/cc/${CC}/g' ${WRKSRC}/Makefile

pre-build:
	cd ${WRKSRC} && lex -lt lexer.l >lexer.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mpeg ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/mpeg.1 ${PREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc.ps ${DOCSDIR}
.endif

.include <bsd.port.mk>
