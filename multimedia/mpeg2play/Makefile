# New ports collection makefile for:	mpeg2play
# Version required:	1.1b
# Date created:		June 21, 1996
# Whom:			"Philippe Charnier" <charnier@lirmm.fr>
#
# $FreeBSD$
#

DISTNAME=	mpeg2play-1.1b
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.funet.fi/pub/graphics/packages/mpeg/mpeg2play/
DISTFILES=	mpeg2play-1.1b.tar.gz

MAINTAINER=	charnier@lirmm.fr

USE_X_PREFIX=	yes
USE_IMAKE=	yes
REQUIRES_MOTIF=	yes
ALL_TARGET=	mpeg2play

do-install:
	${INSTALL} ${COPY} ${STRIP} -o ${BINOWN} -g ${BINGRP} -m ${BINMODE} \
		${WRKSRC}/mpeg2play ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/Mpeg2play ${PREFIX}/lib/X11/app-defaults


.include <bsd.port.mk>
