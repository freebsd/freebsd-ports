# New ports collection makefile for:	oqtplayer
# Date created:				Mon Sep 24 16:26:33 BRT 2001
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	OQTPlayer
PORTVERSION=	0.5
PORTREVISION=	2
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	openquicktime
DISTNAME=	${PORTNAME:L}-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	A very very small, not functionnal, video OpenQuicktime (TM) player

LIB_DEPENDS=    openquicktime.0:${PORTSDIR}/multimedia/openquicktime

USE_SDL=	sdl
MAKE_ENV=	SDL_CONFIG=${SDL_CONFIG}
WRKSRC=	${WRKDIR}/${PORTNAME}-${PORTVERSION}

CFLAGS+=	-I${LOCALBASE}/include

do-install:
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/readme ${DOCSDIR}
.endif
	@${INSTALL_PROGRAM} ${WRKSRC}/oqtplayer ${PREFIX}/bin

.include <bsd.port.mk>
