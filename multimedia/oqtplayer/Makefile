# New ports collection makefile for:	oqtplayer
# Date created:				Mon Sep 24 16:26:33 BRT 2001
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	OQTPlayer
PORTVERSION=	0.5
PORTREVISION=	3
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	openquicktime
DISTNAME=	${PORTNAME:L}-${PORTVERSION}-src
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A very very small, not functionnal, video OpenQuicktime (TM) player

LIB_DEPENDS=	openquicktime.0:${PORTSDIR}/multimedia/openquicktime

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_SDL=	sdl
MAKE_ARGS=	CFLAGS="${CFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

PLIST_FILES=	bin/oqtplayer

.if !defined(NOPORTDOCS)
PORTDOCS=	readme
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|gcc -g|${CC}|g ; \
		 s|sdl-config|${SDL_CONFIG}|g' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/oqtplayer ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/readme ${DOCSDIR}
.endif

.include <bsd.port.mk>
