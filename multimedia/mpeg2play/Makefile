# New ports collection makefile for:	mpeg2play
# Date created:		June 21, 1996
# Whom:			"Philippe Charnier" <charnier@lirmm.fr>
#
# $FreeBSD$
#

PORTNAME=	mpeg2play
PORTVERSION=	1.1b
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.funet.fi/pub/graphics/packages/mpeg/mpeg2play/

MAINTAINER=	charnier@lirmm.fr

USE_IMAKE=	yes
USE_MOTIF=	yes
ALL_TARGET=	mpeg2play

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mpeg2play ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/Mpeg2play ${PREFIX}/lib/X11/app-defaults

.include <bsd.port.mk>
