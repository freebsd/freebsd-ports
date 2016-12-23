# Created by: Jille Timmermans (jille@quis.cx)
# $FreeBSD$

PORTNAME=	oggvideotools
PORTVERSION=	0.9
PORTREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${DISTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Toolbox for manipulating Ogg video files

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgd.so:graphics/gd \
		libogg.so:audio/libogg \
		libtheora.so:multimedia/libtheora \
		libvorbis.so:audio/libvorbis

USES=		cmake compiler:c++11-lib localbase:ldflags pkgconfig
USE_CXXSTD=	c++11
USE_SDL=	sdl
USE_LDCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} -e \
		's|-O0.*-fPIC|-fPIC|' ${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
