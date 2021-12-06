PORTNAME=	cutelyst
DISTVERSIONPREFIX=	v
DISTVERSION=	3.2.0
CATEGORIES=	www

MAINTAINER=	adridg@FreeBSD.org
COMMENT=	C++/Qt web framework

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake compiler:c++11-lang localbase qt:5
USE_GITHUB=	yes
USE_LDCONFIG=	yes
USE_QT=		qmake_build buildtools_build linguisttools_build \
		core network sql

# There are more views available and various plugins,
# but we don't expose all of them in the port.
OPTIONS_DEFINE=	GRANTLEE
OPTIONS_DEFAULT=	GRANTLEE
OPTIONS_SUB=	yes

GRANTLEE_DESC=	Allow Grantlee templates
GRANTLEE_USES=	grantlee:5
GRANTLEE_CMAKE_BOOL=	PLUGIN_VIEW_GRANTLEE

CMAKE_ON=	PLUGIN_CSRFPROTECTION \
		PLUGIN_STATICCOMPRESSED
CMAKE_OFF=	BUILD_ALL BUILD_TESTS
CMAKE_ARGS=	-DMANDIR:PATH=share/man \
		-DCMAKE_DISABLE_FIND_PACKAGE_Doxygen=TRUE

PLIST_SUB=	SOVER=${DISTVERSION}

.include <bsd.port.mk>
