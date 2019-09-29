# Created by: "Philippe Charnier" <charnier@lirmm.fr>
# $FreeBSD$

PORTNAME=	mpeg2play
PORTVERSION=	1.1b
PORTREVISION=	5
CATEGORIES=	multimedia
MASTER_SITES=	ftp://ftp.funet.fi/pub/graphics/packages/mpeg/mpeg2play/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Program to play mpeg-2 movies on X displays

USES=		imake motif xorg
USE_XORG=	x11 xext xt
ALL_TARGET=	mpeg2play

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mpeg2play ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/Mpeg2play ${STAGEDIR}${PREFIX}/lib/X11/app-defaults

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
