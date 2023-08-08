PORTNAME=	CTK
DISTVERSION=	2023.07.13
CATEGORIES=	x11-toolkits
PKGNAMESUFFIX=	-widgets

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Widgets and common code for medical imaging, surgical navigation, etc
WWW=		https://www.commontk.org/index.php/Main_Page

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake compiler:c++11-lib qt:5
USE_QT=		concurrent core designer gui multimedia opengl sql widgets xml xmlpatterns \
		buildtools:build uitools:build qmake:build testlib:build # see CMake/ctkMacroSetupQt.cmake
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	commontk

CMAKE_ARGS=	-DCTK_QT_VERSION=5
CMAKE_OFF=	CTK_SUPERBUILD BUILD_TESTING
CMAKE_ON=	CTK_LIB_Widgets

.include <bsd.port.mk>
