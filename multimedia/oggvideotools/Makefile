# Ports collection makefile for:  oggvideotools
# Date created:                   Sat Feb 28, 2010
# Whom:                           Jille Timmermans (jille@quis.cx)
# $FreeBSD$

PORTNAME=	oggvideotools
PORTVERSION=	0.8
PORTREVISION=	2
CATEGORIES=	multimedia
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	oggvideotools/oggvideotools/${DISTNAME}

MAINTAINER=	jille@quis.cx
COMMENT=	A toolbox for manipulating Ogg video files

LIB_DEPENDS=	gd.4:${PORTSDIR}/graphics/gd \
		ogg.7:${PORTSDIR}/audio/libogg \
		theora.0:${PORTSDIR}/multimedia/libtheora \
		vorbis.4:${PORTSDIR}/audio/libvorbis

USE_SDL=	sdl
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS=-I${LOCALBASE}/include
MAKEFILE=	makefile

.for app in oggSplit oggDump oggJoin oggCut oggCat oggLength oggSlideshow oggThumb oggResize oggSilence oggScroll mkThumbs mkSlideshow
PLIST_FILES+=	bin/${app}
.endfor
.for app in oggResize oggSlideshow oggThumb oggSplit oggJoin oggCut oggCat oggSilence
MAN1+=	${app}.1
.endfor

.include <bsd.port.mk>
