PORTNAME=	multimedia
PORTVERSION=	${QT6_VERSION}
CATEGORIES=	multimedia
PKGNAMEPREFIX=	qt6-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt audio, video, radio and camera support module
WWW=		https://qt.io

BUILD_DEPENDS=	vulkan-headers>0:graphics/vulkan-headers
LIB_DEPENDS=	libxkbcommon.so:x11/libxkbcommon

USES=		cmake compiler:c++11-lang gl gnome gstreamer:1 localbase:ldflags \
		pkgconfig qt-dist:6
USE_GL=		gl opengl
USE_GNOME=	glib20
USE_GSTREAMER=	bad gl good ugly
USE_QT=		base declarative shadertools svg

CXXFLAGS_powerpc64=	-mvsx
CFLAGS_powerpc=	-DPFFFT_SIMD_DISABLE

.include <bsd.port.mk>
