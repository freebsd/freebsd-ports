PORTNAME=	pugixml
DISTVERSION=	1.11.4
CATEGORIES=	textproc
MASTER_SITES=	https://github.com/zeux/pugixml/releases/download/v${DISTVERSION}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Light-weight, simple and fast XML parser for C++ with XPath support

LICENSE=	MIT

USES=		cmake compiler:c++11-lang
USE_LDCONFIG=	yes

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_OFF=	BUILD_TESTS USE_VERSIONED_LIBDIR

.include <bsd.port.mk>
