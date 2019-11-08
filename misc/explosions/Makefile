# Created by: Pete Fritchman <petef@databits.net>
# $FreeBSD$

PORTNAME=	explosions
PORTVERSION=	0.2005.07.31
PORTREVISION=	16
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.tuxpaint.org/unix/x/${PORTNAME}/ \
		SF/nemysisfreebsdp/${CATEGORIES}/:icons
DISTNAME=	${PORTNAME}-${PORTVERSION:S/^0.//}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${PORTNAME}.png:icons
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	3D objects flying around resembling explosions with various effects

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING.txt

USES=		gmake perl5 sdl
USE_PERL5=	build
USE_SDL=	sdl image

PORTDOCS=	BUGS.txt CHANGES.txt README.txt
OPTIONS_DEFINE=	DOCS

DESKTOP_ENTRIES="Explosions" "" "${PORTNAME}" \
		"${PORTNAME}" "Game;Graphics;" ""

post-patch:
	@${REINPLACE_CMD} -e 's|CFLAGS=-Wall -O2|CFLAGS+=-Wall|; \
		s|sdl-config|${SDL_CONFIG}|' \
		${WRKSRC}/Makefile
	@${REINPLACE_CMD}  -e 's|spark%d.png|${DATADIR}/spark%d.png|' \
		${WRKSRC}/explosions.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/spark?.png ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${_DISTDIR}/${PORTNAME}.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
