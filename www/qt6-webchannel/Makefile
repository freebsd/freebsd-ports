PORTNAME=	webchannel
DISTVERSION=	${QT6_VERSION}
CATEGORIES=	www
PKGNAMEPREFIX=	qt6-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt 6 library for integration of C++/QML with HTML/js clients

BUILD_DEPENDS=	vulkan-headers>0:graphics/vulkan-headers

USES=		cmake compiler:c++17-lang pkgconfig qt-dist:6
USE_QT=		base declarative

.include <bsd.port.mk>
