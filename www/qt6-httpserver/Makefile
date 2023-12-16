PORTNAME=	httpserver
DISTVERSION=	${QT6_VERSION}
CATEGORIES=	www
PKGNAMEPREFIX=	qt6-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Lightweight HTTP Server

BUILD_DEPENDS=	vulkan-headers>0:graphics/vulkan-headers

USES=		cmake compiler:c++17-lang pkgconfig qt-dist:6
USE_QT=		base websockets

.include <bsd.port.mk>
