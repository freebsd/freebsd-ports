# Created by: Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
# $FreeBSD$

PORTNAME=	OQTPlayer
PORTVERSION=	0.5
PORTREVISION=	10
CATEGORIES=	multimedia
MASTER_SITES=	SF/openquicktime/OpenQuicktime%20v1/1.0b
DISTNAME=	${PORTNAME:L}-${PORTVERSION}-src
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Small, not functional, video OpenQuicktime (TM) player

LIB_DEPENDS=	openquicktime.0:${PORTSDIR}/multimedia/openquicktime

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_SDL=	sdl
MAKE_ARGS=	CFLAGS="${CFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

PLIST_FILES=	bin/oqtplayer

.if !defined(NOPORTDOCS)
PORTDOCS=	readme
.endif

NO_STAGE=	yes
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
