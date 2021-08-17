PORTNAME=	libxdf
DISTVERSIONPREFIX=	v
DISTVERSION=	0.99.6-2
DISTVERSIONSUFFIX=	-g1ee26a6
CATEGORIES=	misc

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ library for loading XDF files

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libpugixml.so:textproc/pugixml

USES=		cmake
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	xdf-modules

CMAKE_ON=	BUILD_SHARED_LIBS

.include <bsd.port.mk>
