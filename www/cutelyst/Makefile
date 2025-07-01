PORTNAME=	cutelyst
DISTVERSIONPREFIX=	v
DISTVERSION=	4.7.0
CATEGORIES=	www

MAINTAINER=	adridg@FreeBSD.org
COMMENT=	C++/Qt web framework
WWW=		https://cutelyst.org

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libepoll-shim.so:devel/libepoll-shim \
		libCuteleeQt6Templates.so:devel/cutelee

USES=		cmake compiler:c++20-lang localbase qt:6
USE_CXXSTD=	c++20
USE_GITHUB=	yes
USE_LDCONFIG=	yes
USE_QT=		tools:build translations:build \
		base

CMAKE_ON=	PLUGIN_CSRFPROTECTION \
		PLUGIN_STATICCOMPRESSED \
		PLUGIN_VIEW_CUTELEE
CMAKE_OFF=	BUILD_ALL BUILD_TESTS
CMAKE_ARGS=	-DMANDIR:PATH=share/man \
		-DCMAKE_DISABLE_FIND_PACKAGE_Doxygen=TRUE

PLIST_SUB=	SOVER=${DISTVERSION}

.include <bsd.port.mk>
