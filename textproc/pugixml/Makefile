PORTNAME=	pugixml
DISTVERSION=	1.12.1
CATEGORIES=	textproc
MASTER_SITES=	https://github.com/zeux/pugixml/releases/download/v${DISTVERSION}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Light-weight, simple and fast XML parser for C++ with XPath support

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USES=		cmake compiler:c++11-lang cpe
CPE_VENDOR=	${PORTNAME}_project
USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-1.12

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_OFF=	PUGIXML_BUILD_TESTS PUGIXML_USE_VERSIONED_LIBDIR

.include <bsd.port.mk>
