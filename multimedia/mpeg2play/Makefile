# New ports collection makefile for:	mpeg2play
# Date created:		June 21, 1996
# Whom:			"Philippe Charnier" <charnier@lirmm.fr>
#
# $FreeBSD$
#

PORTNAME=	mpeg2play
PORTVERSION=	1.1b
PORTREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	ftp://ftp.funet.fi/pub/graphics/packages/mpeg/mpeg2play/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A program to play mpeg-2 movies on X displays

USE_IMAKE=	yes
USE_MOTIF=	yes
ALL_TARGET=	mpeg2play

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mpeg2play ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/Mpeg2play ${PREFIX}/lib/X11/app-defaults
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}/README
.endif

.include <bsd.port.mk>
