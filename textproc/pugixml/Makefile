# $FreeBSD$

PORTNAME=	pugixml
PORTVERSION=	1.10
CATEGORIES=	textproc
MASTER_SITES=	https://github.com/zeux/pugixml/releases/download/v${PORTVERSION}/

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Light-weight, simple and fast XML parser for C++ with XPath support

LICENSE=	MIT

USES=		cmake compiler:c++11-lang
USE_LDCONFIG=	yes

CMAKE_OFF=	BUILD_TESTS USE_VERSIONED_LIBDIR
CMAKE_ON=	BUILD_SHARED_LIBS

PLIST_SUB=	SOVERSION=${PORTVERSION}

.include <bsd.port.mk>
