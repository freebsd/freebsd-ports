# $FreeBSD$

PORTNAME=	pugixml
PORTVERSION=	1.9
CATEGORIES=	textproc
MASTER_SITES=	https://github.com/zeux/pugixml/releases/download/v${PORTVERSION}/

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Light-weight, simple and fast XML parser for C++ with XPath support

LICENSE=	MIT

USES=		cmake compiler:c++11-lang

CMAKE_OFF=	BUILD_TESTS
CMAKE_ON=	BUILD_SHARED_LIBS BUILD_STATIC_LIBS BUILD_PKGCONFIG

.include <bsd.port.mk>
