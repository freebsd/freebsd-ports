# Created by: "Philippe Charnier" <charnier@lirmm.fr>
# $FreeBSD$

PORTNAME=	mpeg2play
PORTVERSION=	1.1b
PORTREVISION=	4
CATEGORIES=	multimedia
MASTER_SITES=	ftp://ftp.funet.fi/pub/graphics/packages/mpeg/mpeg2play/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Program to play mpeg-2 movies on X displays

USES=		imake
USE_XORG=	x11 xext xp xt
USE_MOTIF=	yes
ALL_TARGET=	mpeg2play

.include <bsd.port.options.mk>

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mpeg2play ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/Mpeg2play ${PREFIX}/lib/X11/app-defaults
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}/README
.endif

.include <bsd.port.mk>
