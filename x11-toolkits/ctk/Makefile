# $FreeBSD$

PORTNAME=	CTK
DISTVERSION=	2018-10-29
CATEGORIES=	x11-toolkits
PKGNAMESUFFIX=	-widgets

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Widgets and common code for medical imaging, surgical navigation, etc

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake:outsource compiler:c++11-lib qt:5
USE_GITHUB=	yes
GH_ACCOUNT=	commontk
USE_QT=		concurrent core designer gui opengl sql widgets xml xmlpatterns buildtools_build uitools_build qmake_build # see CMake/ctkMacroSetupQt.cmake
USE_LDCONFIG=	yes

CMAKE_ARGS=	-DCTK_QT_VERSION=5
CMAKE_OFF=	CTK_SUPERBUILD BUILD_TESTING
CMAKE_ON=	CTK_LIB_Widgets

.include <bsd.port.mk>
