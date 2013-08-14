# Created by: Jille Timmermans (jille@quis.cx)
# $FreeBSD$

PORTNAME=	oggvideotools
PORTVERSION=	0.8a
PORTREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${DISTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Toolbox for manipulating Ogg video files

LICENSE=	GPLv2 # (or later)

LIB_DEPENDS=	gd:${PORTSDIR}/graphics/gd \
		ogg:${PORTSDIR}/audio/libogg \
		theora:${PORTSDIR}/multimedia/libtheora \
		vorbis:${PORTSDIR}/audio/libvorbis

USE_SDL=	sdl
USES=		cmake pkgconfig
USE_LDCONFIG=	yes

LDFLAGS+=	-L${LOCALBASE}/lib

MAN1=		mkThumbs.1 oggCat.1 oggCut.1 oggDump.1 oggJoin.1 \
		oggLength.1 oggSilence.1 oggSlideshow.1 oggSplit.1 \
		oggThumb.1 oggTranscode.1

.include <bsd.port.mk>
