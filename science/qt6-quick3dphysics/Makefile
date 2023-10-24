PORTNAME=	quick3dphysics
DISTVERSION=	${QT6_VERSION}
CATEGORIES=	science
PKGNAMEPREFIX=	qt6-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	High-level API for physics simulation
WWW=		https://qt.io

BUILD_DEPENDS=	vulkan-headers>0:graphics/vulkan-headers
LIB_DEPENDS=	libxkbcommon.so:x11/libxkbcommon

USES=		cmake compiler:c++17-lang gl pkgconfig qt-dist:6
USE_GL=		opengl
USE_LOCALE=	C.UTF-8
USE_QT=		base declarative quick3d shadertools

.include <bsd.port.mk>
